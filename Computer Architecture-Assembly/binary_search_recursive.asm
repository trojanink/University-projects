## 
## Implemention of the "recursive binary search" function 
##  in MIPS assembly
##
## int recursive_bin_search(int A[], int X, int low, int high) {
##  
##        mid = (low + high) / 2
##        if (low > high)
##            return -1;
##        else if (X == A[mid])
##            return mid;
##        else if (X < A[mid]) 
##           return recursive_bin_search (A[], X, low, mid-1);
##        else  if (X > A[mid]);
##           return recursive_bin_search (A[], X, mid+1, high)
##       }
##
#################################################
#     	 	data segment			#
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
     move $t0, $v0       # $t0 = N-1
     addi $t0, $t0, -1
		
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
        ble $t1, $t0, read_loop
#### 
# Read integer X  
####
        li $v0, 4           # Message to enter X
	la $a0, msg3
	syscall        
        li $v0, 5   # read the input number 
        syscall
# Prepare  input arguments
        la $a0, A        # $a0 = &A[0]   
        move $a1, $v0    # $a1 = X
        li $a2, 0        # $a2 = low = 0
	move $a3, $t0    # a3 = high = N-1
#		   
	jal rec_bin_search       # and call "binary search"
#		   
	move $a0, $v0
        li $v0, 1   # print output
        syscall

	li $v0,10        # And exit!
	syscall	

###########
#######  Binary Search function :bin_search(A[], X, low, high)
###########
rec_bin_search :      #$a0, $a1, $a2, $a3 are the inputs    
         addi $sp, $sp, -12
         sw $ra, 8($sp)      
         sw $a2, 4($sp)  
         sw $a3, 0($sp) 
  
        ble  $a2, $a3, L1   # if (low > high) return -1
        li $v0, -1
        j Exit
L1:     
        add  $t0, $a2, $a3
        srl  $t0, $t0, 1   # $t0 = mid
        sll  $t1, $t0, 2
        add  $t2, $a0, $t1  
	lw   $t2, 0($t2)    #$t2 = A[mid]	 
        bne  $a1, $t2, L2    
        move $v0, $t0     # if (X == A[mid]) return mid;
	j Exit    
L2:     bgt $a1, $t2, L3  
        addi $a3, $t0, -1 # if (X < A[mid]) return rec_bin_search (A[], X, low, mid-1);
        jal rec_bin_search
        j Exit
L3:
        addi $a2, $t0, 1  # if (X > A[mid]) return rec_bin_search (A[], X, mid+1, high);     
        jal rec_bin_search

Exit:		 
         lw $ra, 8($sp)      
         lw $a2, 4($sp)  
         lw $a3, 0($sp)   	
         addi $sp, $sp, 12	
	 jr   $ra
