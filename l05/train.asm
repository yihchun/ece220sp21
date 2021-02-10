.ORIG x3000

; initialize R1 and R2
LEA R1, INORD
LEA R2, OUTORD
LEA R6, STACK_BOT

LOOPTOP
  ; R3 <- M[R1], R4 <- M[R2]
  LDR R3, R1, #0
  LDR R4, R2, #0

  ; while M[R2] != 0
  BRz LOOPBOT

  ; if R3 == R4
  NOT R5, R3
  ADD R5, R5, #1
  ADD R5, R4, R5
  BRnp NOTTHROUGH  ; not equal, move to the next case
  ADD R1, R1, #1   ; used 1 car from input
  ADD R2, R2, #1   ; handled 1 car from the output
  LEA R5, COMMANDS ; print a Through
  LDR R0, R5, #0
  OUT
  BRnzp LOOPTOP    ; back to the top of the loop

NOTTHROUGH
  ; check if top of stack (M[R6+1]) == R4
  LDR R5, R6, #1
  NOT R5, R5
  ADD R5, R5, #1
  ADD R5, R4, R5
  BRnp NOTPOP      ; not equal, so push
  ADD R6, R6, #1   ; pop only moves R6
  ADD R2, R2, #1   ; handled 1 car from the output
  LEA R5, COMMANDS ; prints a pOp
  LDR R0, R5, #1
  OUT
  BRnzp LOOPTOP    ; back to the top of the loop

NOTPOP
  ; TODO check for stack overflow
  ; TODO check that R3 is not null terminator
  STR R3, R6, #0   ; push
  ADD R6, R6, #-1
  ADD R1, R1, #1   ; handled one input car
  LEA R5, COMMANDS ; prints a pUsh
  LDR R0, R5, #2
  OUT
  BRnzp LOOPTOP    ; back to the top of the loop

LOOPBOT
  HALT


COMMANDS .STRINGZ "TOU"
INORD .STRINGZ "ABCD"
OUTORD .STRINGZ "CBAD"
STACK_TOP .BLKW #20
STACK_BOT .FILL #0

.END
