;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Copyright : SDUT
;Author : JueChen
;Data   : 2016-11-06
;Description : 比较两个个位数的大小，输出比较的结果
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DATA SEGMENT
	HH 	DB	0DH,0AH,'$'
	TS	DB	'Please input two num!$' ;提示输入数字
	WA 	DB  0DH,0AH,'The input is not legal!$'	;提示输入部分不合法
	GR	DB 	0DH,0AH,'GREAT$'	;第一个数大于第二个数
	LESS	DB 	0DH,0AH,'LESS$'	;第一个数小于第二个数
	EQE	DB	0DH,0AH,'EQUAL$'	;第一个数等于第二个数
	NUM1	DB 	100				;第一个数的存储空间
			DB 	?
			DB 	100 DUP(?)
			
	NUM2	DB 	100				;第二个数的存储空间
			DB  ?
			DB	100 DUP(?)
DATA ENDS
STACK SEGMENT STACK
	DB	100	DUP(?)
STACK ENDS
CODE SEGMENT
	ASSUME CS:CODE,DS:DATA,SS:STACK
;Function Name  : OUTPUTSR , INPUTSR
;Description    : 输出和输入字符串
OUTPUTSR MACRO SR
	LEA DX, SR
	MOV AH, 09H
	INT 21H
	ENDM
INPUTSR MACRO SR
	LEA DX, SR
	MOV AH, 0AH
	INT 21H
	ENDM
;Function Name  : FINISH
;Description    : 输出比较的结果，并按任意键结束
FINISH MACRO SR
	OUTPUTSR SR
	OUTPUTSR HH
	MOV AH, 0H
	INT 16H
	MOV AH, 4CH
	INT 21H
	ENDM 
MAIN PROC FAR
	MOV AX, DATA
	MOV DS, AX
	LOOPINPUT:
		OUTPUTSR TS		
		OUTPUTSR HH
		INPUTSR NUM1
		OUTPUTSR HH
		INPUTSR NUM2
		CALL CHECK 
		CMP AX, 1
		JNZ ISTRUE			;输入合法则输出判断的结果
		OUTPUTSR WA
		OUTPUTSR HH
		JMP LOOPINPUT		;输入不合法则继续输入
	ISTRUE:
		CMP DL,DH
		JZ ISEQ
		JG ISGR
		JL ISLE
		ISEQ:
			FINISH EQE
			RET
		ISLE:
			FINISH LESS
			RET
		ISGR:
			FINISH GR
			RET
	RET
MAIN ENDP
;Function Name  : CHECK
;Description    : 判断输入的数据是不是合法的数据
;Return 		: 合法：AX = 1，DL = NUM1，DH = NUM2,否则：AX = 0
CHECK PROC
	MOV AX, 0
	MOV CX, 0
	MOV DL, NUM1+1
	CMP DL, 1
	JNZ LEGAL
	MOV DL, NUM2+1
	CMP DL, 1
	JNZ LEGAL
	MOV DL, NUM1+2
	MOV DH, NUM2+2
	RET
	LEGAL:
		MOV AX,1
	RET
CHECK ENDP
CODE ENDS
	END MAIN