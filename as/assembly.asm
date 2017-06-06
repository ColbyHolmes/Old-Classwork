add $s0, $zero, $zero
LOOP: slti $t0, $s0, 200
beq $t0, $zero, EXIT
addi $t1, $s0, 2
sll $t2, $s0, 2
add $t2, $s1, $t2
sw $t1, 0($t2)
addi $s0, $s0, 1
j LOOP
EXIT: