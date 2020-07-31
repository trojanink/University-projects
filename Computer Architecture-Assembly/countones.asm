.data

.text

.globl main

main:

	li $s0, 13
	li $s1, 0          # count=0
	and $t0, $s0, 0xFF # temp=s0

loop:
	and $t1, $t0, 1   # mask with 0x00000001
	add $s1, $s1,$t1  # count++ if mask=1
	srl $t0, $t0, 1   # shift right
	bnez $t0, loop
	

	li $v0,1
	move $a0, $s1
	syscall
	
	li $v0,10
	syscall
