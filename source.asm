main:
    addi t0, zero, 10
    addi t1, azero, 20
loop:
    addi t0, t0, 1
    beq t0, t1, exit
    jal loop  
exit:
    addi a7, 10
    ecall