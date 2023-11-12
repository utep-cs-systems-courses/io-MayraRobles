	.arch msp430g2553
	.p2align 1,0
	.text

	.global oncePerSecond
	.extern blinkLimit
	
oncePerSecond:
	add #1, blinkLimit
	cmp #8, &blinkLimit 	; check blinkLimit < 8 (if yes c = 0)
	jnc smaller_than_8
	mov #0, &blinkLimit
	pop r0
smaller_than_8:
	pop r0
	
