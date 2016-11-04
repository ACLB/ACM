;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Copyright : SDUT
;Author : JueChen
;Data   : 2016-11-01
;Description : 输入0-9的个位数字，得到最大值
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DATA 	SEGMENT
	MAXNUM	DB 	100
			DB	?
			DB	100	DUP(?)
	TS		DB	'Please input the num!$'
	WA 		DB	0DH,0AH,'The input is not legal!',0DH,0AH,'$'
	HH		DB 	0DH,0AH,'$'
	MM		DB	0DH,0AH,'The max num is:$' 
DATA	ENDS
CODE	SEGMENT 
	ASSUME DS:DATA,CS:CODE

	;Function Name  : OUTPUT 和 INPUT
;Description    : 输出字符串和输出字符
OUTPUT	MACRO SR
	LEA DX, SR
	MOV AH, 09H
	INT 21H
	ENDM 
INTPUT 	MACRO SR
	LEA DX, SR
	MOV AH, 0AH
	INT 21H
	ENDM
MAX PROC FAR
	MOV AX, DATA
	MOV DS, AX
	NEXT:
		OUTPUT TS
		OUTPUT HH
		INTPUT MAXNUM
		CALL CHECK
		CMP AX, 1
		JNZ NEXT
	OUTPUT MM
	CALL GETMAX
	MOV DL, AL
	MOV AH, 02H
	INT 21H
	OUTPUT HH
	CALL FINISH
	RET
MAX ENDP

;Function Name  : FINISH
;Description    : 按任意键结束 
FINISH PROC
	MOV AH, 0
	INT 16H
	MOV AH,4CH
	INT 21H
	RET
FINISH ENDP
;Function Name	:GETMAX
;Description	:得到最大值，将结果存在AL中
GETMAX	PROC
	LEA SI, MAXNUM+2
	MOV CL, [MAXNUM+1]
	XOR CH, CH
	MOV DL, 0
	GET:
		MOV AL, [SI]
		CMP AL, DL
		JL NMAX
		MOV DL,AL
		NMAX:
			INC SI
			DEC CX
		JNZ GET
	MOV AL,DL
	RET
GETMAX 	ENDP
;Function Name  : CHECK
;Description    : 判断输入的字符组成是不是合法
;Return         : 如果合法AX =1，否则AX = 0,输出The input is not legal!,继续请求输入
CHECK PROC
	LEA SI, MAXNUM+2
	MOV CL, [MAXNUM+1]
	XOR CH, CH
	ISNUM:
		MOV DL, [SI]
		CMP DL, '0'
		JL EXIT
		CMP DL, '9'
		JG EXIT
		INC SI
		DEC CX
		JNZ ISNUM
	MOV AX, 1
	RET
	EXIT:
		OUTPUT WA
		MOV AX ,0
	RET
CHECK ENDP
CODE ENDS
	END MAX