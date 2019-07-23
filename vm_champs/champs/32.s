.name           "42"
.comment        "Just a basic Winner Program"

entree:	live	%42		# entree
	ld	%0,r5
	ld	%0,r5
	zjmp	%:bite

tir:	sti	r1,%:tirb,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11
