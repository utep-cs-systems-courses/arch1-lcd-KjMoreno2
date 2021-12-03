	.arch msp430g2553
	.p2align 1,0

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
	cmp #1, &dimState 	;switch statement check if dim state 0, 1, 2
	jl case_0		;executes instructions according to value in dimstate
	cmp #2, &dimState
	jl case_1
	cmp #3, &dimState
	jl case_2
case_0:
	call #redDim50
	call #greenDim50
	add #1, &dimState
	jmp out
case_1:
	call #redDim75
	call #greenDim25
	add #1, &dimState
	jmp out
case_2:
	call #redDim25
	call #greenDim75
	mov #0, &dimState
	jmp out
out:
	pop r0
