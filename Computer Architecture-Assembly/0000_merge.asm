########################################################
# void merge(int *out, int *in1, int N, int *in2, int M)
#                $s0      $a0     $a1     $a2       $a3
########################################################
#{
#	int i,j,k=0;
#
#	i=0;
#	j=0;
#for1:
#	if (i>=N) goto endfor1;
#	if (j>=M) goto endfor1;
#	out[k]=in1[i];
#	if (in1[i]<=in2[j]) goto ifelse;
#	  out[k]=in2[j];
#	  j++;
#	  goto endif;
#ifelse:
#	  i++;
#endif:
#	  k++;
#	goto for1;
#endfor1:
#
#for2: if (i>=N) goto endfor2;
#		out[k]=in1[i];
#		k++;
#		i++;
#		goto for2;
#endfor2:
#
#for3: if (j>=M) goto endfor3;
#		out[k]=in2[j];
#		k++;
#		j++;
#		goto for3;
#endfor3:
#return;
#}
merge:
#save local variables to stack
addi $sp,$sp,-24 # reserve stack
sw  $ra, 0($sp)   # push $ra
sw  $s0, 4($sp)   # s1=i, index for in1, $a0, $a1=N, size of in1
sw  $s1, 8($sp)   # s1=i, index for in1, $a0, $a1=N, size of in1
sw  $s2,12($sp)   # s2=j, index for in2, $a2, $a3=M, size of in2
sw  $s3,16($sp)   # s3=k, index for out, $s0, $s4=N+M, size of out
sw  $s4,20($sp)   # s4=N+M, size of out
#retrieve argument from stack
lw   $s0,24($sp)  # get out from stack
#initialize var
li  $s1,0         # i=0 
li  $s2,0         # j=0
li  $s3,0         # k=0
add $s4,$a1,$a3   # size of out= N+M

merge_for1:
   bge $s1,$a1,merge_endfor1   # if (i>=N) goto endfor1;
   bge $s2,$a3,merge_endfor1   # if (j>=M) goto endfor1;
# out[k]=in1[i]
      # t2=in1[i]
      la  $t0,($a0)   # t0 = address of in1
      sll $t1,$s1,2   # t1 = aligned index i
      add $t0,$t0,$t1 # t0= index of in1
      lw  $t2,($t0)    # t2= in1[i]
      # t4->out[k]
      la  $t4,($s0)   # t0 = address of out
      sll $t1,$s3,2   # t1 = aligned index k
      add $t4,$t4,$t1 # t4= index of out
      sw $t2,($t4)    # out[k]=in1[i]
      # t3=in2[j]
      la  $t0,($a2)   # t0 = address of in2
      sll $t1,$s2,2   # t1 = aligned index j
      add $t0,$t0,$t1 # t0= index of in2
      lw $t3,($t0)    # t3= in2[j]
# if (in1[i]<=in2[j]) goto ifelse;
      ble $t2,$t3,merge_ifelse
         sw $t3,($t4)    # out[k]=in2[j]
         addi $s2,$s2,1  # j=j+1
      j merge_endif
merge_ifelse:
         addi $s1,$s1,1 # i=i+1
merge_endif:
         addi $s3,$s3,1 # k=k+1
      j merge_for1
merge_endfor1:

# continue with rest of in1
#for2: if (i>=N) goto endfor2;
#		out[k]=in1[i];
#		k++;
#		i++;
#		goto for2;
#endfor2:
merge_for2:
      bge $s1,$a1,merge_endfor2   # if (i>=N) goto endfor2;
      # t2=in1[i]
      la  $t0,($a0)    # t0 = address of in1
      sll $t1,$s1,2    # t1 = aligned index i
      add $t0,$t0,$t1  # t0= index of in1
      lw  $t2,($t0)    # t2= in1[i]
      # t4->out[k]
      la  $t4,($s0)    # t0 = address of out
      sll $t1,$s3,2    # t1 = aligned index k
      add $t4,$t4,$t1  # t4= index of out
      sw $t2,($t4)     # out[k]=in1[i]
      addi $s3,$s3,1   # k=k+1
      addi $s1,$s1,1   # i=i+1
      j merge_for2
merge_endfor2:

# continue with the rest of in2
#for3: if (j>=M) goto endfor3;
#		out[k]=in2[j];
#		k++;
#		j++;
#		goto for3;
#endfor3:
merge_for3:	
      bge $s2,$a3,merge_endfor3   # if (j>=M) goto endfor3;
      # t3=in2[j]
      la  $t0,($a2)    # t0 = address of in2
      sll $t1,$s2,2    # t1 = aligned index j
      add $t0,$t0,$t1  # t0= index of in2
      lw $t3,($t0)     # t3= in2[j]
      # t4->out[k]
      la  $t4,($s0)    # t4 = address of out
      sll $t1,$s3,2    # t1 = aligned index k
      add $t4,$t4,$t1  # t4= index of out
      sw $t3,($t4)     # out[k]=in2[j]

      addi $s3,$s3,1   # k=k+1
      addi $s2,$s2,1   # j=j+1
      j merge_for3
merge_endfor3:

#return
lw $ra, 0($sp)   # push $ra
lw $s0, 4($sp)   # s1=i
lw $s1, 8($sp)   # s1=i
lw $s2,12($sp)   # s2=j
lw $s3,16($sp)   # s3=k
lw $s4,20($sp)   
addi $sp,$sp,24 # reserve stack
jr $ra
