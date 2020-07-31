##  
##
## Implemention of the "min/max" function 
##  in MIPS assembly
##
##
#################################################
#     	 	data segment			            #
#################################################

.data

# statically defined input strings
   msg1:
      .asciiz "Please give an integer >0 : "
  min_msg:
      .asciiz "MIN = "
  max_msg:
      .asciiz "MAX = "
  newline:
      .asciiz "\n"

.align 2
  array:
      .space 400
#################################################
#     	 	text segment			            #
#################################################
.text
.globl main            		# label "main" must be global

main:
        li $v0, 4           # Message to enter a number
	la $a0, msg1
	syscall
#### 
# Read size N of array
####		
again:
        li $v0,5            # Loop until n>0
	syscall
	blez $v0, again
	
	move $t0, $v0   
        li $t1, 0
        li $t2, 0
#### 
# Read N numbers
####
read_loop: 
        li $v0,5            # Read n numbers
	syscall             # and store them in array  
        sw $v0, array($t2)
        addi $t2, $t2, 4
        addi $t1, $t1, 1
        blt $t1, $t0, read_loop 
#### 
# Main part of the code 
####
        li $t1, 0
        li $s0, 0x80000000          # smallest integer (will contain the max)
        li $s1, 0x7FFFFFFF          # largest integer (will contain the min)
loop:                       
        bge $t1, $t0,  print      # main loop for min/max
        sll $t2, $t1, 2	       
        lw  $t2, array($t2)
        ble $t2, $s0,  L1
        move $s0, $t2
L1:     bge  $t2, $s1, L2
        move $s1, $t2
L2:     addi $t1, $t1, 1
        j    loop

#### 
# Print min and max to the console
####
print:                          # Finally, print min/max
        li $v0, 4               # First, min
	la $a0, min_msg
	syscall  
        move $a0, $s1
        li $v0, 1
        syscall
        li $v0, 4           
        la $a0, newline
	syscall  

        li $v0, 4               # Then, max
	la $a0, max_msg
	syscall  
        move $a0, $s0
        li $v0, 1
        syscall
        li $v0, 4           
	la $a0, newline
	syscall  
#### 
# and Exit
####    
Exit:		
	    li $v0,10      # and done!
	    syscall	



