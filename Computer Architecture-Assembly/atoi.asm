# Συνεχίστε το πρόγραμμα σας στον παρακάτω πίνακα. 
#   Data Segment 
.data 
  str: 
       .asciiz "894673"

#   Text  Segment 
.text
.globl main     
       		
main:   
     la $a0, str
     jal atoi
     move $a0, $v0
     li $v0, 1
     syscall
     li $v0, 10
     syscall

     
 atoi:
     li $v0, 0
 loop:
     lb $t1, 0($a0)
     beqz $t1, Exit
     subu $t1, $t1, '0'
     mul $v0, $v0, 10
     addu $v0, $v0, $t1
     addi $a0, $a0, 1
     j loop
Exit:
     jr $ra
