## 
## Implemention of the "binary search" function 
##  in MIPS assembly
##
## bin_search(int A[], int N, int X) {
##     low = 0; high = N-1;
##      while (high < low) {     
##        mid = (low + high) / 2
##        if (X < A[mid]) 
##           high = mid - 1;
##        else if (X > A[mid]):
##           low = mid + 1;
##        else 
##           return mid;
##       }
##       return -1;       // not found
##
#################################################
#     	 	data segment			            #
#################################################

.data
 .align 2
  A: 
    .space 400

# statically defined input strings
 .align 2
   msg1:
      .asciiz "Please enter the size of the array N > 0 : "
   msg2:
      .asciiz "Please enter a non-decreasing sorted list of N numbers  : "
   msg3: 
      .asciiz "Please enter an integer number X : "

#################################################
#     	 	text segment			            #
#################################################
.text
.globl main         	# label "main" must be global

main:
# Read size N of array
####		
        li $v0, 4           # Message to enter a number
	la $a0, msg1
	syscall
again: 
        li $v0,5            # Loop until n>0
	syscall
	blez $v0, again
        move $t0, $v0       # $t0 = N
		
        li $v0, 4           # Message to enter the sorted list
	la $a0, msg2
	syscall
		  
        li $t1, 0
        li $t2, 0

#### 
# Read N already sorted numbers. No need to check for that property. 
####
read_loop: 
        li $v0,5            # Read n numbers
	syscall             # and store them in array A[]
        sw $v0, A($t2)
        addi $t2, $t2, 4
        addi $t1, $t1, 1
        blt $t1, $t0, read_loop
#### 
# Read integer X  
####
        li $v0, 4           # Message to enter X
	la $a0, msg3
	syscall        
        li $v0, 5   # read the input number 
        syscall
#
        la $a0, A          # Prepare the input arguments
        move $a1, $t0
	move $a2, $v0
#		   
	jal bin_search       # and call "binary search"
#		   
	move $a0, $v0
        li $v0, 1   # print output
        syscall

	li $v0,10        # And exit!
	syscall	

###########
#######  Binary Search function :bin_search(A[], N, X)
###########
bin_search :      #$a0, $a1, $a2 are the inputs         
	 li $v0, -1  # Initialize default output value 
	 li $t0, 0          # $t0 = low 
	 addi $t1, $a1, -1  # $t1 = high		 
loop:   
         bgt  $t0, $t1, Exit
	 add  $t2, $t0, $t1
         srl  $t2, $t2, 1    #$t2 = mid
         sll  $t3, $t2, 2
         add  $t3, $a0, $t3  
	 lw   $t3, 0($t3)    #$t3 = A[mid]
		 
         bge  $a2, $t3, L1   # 
	 addi $t1, $t2, -1    # X < A[mid]
         j loop		 
L1:      beq  $a2, $t3, L2
         addi $t0, $t2, 1     # X < A[mid]
         j loop
L2: 	 move $v0, $t2        # X == A[mid]
			 
Exit:		 		
	jr   $ra
