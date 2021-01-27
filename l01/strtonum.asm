.ORIG x3000

LEA R0, NUM
LD R3, NEGZERO
AND R1, R1, #0 ; init R1 <- 0

LOOPTOP
; check if next character is nul
LDR R2, R0, #0
BRz DONE

; multiply R1 by 10
ADD R1, R1, R1 ; R1 is 2* old R1
ADD R4, R1, R1 ; R4 is 4* old R1
ADD R4, R4, R4 ; R4 is 8* old R1
ADD R1, R1, R4 ; R1 is 10* old R1

ADD R2, R2, R3 ; subtract '0'
ADD R1, R1, R2 ; add to accumulator

; increment pointer
ADD R0, R0, #1
BRnzp LOOPTOP

DONE
HALT


NUM .STRINGZ "123"
NEGZERO .FILL xFFD0

.END
