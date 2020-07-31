# int count = 0;
# for (int i = 0 ; i < 32 ; i+=2) {
#     int two_bits = N & 3;
#     switch (two_bits) {
#       case 0:  	break;
#       case 1:  	
#       case 2:		count ++; 	break;
#       case 3:  	count += 2; 	break;
#     }
#     N = N >> 2;
# }

######################### .data segment #########################
.data
.align 2

jump_table: 
    .word zero one two three

######################### .text segment #########################
.text
main:

    li $v0, 5 
	syscall  # $v0 = N
	move $a0, $v0
	
	jal countOnes
	
	move $a0, $v0        # print output
	li $v0, 1
	syscall
	
	li $v0, 10      # and exit
	syscall

	
countOnes:

	li	$v0, 0			# counts
	li	$t1, 0			# i 
	
loop:
	bge	$t1, 32, end
	and	$t2, $a0, 3		# a0 & 3
	sll	$t2, $t2, 2		# t2 = t2 << 2 
	lw	$t3, jump_table($t2)
	jr	$t3

zero:  
	j	cont			# count doesn't change

one:	
two:
	add	$v0, $v0, 1		# count ++
	j	cont

three:
	add	$v0, $v0, 2		# count += 2
	j	cont

cont:	
	srl	$a0, $a0, 2		# a0 = a0 >> 2
	add	$t1, $t1, 2		# i += 2
	j	loop

end:
	jr	$ra
