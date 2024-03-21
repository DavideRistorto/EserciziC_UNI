x = (x - 2) + y
if (x < y)
    x = x + 1
else
    y = y + 1


addi t0, t0, -2
add t0, t0, t1
bge t0, t1, ELSE  # Branch if t0 < t1
addi t0, t0, 1   # If branch not taken, execute this
beq zero, zero, ENDIF  # Jump to ENDIF
ELSE:
addi t1, t1, 1   # Else block
ENDIF:
