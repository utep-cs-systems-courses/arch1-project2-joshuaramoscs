	.arch msp430g2553
	.text
	.global toggle_red
	.global toggle_green
toggle_red:
	sub #2, R1			; Allocate memory in stack for char changed
	mov.b #0, 0(R1)			; char changed = 0
	cmp.b #1, &red_on		; if(red_on)
	jn red_is_off			; if false, goto red_is_off
	mov.b #0, &red_on		; red_on = 0
	mov.b #1, 0(R1)			; changed = 1
	mov.b 0(R1), R12		; save changed to R12
	add #2, R1			; Reset stack
	ret				; return
	

red_is_off:
	mov.b #1, &red_on		; red_on = 1
	mov.b #1, 0(R1)			; changed = 1
	mov.b 0(R1), R12		; save changed to R12
	add #2, R1			; Reset stack
	ret				; return


toggle_green:
	sub #2, R1			; Allocate memory in stack for char changed
	mov.b #0, 0(R1)			; char changed = 0
	cmp.b #1, &green_on		; if(green_on)
	jn green_is_off			; if false, goto green_is_off
	mov.b #0, &green_on		; green_on = 0
	mov.b #1, 0(R1)			; changed = 1
	mov.b 0(R1), R12		; save changed to R12
	add #2, R1			; Reset stack
	ret				; return
	

green_is_off:
	mov.b #1, &green_on		; green_on = 1
	mov.b #1, 0(R1)			; changed = 1
	mov.b 0(R1), R12		; save changed to R12
	add #2, R1			; Reset stack
	ret				; return
