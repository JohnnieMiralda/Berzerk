.globl printScore
.extern berzerk



printScore:

    addi $sp,$sp,-4
    sw $ra, 0($sp)
    li $a0,1
    li $a1,2
    jal set_cursor

    
    li $a0,83
    jal put_char

    li $a0,67
    jal put_char

    li $a0,79
    jal put_char

    li $a0,82
    jal put_char

    li $a0,69
    jal put_char

    li $a0,58
    jal put_char

    li $a0,1
    jal put_char

    move $t0, $zero //contador para mil
    move $t1, $zero //contador para cien
    move $t2, $zero //contador para dies

    la $t5, berzerk //cargo la info
    lw $t5, 0($t5) //cargo el score

    beq $t5,0,dies_end
    li $t4,1000
    bge $t5, $t4,while_mil
    j mil_end

    while_mil:
        addi $t5,$t5,-1000
        addi $t0,$t0,1
        bge $t5, $t4,while_mil
    mil_end:

    li $t4,100
    bge $t5, $t4,while_cien
    j cien_end

    while_cien:
        addi $t5,$t5,-100
        addi $t1,$t1,1
        bge $t5, $t4,while_cien
    cien_end:

    li $t4,10
    bge $t5, $t4,while_dies
    j dies_end

    while_dies:
        addi $t5,$t5,-10
        addi $t2,$t2,1
        bge $t5, $t4,while_dies
    dies_end:

    beq $t0,$zero,mil_zzer
    beq $t0,1,mil_uno
    beq $t0,2,mil_dos
    beq $t0,3,mil_tre
    beq $t0,4,mil_cua
    beq $t0,5,mil_cin
    beq $t0,6,mil_sei
    beq $t0,7,mil_siet
    beq $t0,8,mil_och
    beq $t0,9,mil_nue


    print_mil:
        mil_zzer:
            li $a0,48
            jal put_char
        j end_print_mil
        mil_uno:
            li $a0,49
            jal put_char
        j end_print_mil

        mil_dos:
            li $a0,50
            jal put_char
        j end_print_mil

        mil_tre:
            li $a0,51
            jal put_char
        j end_print_mil

        mil_cua:
            li $a0,52
            jal put_char
        j end_print_mil

        mil_cin:
            li $a0,53
            jal put_char
        j end_print_mil

        mil_sei:
            li $a0,54
            jal put_char
        j end_print_mil

        mil_siet:
            li $a0,55
            jal put_char
        j end_print_mil

        mil_och:
            li $a0,56
            jal put_char
        j end_print_mil

        mil_nue:
            li $a0,57
            jal put_char

    end_print_mil:

    beq $t1,$zero,cien_cer
    beq $t1,1,cien_uno
    beq $t1,2,cien_dos
    beq $t1,3,cien_tre
    beq $t1,4,cien_cua
    beq $t1,5,cien_cin
    beq $t1,6,cien_sei
    beq $t1,7,cien_siet
    beq $t1,8,cien_och
    beq $t1,9,cien_nue

    print_cien:

        cien_cer:
            li $a0,48
            jal put_char
        j end_print_cien

        cien_uno:
            li $a0,49
            jal put_char
        j end_print_cien

        cien_dos:
            li $a0,50
            jal put_char
        j end_print_cien

        cien_tre:
            li $a0,51
            jal put_char
        j end_print_cien

        cien_cua:
            li $a0,52
            jal put_char
        j end_print_cien

        cien_cin:
            li $a0,53
            jal put_char
        j end_print_cien

        cien_sei:
            li $a0,54
            jal put_char
        j end_print_cien

        cien_siet:
            li $a0,55
            jal put_char
        j end_print_cien

        cien_och:
            li $a0,56
            jal put_char
        j end_print_cien

        cien_nue:
            li $a0,57
            jal put_char

    end_print_cien:

    beq $t2,$zero,dies_zer
    beq $t2,1,dies_uno
    beq $t2,2,dies_dos
    beq $t2,3,dies_tre
    beq $t2,4,dies_cua
    beq $t2,5,dies_cin
    beq $t2,6,dies_sei
    beq $t2,7,dies_siet
    beq $t2,8,dies_och
    beq $t2,9,dies_nue

    print_dies:

        dies_zer:
            li $a0,48
            jal put_char
        j end_print_dies

        dies_uno:
            li $a0,49
            jal put_char
            j dies_zer
        j end_print_dies

        dies_dos:
            li $a0,50
            jal put_char
            j dies_zer
        j end_print_dies  

        dies_tre:
            li $a0,51
            jal put_char
            j dies_zer
        j end_print_dies

        dies_cua:
            li $a0,52
            jal put_char
            j dies_zer
        j end_print_dies

        dies_cin:
            li $a0,53
            jal put_char
            j dies_zer
        j end_print_dies

        dies_sei:
            li $a0,54
            jal put_char
            j dies_zer
        j end_print_dies

        dies_siet:
            li $a0,55
            jal put_char
            j dies_zer
        j end_print_dies

        dies_och:
            li $a0,56
            jal put_char
            j dies_zer
        j end_print_dies

        dies_nue:
            li $a0,57
            jal put_char
            j dies_zer
    end_print_dies:
        
    end:
    lw $ra,0($sp)
    addi $sp,$sp,4
    jr $ra