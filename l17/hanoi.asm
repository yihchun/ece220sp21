.ORIG x3000

LEA R6, STACK_END
JSR HANOI
HALT


HANOI
	ADD R6, R6, #-4
	STR R5, R6, #1
	ADD R5, R6, #0
	STR R7, R5, #2

	LDR R0, R5, #7
	BRz HANOI_TEARDOWN

	ADD R6, R6, #-4
	ADD R0, R0, #-1
	STR R0, R6, #3
	LDR R0, R5, #6
	STR R0, R6, #2
	LDR R0, R5, #4
	STR R0, R6, #1
	LDR R0, R5, #5
	STR R0, R6, #0
	JSR HANOI
	ADD R6, R6, #5

	LD R1, ZERO
	LDR R0, R5, #7
	ADD R0, R0, R1
	OUT
	LDR R0, R5, #6
	OUT
	LEA R0, ARROW
	PUTS
	LDR R0, R5, #4
	OUT
	LD R0, NEWLINE
	OUT

	ADD R6, R6, #-4
	LDR R0, R5, #7
	ADD R0, R0, #-1
	STR R0, R6, #3
	LDR R0, R5, #5
	STR R0, R6, #2
	LDR R0, R5, #6
	STR R0, R6, #1
	LDR R0, R5, #4
	STR R0, R6, #0
	JSR HANOI
	ADD R6, R6, #5

HANOI_TEARDOWN
	LDR R7, R5, #2
	LDR R5, R5, #1
	ADD R6, R6, #3
	RET
	

ZERO .FILL x30
ARROW .STRINGZ " => "
NEWLINE .FILL xA

STACK_START .BLKW #100
STACK_END .FILL x43   ; R5+4
.FILL x42             ; 5
.FILL x41             ; 6
.FILL #3              ; 7

.END