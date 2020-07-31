.data
str1: .asciiz "["
str2: .asciiz "]"
str3: .asciiz " "
str4: .asciiz "\n"

.align 0
str: .space 11
.text 
.globl main
main:

# read a string
li $v0, 8
la $a0, str
li $a1, 11
syscall

li $v0,4
la $a0,str4
syscall


# print string
li $v0, 4
la $a0, str
syscall

li $v0,4
la $a0,str4
syscall

la $t0, str
addi $t1, $t0, 11
loop:
	bge $t0, $t1, endloop

	li $v0,4
	la $a0,str1
	syscall
	
	li $v0,11
	lb $a0,($t0)
	syscall

	li $v0,34
	lb $a0,($t0)
	syscall

		
	li $v0,4
	la $a0,str2
	syscall
	
	addi $t0, $t0,1
	j loop
endloop:

li $v0,4
la $a0,str4
syscall

# put \0 in str[1]
la $t0,str
li $t1,0
sb $t1, 1($t0)

# print string
li $v0, 4
la $a0, str
syscall

li $v0,4
la $a0,str4
syscall
		

exit:	
#exit program
li $v0,10
syscall

