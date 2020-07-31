#################################################
#     	 	data segment			            
#################################################

.data

# statically defined input strings
giveStr:
      .asciiz "Please give a valid string (uppercase) : "
result:
      .asciiz "Result : \n"

# string
str:  .space 50		
 
#################################################
#     	 	text segment			            
#################################################
.text
.globl main            		# label "main" must be global

main:
	# message to read string
	li $v0, 4          
	la $a0, giveStr
	syscall
	# read string
        la $a0, str	# Read the input string 
	la $a1, 50    	# maximum space is 50 chars
	li $v0, 8     	# read_string
	syscall
	
	# remove '\n' from end of string
	la $a0, str
	jal remnl
	
	
	# call check_roman(str)
        la $a0, str
        jal check_roman		
        
        # retrieve function result, if zero, ask for string again
        beqz $v0, main
        
        # call roman_to_decimal(str)
        la $a0, str
        jal roman_to_decimal
        
        # retrieve function result
	move $t0, $v0
	
	# print result
	li $v0, 4
	la $a0, result
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	# Exit
	li $v0,10     
	syscall	

# remove \n character read by syscall 8
remnl:
	li $t9, '\n'	# stop at \n character
	li $t8, '\0'	# if there is no \n character, stop at \0
	loop:
		lb $t0, 0($a0)
		beq $t0, $t9, processnl
		beq $t0, $t8, endloop
		addi $a0, $a0, 1
		j loop
	endloop: 
		jr $ra
	# replace \n by \0
	processnl:
		sb $t8, 0($a0)
		jr $ra


# function int check_roman(char *s)
check_roman:
	# store parameter and $ra in stack
	addi $sp, $sp, -8
	sw $a0, 0($sp)
	sw $ra, 4($sp)
	
	# load *s
	lb $s0, 0($a0)
	
	# if zero, then string is ok
	beqz $s0, ifzero
	
	# call function value to check if *s is valid character
	move $a0, $s0
	jal value
	
	# if returned value is -1, then character is invalid
	li $t0, -1
	beq $v0, $t0, ret0
	
	# recursive call of check_roman(s+1)
	lw $a0, 0($sp)
	addi $a0, $a0, 1
	jal check_roman
	
	# return 1
	ifzero:
	li $v0, 1
	j restore_stack
	
	# return 0
	ret0:
	li $v0, 0
	j restore_stack
	
	# restore stack values and return
	restore_stack:
	lw $a0, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra
	
# function int roman_to_decimal(char *s)
roman_to_decimal:
	# store parameters and $ra in stack
	addi $sp, $sp, -8
	sw $a0, 0($sp)
	sw $ra, 4($sp)
	
	# if last character, then return value(*s)
	lb $t0, 1($a0)
	beqz $t0, ifone
	
	# else, call n=value(*s)
	lb $a0, 0($a0)
	jal value
	move $t0, $v0
	# call value(*(s+1))
	lw $a0, 0($sp)
	lb $a0, 1($a0)
	jal value
	lw $a0, 0($sp)
	move $t1, $v0
	# if n < value(*(s+1)) then n = -n;
	bge $t0, $t1, next
	sub $t0, $0, $t0
	# return n + roman_to_decimal(s+1, size-1)
	next:
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	addi $a0, $a0, 1
	jal roman_to_decimal
	lw $t0, 0($sp)
	addi $sp, $sp, 4
	add $v0, $t0, $v0
	j rest_stack
	
	# return value(*s)
	ifone:
	lb $a0, 0($a0)
	jal value
	
	# restore stack values and return
	rest_stack:
	lw $a0, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra


# int value(char c), returns value of each valid character, -1 otherwise
value:
	li $t9, 'M'
	beq $a0, $t9, caseM
	li $t9, 'D'
	beq $a0, $t9, caseD
	li $t9, 'C'
	beq $a0, $t9, caseC
	li $t9, 'L'
	beq $a0, $t9, caseL
	li $t9, 'X'
	beq $a0, $t9, caseX
	li $t9, 'V'
	beq $a0, $t9, caseV
	li $t9, 'I'
	beq $a0, $t9, caseI
	li $v0, -1
	jr $ra
	caseM:
		li $v0, 1000
		jr $ra
	caseD:
		li $v0, 500
		jr $ra
	caseC:
		li $v0, 100
		jr $ra
	caseL:
		li $v0, 50
		jr $ra
	caseX:
		li $v0, 10
		jr $ra
	caseV:
		li $v0, 5
		jr $ra
	caseI:
		li $v0, 1
		jr $ra
