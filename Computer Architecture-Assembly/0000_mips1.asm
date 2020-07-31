.data 
dimensionN: .asciiz "Please give the dimension of the matrix: \n**** user input : "
fill: .asciiz "Now you have to fill the matrix\n"
int: .asciiz "Please give an integer : \n****user input : "
dimensionM: .asciiz "Please the dimension of the submatrix \n**** user input : "
left: .asciiz "Please define the left distance \n**** user input : "
upper: .asciiz "Please define the upper distance\n**** user input : "
new_matrix: .asciiz "The new matrix is: \n"
linefeed: .asciiz "\n"
space: .asciiz " "


.align 2
vector: .space 400
vector_new: .space 400

.text
.globl main

main:

li $v0,4			#Prints the dimensionN string
la $a0,dimensionN
syscall

li $v0,5			#Reads the N to $s0
syscall
move $s0,$v0

mul $t0,$s0,$s0			# $t0==$s0^2
addi $t1,$0,0			#$t1==0

li $v0,4			#Prints the fill string
la $a0,fill
syscall

fill_matrix:
	li $v0,4			#Prints the int string
	la $a0,int
	syscall
	
	li $v0,5			#Reads the int to $t2
	syscall
	move $t2,$v0
	
	sw $t2,vector($t1)		#store word $t2-->vector
	
	addi $t1,$t1,4			# $t1+=4
	addi $t4,$t4,1
	blt $t4,$t0,fill_matrix		#$t1<=$t0 -->fill

li $v0,4			#Prints the dimensionM string
la $a0,dimensionM
syscall

li $v0,5			#Reads the M to $s1
syscall
move $s1,$v0

mul $s4,$s1,$s1			#s4==$s1^2

li $v0,4			#Prints the left string
la $a0,left
syscall

li $v0,5			#Reads the left $s2
syscall
move $s2,$v0

li $v0,4			#Prints the upper string
la $a0,upper
syscall

li $v0,5			#Reads the upper to $s3
syscall
move $s3,$v0

mul $t5,$s3,$s0
add $t5,$t5,$s2		
sll $t5,$t5,2			#$t5==(upper*N+left)*4(begins the submatrix)

add $t9, $s3, $s1
mul $t9, $t9, $s0
add $t9, $t9, $s2
sll $t9, $t9, 2       #$t9=((upper+M)*N+left) * 4 (begins next row after submatrix)

li $t1,0			#Reseting counters $t1,$t4
li $t4,0
copy:
	beq $t1,$t5,subloop		#if $t1==$t5 -->subloop
cont:	
	lw $t2,vector($t1)		#Reads the word from vector to $t2
	sw $t2,vector_new($t1)		#Stores $t2 to vector_new
	
	addi $t1,$t1,4
	addi $t4,$t4,1
	bge $t4,$t0,EXIT
	j copy
	
subloop:
	bge $t1, $t9, cont
	li $t8,0
sloop:	
	addi $t8,$t8,1
	lw $t2,vector($t1)		#Reads the word from vector to $t2
	sll $t2,$t2,2			#$t2*4
	add $t6,$0,$t1			#t6=t1		thesi panw
	sll $t7,$s0,2			#t7=N*4		thesi		
	sub $t6,$t6,$t7			#t6=t6-t7	thesi
	lw $t7,vector($t6)
	add $t2,$t2,$t7			#t2=t2+t7		aristera
	addi $t6,$t1,0			#t6=t1
	subi $t6,$t6,4			#t6=t6-4
	lw $t7,vector($t6)		
	add $t2,$t2,$t7			#t2=t2-t7		deksia
	addi $t6,$t1,0			#t6=t1
	addi $t6,$t6,4			#t6=t6+4
	lw $t7,vector($t6)
	add $t2,$t2,$t7			#t2=t2+t7		katw
	addi $t6,$t1,0			#t6=t1
	sll $t7,$s0,2			#t7=n*4
	add $t6,$t6,$t7			#t6=t6+t7
	lw $t7,vector($t6)
	add $t2,$t2,$t7
	div $t2,$t2,8
	sw $t2,vector_new($t1)
	
	
	addi $t1,$t1,4
	addi $t4,$t4,1
	
	
	beq $t8,$s1,counters
	j sloop
	
	
counters:
	srl $t5,$t5,2
	add $t5,$t5,$s0
	sll $t5,$t5,2
	j copy
	
			
EXIT:
	li $v0,4			#Prints the new_matrix string
	la $a0,new_matrix
	syscall	
	
	
	li $t1,0
	li $t4,0	
test:
		li $s7,0
print:

	
	lw $t3,vector_new($t1)
	
	li $v0,1
	addi $a0,$t3,0
	syscall
	
	li $v0,4			#Prints the space
	la $a0,space
	syscall
	
	addi $t1,$t1,4
	addi $t4,$t4,1
	addi $s7,$s7,1
	blt $s7,$s0,print
	
	li $v0,4			#Prints the linefeed
	la $a0,linefeed
	syscall

	blt $t4,$t0,test

		
	
li $v0,10
syscall
	








