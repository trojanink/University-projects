#
# Compute Taylor series of sin(x) = Sum{((-1)^k/(2k+1)!)/x^{2k+1)
# This can be computed iteratively as 
# sinx = E0 + E1 + E2 + ... + E(k-1) + E(k-1)* (-1)/(2k*(2k+1)) * x^2
# In this case, we set x = 1.423 and sin(x) = 0.989098 in .data segment
#################################################
#     	 	data segment			           #
#################################################
.data
 .align 2
   x:
      .float 1.423
   sinx:
      .float 0.989098
   error:
      .float 10e-6
   msg1:
      .asciiz "sin(x)= "
   msg2:
      .asciiz "k =  "
   newline:
      .asciiz "\n"
  
#################################################
#     	 	text segment			            #
#################################################
.text
.globl main            		# label "main" must be global

main:

        lwc1 $f30, sinx($0)   # sinx in $f30
        lwc1 $f31, error($0)  # error in $f31
        lwc1 $f0, x($0)       # Taylor series in $f0. Initially equal to x
        mov.s $f20, $f0       # E(k-1). Initally equal to E0=x
        mul.s $f2, $f0, $f0   #x^2 in $f2
     
        li $t0, 0
        mtc1 $t0, $f4
        cvt.s.w $f4, $f4   # k in $f4
        li $t0, -1
        mtc1 $t0, $f6
        cvt.s.w $f6, $f6   # -1 in $f6
        li $t0, 1
        mtc1 $t0, $f8
        cvt.s.w $f8, $f8   # 1 in $f8
        li $t0, 2
        mtc1 $t0, $f10
        cvt.s.w $f10, $f10   # 2 in $f10
loop:      
        sub.s $f1, $f30, $f0   # Check for error 
        abs.s $f1, $f1
        c.lt.s $f1, $f31
        bc1t Exit

        mul.s $f20, $f20, $f6    # next element in series 
        mul.s $f20, $f20, $f2
        add.s $f4, $f4, $f8    # k
        mul.s $f5, $f4, $f10    # 2k
        add.s $f7, $f5, $f8    # $f7=2k+1
        mul.s $f9, $f5, $f7    # 2k * (2k+1)

        div.s $f20, $f20, $f9
        add.s $f0, $f0, $f20  # E(k) 
  
        j loop

Exit:
        la $a0, msg1
        li $v0, 4
        syscall
        mov.s $f12, $f0
        li $v0, 2             # Print sinx
	    syscall 
        la $a0, newline
        li $v0, 4
        syscall
        la $a0, msg2
        li $v0, 4
        syscall
        mov.s $f12, $f4
        li $v0, 2             # Print sinx
	syscall 
        li $v0, 10           # Exit
	syscall 


       
  
