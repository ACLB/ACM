DATA SEGMENT
	CODESET DB 	'0522'
	ED		DB 	'EXIT'
	MA		DB 	10
			DB 	?
			DB	10 DUP(?)
	TS		DB 	0DH,0AH,'Please input the password!$'
	WA 		DB 	0DH,0AH,'The data is not legal!','$'
	WARP	DB  0DH,0AH,'$'
	IST		DB 	0DH,0AH,'CORRECT','$'
	ISF		DB 	0DH,0AH,'ERROR','$'
DATA ENDS
CODE SEGMENT
		ASSUME DS:DATA,CS:CODE
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
	MOV AX, DATAe
	MOV DS, AX
	TESTT:
		OUTPUT TS
		OUTPUT WARP
		INPUT MA
		CALL CHECK 
		CMP AX,1
		JZ TESTT
		CALL ISTRUE
		CMP AX,1
		JZ TESTT
	CALL FINISH
	RET
MAIN ENDP
FINISH PROC;程序按任意键结束过程
	MOV AH,0
	INT 16H
	MOV AH,4CH
	INT 21H
	RET 
FINISH ENDP
ISTRUE PROC 
	LEA SI, MA+2
	LEA DI, CODESET
	MOV CX, 04H
	NEXT1:
		MOV AX,[DI]
		MOV DX,[SI]
		CMP AX,DX
		JNZ NO
		DEC CX
		INC SI
		INC DI
		JNZ NEXT1
	JCXZ YES
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
		JZ NEXT
		MOV AX,0
		RET
	EXIT :
		OUTPUT WA
		MOV AX,1
		RET
	RET
CHECK ENDP
CODE ENDS
	END MAIN
