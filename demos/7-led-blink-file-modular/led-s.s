	.arch msp430g2552
	.p2align 1,0
	
	.data			; global and static variables go in the data segment
	.extern P1DIR
	.extern P1OUT
	.extern LEDS
red_on:		.byte 0
green_on:	.byte 0
led_changed:	.byte 0
ledFlags:	.byte 0
redVal:		.byte 0
		.byte LED_RED
greenVal:	.byte 0
		.byte LED_GREEN
	
	.text			; instructions go in the text segment
	.global led_init
	.global led_update

led_init:
	bis.b &LEDS, &P1DIR
	mov #1, &led_changed
	call led_update
	
led_update:
	cmp #0, &led_changed	; check is led_changed is 0 
	jz not_led_changed
	
	mov.b &red_on, r1	; ledFlags = redVal[red_on] | greenVal[green_on]
	add.b r1, r1
	add.b #redVal, r1
	mov.b @r1, r2
	mov.b &green_on, r1
	add.b r1, r1
	add.b #greenVal, r1
	add.b @r1, r3
	mov.b r2, &ledFlags
	bis.b r3, &ledFlags
	
	mov #0xff, r1		; P1OUT &= (0Xff^LEDS) | ledFlags
	xor.b &LEDS, r1
	bis.b &ledFlags, r1
	and.b r1, &P1OUT

	bis.b &ledFlags, &P1OUT
	mov #0, &led_changed
	pop r0
	
not_led_changed:
	pop r0
