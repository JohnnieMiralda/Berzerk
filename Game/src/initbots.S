.globl initbots
.extern bots


initbots:
    addi $sp,$sp,-4
    sw $ra,0($sp)



    beq $a0,1,bot_0
    beq $a0,2,bot_1
    beq $a0,3,bot_2
    beq $a0,4,bot_3
    beq $a0,5,bot_4
    beq $a0,6,bot_5
    beq $a0,7,bot_6
    beq $a0,8,bot_7

    la $t0, bots //cargo la info
    bot_7:
        la $t0, bots 
        lw $t2, 112($t0)
        li $t1,50
        sw $t1, 112($t0)

        lw $t2, 116($t0)
        li $t1,15
        sw $t1, 116($t0)

        lw $t2, 120($t0)
        li $t1,1
        sb $t1, 120($t0)
    bot_6:
        la $t0, bots 
        lw $t2, 96($t0)
        li $t1,70
        sw $t1, 96($t0)

        lw $t2, 100($t0)
        li $t1,28
        sw $t1, 100($t0)

        lw $t2, 104($t0)
        li $t1,1
        sb $t1, 104($t0)
    bot_5:
        la $t0, bots 
        lw $t2, 80($t0)
        li $t1,30
        sw $t1, 80($t0)

        lw $t2, 84($t0)
        li $t1,17
        sw $t1, 84($t0)

        lw $t2, 88($t0)
        li $t1,1
        sb $t1, 88($t0)
    bot_4:
        la $t0, bots 
        lw $t2, 64($t0)
        li $t1,28
        sw $t1, 0($t0)

        lw $t2, 68($t0)
        li $t1,20
        sw $t1, 68($t0)

        lw $t2, 72($t0)
        li $t1,1
        sb $t1, 72($t0)
    bot_3:
        la $t0, bots 
        lw $t2, 48($t0)
        li $t1,30
        sw $t1, 0($t0)

        lw $t2, 52($t0)
        li $t1,8
        sw $t1, 52($t0)

        lw $t2, 56($t0)
        li $t1,1
        sb $t1, 56($t0)
    bot_2:
        la $t0, bots 
        lw $t2, 32($t0)
        li $t1, 50
        sw $t1, 32($t0)

        lw $t2, 36($t0)
        li $t1,18
        sw $t1, 36($t0)

        lw $t2, 40($t0)
        li $t1,1
        sb $t1, 40($t0)
    bot_1:
        la $t0, bots 
        lw $t2, 16($t0)
        li $t1,20
        sw $t1, 16($t0)

        lw $t2, 20($t0)
        li $t1,25
        sw $t1, 20($t0)

        lw $t2, 24($t0)
        li $t1,1
        sb $t1, 24($t0)
    bot_0:
        la $t0, bots //cargo la info
        lw $t2, 0($t0)
        li $t1,10
        sw $t1, 0($t0)

        lw $t2, 4($t0)
        li $t1,20
        sw $t1, 4($t0)

        lw $t2, 8($t0)
        li $t1,1
        sb $t1, 8($t0)

    end:
    lw $ra,0($sp)
    addi $sp,$sp,4
    jr $ra

    //aaaabbbbc___dddd,aaaa