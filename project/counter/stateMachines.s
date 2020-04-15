	.arch msp430g2553
	.data			; state is a static variable (in ram)

state:
	.word 1
	
	.text			; jt is constants (in flash)
jt:
	.word state0
	.word state1
	.word state2
	.word state3

	.global state_loop
state_loop:
	;; range check on selector (s)
	cmp #4, &state		; state-4 doesn't borrow uf state>3
	jhs out			; jmp if state > 3

	;; index into jt
	mov &state, R12
	add R12, r12		; R12=2*state
	mov jt(r12), r0		; jmp jt[state]

	;; switch table options
state0:
	call #state_zero
	cmp R12, #0		; if(!state_zero())
	jn changed0
	mov #0, &led_changed	; led_changed = 0
	mov #1, state		; state = 1
	jmp out			; break
changed0:
	mov #1, &led_changed	; led_changed = 1
	mov #1, state		; state = 1
	jmp out			; break
state1:
	call #state_one
	cmp R12, #0		; if(!state_one())
	jn changed1
	mov #0, &led_changed	; led_changed = 0
	mov #2, state		; state = 2
	jmp out			; break
changed1:
	mov #1, &led_changed	; led_changed = 1
	mov #2, state		; state = 2
	jmp out			; break
state2:
	call #state_two
	cmp R12, #0		; if(!state_two())
	jn changed2
	mov #0, &led_changed	; led_changed = 0
	mov #3, state		; state = 3
	jmp out			; break
changed2:
	mov #1, &led_changed	; led_changed = 1
	mov #3, state		; state = 3
	jmp out			; break
state3:
	call #state_three
	cmp R12, #0		; if(!state_three())
	jn changed3
	mov #0, &led_changed	; led_changed = 0
	mov #0, state		; state = 0
	jmp out			; break
changed3:
	mov #1, &led_changed	; led_changed = 1
	mov #0, state		; state = 0
	jmp out			; break
out:
	pop R0
