;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Copyright : SDUT
;Author : JueChen
;Data   : 2016-10-31
;Description : 检查输入的四位密码与设定的密码是否相同，输入EXIT结束程序
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Function Name  : DATA SEGMENT
;Description    : 定义要用的提示字符串和申请储存输入的空间
DATA SEGMENT
    CODESET DB '0522'
    ED  DB  'EXIT'
    MA  DB  10
        DB  ?
        DB  10 DUP(?)
    TS  DB  0DH,0AH,'Please input the password!$'
    WA  DB  0DH,0AH,'The string is not legal!','$'
    WARP    DB 0DH,0AH,'$'
    IST DB  0DH,0AH,'CORRECT','$'
    ISF DB  0DH,0AH,'ERROR','$'
    ID  DB  0DH,0AH,'Press any key to finish !$'
DATA ENDS


CODE SEGMENT
    ASSUME DS:DATA,CS:CODE

;Function Name  : OUTPUT 和 INPUT
;Description    : 输出字符串和输出字符
OUTPUT MACRO SR
    LEA DX, SR
    MOV AH, 09H
    INT 21H
    ENDM
INPUT MACRO SR
    LEA DX, SR
    MOV AH, 0AH
    INT 21H
    ENDM
MAIN PROC FAR
    MOV AX, DATA
    MOV DS, AX
    TESTT:
        OUTPUT TS
        OUTPUT WARP
        INPUT MA
        CALL ISEND
        CMP AX ,1
        JZ FIN
        CALL CHECK
        CMP AX,0
        JZ TESTT
        CALL ISTRUE
        CMP AX,1
        JZ TESTT
        OUTPUT ID
        CALL FINISH
        RET
    FIN:
        OUTPUT ID
        CALL FINISH
    RET
MAIN ENDP
;Function Name  : FINISH
;Description    : 按任意键结束 
FINISH PROC
    MOV AH,0
    INT 16H
    MOV AH,4CH
    INT 21H
    RET
FINISH ENDP

;Function Name  : ISEND
;Description    : 判断输入的字符是不是结束标志字符串
;Return         : 如果是结束字符串AX =1,否则AX = 0
ISEND PROC
    LEA SI, MA+2
    LEA DI, ED
    MOV CX, 04H
    NEXTEND:
        MOV AL,[DI]
        MOV AH,[SI]
        CMP AL,AH
        JNZ ISNOT
        INC SI
        INC DI
        DEC CX
        JNZ NEXTEND
    JZ ISEXIT
    ISEXIT:
        MOV AX ,1
        RET
    ISNOT:
        MOV AX,0
        RET
ISEND ENDP
;Function Name  : ISTRUE
;Description    : 判断输入的字符和规定的密码是否相同
;Return         : 如果相同AX =1,并输出CORRECT,结束程序，否则AX = 0,输出ERROR,继续请求输入
ISTRUE PROC
    LEA SI, MA+2
    LEA DI, CODESET
    MOV CX, 04H
    NEXT1:
        MOV AL,[DI]
        MOV AH,[SI]
        CMP AL,AH
        JNZ NO
        INC SI
        INC DI
        DEC CX
        JNZ NEXT1
    JZ YES
    NO:
        OUTPUT ISF
        MOV AX, 1
        RET
    YES:
        OUTPUT IST
        MOV AX, 0
        RET
    RET
ISTRUE ENDP
;Function Name  : CHECK
;Description    : 判断输入的字符长度和组成是不是合法
;Return         : 如果合法AX =1，否则AX = 0,输出The string is not legal!,继续请求输入
CHECK PROC 
    LEA SI,MA+2
    MOV CL,[MA+1]
    XOR CH,CH
    CMP CX,4
    JNZ EXIT
    NEXT:
        MOV AL,[SI]
        CMP AL,'0'
        JL EXIT
        CMP AL,'9'
        JG EXIT
        INC SI
        DEC CX
        JNZ NEXT
        MOV AX,1
        RET
    EXIT :
        OUTPUT WA
        MOV AX,0
        RET
    RET
CHECK ENDP
CODE ENDS
    END MAIN
