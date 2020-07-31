# Data Segment
.data
# Text Segment
.text
.globl main

main:
  li $a0, 12345
  jal athroisma

  move $a0,$v0  
  li $v0, 1
  syscall
  
  li $v0,10
  syscall
  

# athroizei ta psifia enos akeraiou
athroisma:
  li $t0, 10    # t0=10
  move $t1, $a0 # t1=a0
  li $t3,0      # t3=0, t3=athroisma psifiwn
  
Loop:
  div  $t1,$t0       #t1/10
  mflo $t1           #t1 = piliko
  mfhi $t2           #t2 = ypoloipo
  add  $t3, $t3,$t2  #t3=t3+ypoloipo
  beqz $t1, Exit     #If t1<>0 go to Loop

j Loop
Exit:
  move $v0, $t3
  jr $ra
