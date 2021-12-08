	.arch msp430g2553
	.p2align 1,0


	.text
jt:
	.word case0
	.word case1
	.word case2
	
	.data
dimState:	 .word 0

	.text
	.extern redDim75
	.extern greenDim25
	.extern redDim25
	.extern greenDim75
	.extern redDim50
	.extern greenDim50
	.global dim_sequence
dim_sequence:
	cmp #3, &dimState 	;switch statement check if dim state 0, 1, 2
	jc out		;executes instructions according to value in dimstate
	mov &dimState, r12
	add r12, r12
	mov jt(r12), r0
case2:
	call #redDim50
	call #greenDim50
	mov #0, &dimState
case1:
	call #redDim75
	call #greenDim25
	add #1, &dimState
case0:
	call #redDim25
	call #greenDim75
	add #1, &dimState
out:
	pop r0
