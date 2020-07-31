# Συνεχίςτε το πρόγραμμα ςασ ςτον παρακάτω πίνακα.
# Data Segment
.data
.align 2
str: .space 100
# Text Segment
text
.globl main
main:
li $v0, 5
syscall
move $a0, $v0
la $a1, str
jal itoa
li $v0, 10
syscall
itoa:
li $t0, 10 # t0=10
move $t1, $a0 # t1=a0
addi $t3, $a1, 100
Loop:
addi $t3, $t3,-1
div $t1,$t0 #t1/10
mflo $t1 #t1 = quotient
mfhi $t2 #t2 =remainder
beqz $t1, Exit #If t1<>0 go to Loop
addi $t2,$t2,’0’ #Convert to ASCII
sb $t2,0($t3) # Write t2
j Loop
Exit:
move $v0, $t3
jr $ra