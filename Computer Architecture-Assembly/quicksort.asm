################################################
# Implement quicksort recursively
#  void quicksort (int *array, int min, int max) [
#      if (size(array) > 1) {
#           pivot = array[N-1];
#           left = &array[0];
#           right = &array[N-1];
#           while (left <= right) {
#                while (array[left] < pivot)
#                       left++;
#                while (array[right] > pivot)
#                       right--;
#                if (left <= right) {
#                       swap(array[left], array[right]);
#                       left++;
#                       right--
#                }
#           }
#           quicksort(array, min, right);
#           quicksort(array, left, max);
#      }
#   }
################################################
#     	 	data segment			            
#################################################
.data

.align 2
array: .word 17 12 6 19 23 8 5 10
num: .word 8

#################################################
#     	 	text segment			            
#################################################
.text 
.globl main

main:
       la $a0, array
       lw $a1, num($0)    # array size
       jal print_array
       
       la $a0, array
       li $a1, 0    # first index
       lw $a2, num($0)  
       addi $a2, $a2, -1
       jal quicksort
       
       la $a0, array
       lw $a1, num($0)     # array size
       jal print_array
       
       li $v0, 10
       syscall
       
      
quicksort:
       addi $sp, $sp, -24
       sw $ra, 20($sp)
       sw $a0, 16($sp)  # pointer to beginning of array
       sw $a1, 12($sp)   # min
       sw $a2, 8($sp)    # max 
       sw $s0, 4($sp)
       sw $s1, 0($sp)
       
       sub $t0, $a2, $a1
       blez $t0, exit_qsort    # if size(array) <= 1 exit
       # else, partition the array     
       move $s0, $a1     
       sll $t0, $s0, 2
       add $t0, $a0, $t0  # left pointer
       move $s1, $a2
       sll $t1, $s1, 2
       add $t1, $a0, $t1  # right pointer
       lw $t9, 0($t1)     # pivot
L0:
       bgt $s0, $s1, goto_rec   # if (left > right) goto_rec
L1:
       lw $t2, 0($t0)       
       bge $t2, $t9, L2
       addi $t0, $t0, 4
       addi $s0, $s0, 1
       j L1
L2:    
       lw $t3, 0($t1)
       ble $t3, $t9, L3
       addi $t1, $t1, -4
       addi $s1, $s1, -1
       j L2
L3:               # swap 
       bgt $s0, $s1, goto_rec 
       lw $t2, 0($t0) 
       lw $t3, 0($t1)
       sw $t2, 0($t1)
       sw $t3, 0($t0)
       addi $t0, $t0, 4
       addi $s0, $s0, 1
       addi $t1, $t1, -4
       addi $s1, $s1, -1
       j L0
       
goto_rec: 
    #  quicksort(array($a0), min($a1), right($s1));    
       la $a0, array  
       lw $a1, 12($sp)
       move $a2, $s1
       jal quicksort
    # quicksort(array($a0), left($s0), max($a2));
       la $a0, array
       move $a1, $s0
       lw $a2, 8($sp) 
       jal quicksort

exit_qsort: 
       lw $s1, 0($sp)    
       lw $s0, 4($sp) 
       lw $a2, 8($sp) 
       lw $a1, 12($sp)
       lw $a0, 16($sp) 
       lw $ra, 20($sp)
       addi $sp, $sp, 24
       jr $ra

print_array:      
       move $t0, $a0
       move $t1, $a1        
print_loop:
       li $v0, 1
       lw $a0, 0($t0)
       syscall
       li $v0, 11
       li $a0, ' '
       syscall
       addi $t0, $t0, 4
       subi $t1, $t1, 1
       bgtz $t1, print_loop
       
       li $v0, 11
       li $a0, '\n'
       syscall
       jr $ra

