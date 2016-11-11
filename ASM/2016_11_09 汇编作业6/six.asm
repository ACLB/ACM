;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Copyright 	: SDUT
;Problem	: 四组-第六题
;Member		：李标，路广晨，时明群，司腾，张树炜，张镇，张永平
;Data 		: 2016-10-31
;Description: 检查输入的四位密码与设定的密码是否相同，输入EXIT结束程序
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Function Name 	: DATA SEGMENT
;Description	: 定义数据段
DATA SEGMENT
	CODESET DB '0522'								;设定密码
	ED	DB 	'EXIT'									;退出命令
	MA	DB 	100										;用来储存输入的密码
		DB 	?
		DB	100 DUP(?)
	TS	DB 	0DH,0AH,'Please input the password! If you want to quit the program,please input "EXIT".$'	
													;提示输入密码和退出程序的命令
	WA 	DB 	0DH,0AH,'The password is not legal!','$';提示输入的密码不合法
	WARP	DB 0DH,0AH,'$'							;回车换行
	IST	DB 	0DH,0AH,'CORRECT','$'					;密码输入正确
	ISF	DB 	0DH,0AH,'ERROR','$'						;密码输入错误
	ID 	DB 	0DH,0AH,'Press any key to finish !$'	;提示按任意键结束程序
DATA ENDS

;Function Name 	: STACK SEGMENT
;Description	: 定义堆栈段
STACK SEGMENT STACK
	DB 	100 DUP(?)
STACK ENDS

CODE SEGMENT
	ASSUME DS:DATA,ES:DATA,CS:CODE,SS:STACK

;Function Name  : OUTPUT 和 INPUT
;Description	: 输出字符串和输出字符
OUTPUT MACRO SR
	LEA DX, SR										;获取SR存储器偏移地址
	MOV AH, 09H										;09功能号，显示字符串，首地址为DS:DX
	INT 21H	
	ENDM
INPUT MACRO SR
	LEA DX, SR
	MOV AH, 0AH										;0A功能号，输入字符串至内存缓存区，首地址为DS:DX
	INT 21H
	ENDM
MAIN PROC FAR
	MOV AX, DATA									;ASSUME确定段寄存器和逻辑段之间的关系，但是
	MOV DS, AX										;没有赋初值，通过MOV给DS,ES赋初值
	MOV ES, AX
	TESTT:
		OUTPUT TS									;提示输入密码
		OUTPUT WARP							
		INPUT MA									;输入字符串
		CALL ISEND									;判断输入的字符串是不是结束命令
		CMP AX ,1
		JZ FIN										;如果是结束命令则结束程序
		CALL CHECK									;判断输入的字符是不是合法，即是不是4位和是不是由数字组成
		CMP AX,0
		JZ TESTT									;如果不合法则继续输入
		CALL ISTRUE									;判断输入的合法密码是不是正确
		CMP AX,1
		JZ TESTT									;如果密码不正确则继续输入
	FIN:											;结束程序
		OUTPUT ID
		CALL FINISH
	RET
MAIN ENDP

;Function Name	: FINISH
;Description	: 按任意键结束 
FINISH PROC
	MOV AH,0
	INT 16H											;16H是键盘服务，00表示从键盘读字符
	MOV AH,4CH
	INT 21H											;带返回码结束程序
	RET
FINISH ENDP

;Function Name	: ISEND
;Description	: 判断输入的字符是不是结束标志字符串
;Return			: 如果是结束字符串AX =1,否则AX = 0
ISEND PROC
	LEA SI, MA+2									;输入字符的首地址
	LEA DI, ED										;定义结束命令的首地址
	MOV CL, MA+1
	XOR CH, CH
	CMP CX, 04H										;判断长度是不是合法
	JNZ ISNOT
	CLD												;清方向标志位
	REPE CMPSB										;字符串比较
	JCXZ ISEXIT										;如果CX = 0 ,说明输入的是结束命令
	ISNOT:
		MOV AX,0
		RET
	ISEXIT:
		MOV AX ,1
		RET
ISEND ENDP

;Function Name	: ISTRUE
;Description	: 判断输入的字符和规定的密码是否相同
;Return			: 如果相同AX =1,并输出CORRECT,结束程序，否则AX = 0,输出ERROR,继续请求输入
ISTRUE PROC
	LEA SI, MA+2									;输入字符的首地址
	LEA DI, CODESET									;定义密码的首地址
	MOV CX, 04H
	CLD												;清方向标志位
	REPE CMPSB										;字符串比较
	JCXZ YES										;如果CX = 0 ,说明输入的是密码
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

;Function Name	: CHECK
;Description	: 判断输入的字符长度和组成是不是合法
;Return			: 如果合法AX =1，否则AX = 0,输出The string is not legal!,继续请求输入
CHECK PROC 
	LEA SI,MA+2
	MOV CL,[MA+1]
	XOR CH,CH
	CMP CX,4										;判断输入的字符串是不是4个
	JNZ EXIT
	NEXT:
		MOV AL,[SI]
		CMP AL,'0'									;输入的字符是不是小余'0'
		JL EXIT
		CMP AL,'9'									;输入的字符是不是大余'9'
		JG EXIT
		INC SI
		DEC CX
		JNZ NEXT									;如果合法，则继续判断下一个字符
		MOV AX,1
		RET
	EXIT :											;输入不合法，则AX = 0
		OUTPUT WA								
		MOV AX,0
		RET
	RET
CHECK ENDP
CODE ENDS
	END MAIN