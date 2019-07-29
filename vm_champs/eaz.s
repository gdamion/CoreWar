.name "EZ"
.comment "ez"

l2:		sti r1, %:live, %1

live:	live %1
		zjmp %:live

livex:  live %66
        fork %:live

live1:    live %1
        zjmp %:live

debut:    ld %0,r7
        zjmp %:l2
