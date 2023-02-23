
	.data
cadena: 	.asciiz "Practica 5 de Principios de Computadores. Quedate en casa!!\n"
cadena2:	.asciiz "roma tibi subito m otibus ibit amor"

msgread:    .asciiz "Introduzca 1 para la version recursiva y 2 para la iterativa: \n"
cadtiene:	.asciiz " tiene "
cadcarac:	.asciiz " caracteres.\n"
cadespal:	.asciiz "\n Es palíndroma.\n\n"
cadnoespal:	.asciiz "No es palíndroma.\n\n"
cadena6:	.asciiz "roma"#
	.text


strlen:  # numero de caracteres que tiene una cadena sin considerar el '\0'
		 # la cadena tiene que estar terminada en '\0'
		 # $a0 tiene la direccion de la cadena
		 # $v0 devuelve el numero de caracteres

		 # INTRODUCE AQUÍ EL CÓDIGO DE LA FUNCIÓN strlen SIN CAMBIAR LOS ARGUMENTOS
        li $t1, 0
begstrlen:
        lb $t0, 0($a0)
        beq $t0, 0, endstrlen 
        addi $t1, $t1, 1
        addi $a0, $a0,1
        b begstrlen
endstrlen:
        move $v0,$t1
        jr $ra


		 
reverse_i:  # funcion que da la vuelta a una cadena
			# $a0 cadena a la que hay que dar la vuelta
			# $a1 numero de caracternes que tiene la cadena
			# $v0 1 Si es palíndroma 0 si no lo es
			
			# INTRODUCE AQUÍ EL CÓDIGO DE LA FUNCIÓN reverse_i SIN CAMBIAR LOS ARGUMENTOS

            ### $t0-> valor de i
            ### $t1-> n/2
			###	$t2-> Caracter del final
            ### $t3-> n-1
            ### $t4-> $a0+(n-1)-i
            ### $t5-> (n-1)-i


            divu $t1, $a1,2
            addi $t3, $a1, -1
            move $t0, $zero
            li $v0,1

            empiezabucle:
                        bgt $t0,$t1,finbucle #Condicion para entrar en bucle
                        sub $t5, $t3,$t0
                        add $t4, $t5,$a0 #direccion equivalente al final. a0 +n -1 -i
                        lb $t2, 0($t4) #Guardamos en t2 el caracter de la segunda mitad
                        add $s0, $a0, $t0
                        lb $s1, 0($s0) # Guardo en s1 el caracter de a0 +i
                        sb $s1, 0($t4) 
                        sb $t2, 0($s0) #Guardo en S0 el valor de t2(a0 +n -1 -i)
                    
                        beq $t2, $s1, nopalin
                        move $v0, $zero
            nopalin:
                        addi $t0, $t0,1
                        b empiezabucle       

            finbucle:
            jr $ra

reverse_r:  # funcion que da la vuelta a una cadena
			# $a0 cadena a la que hay que dar la vuelta
			# $a1 numero de caracternes que tiene la cadena
			# $v0 1 Si es palíndroma 0 si no lo es
			
			# INTRODUCE AQUÍ EL CÓDIGO DE LA FUNCIÓN reverse_r SIN CAMBIAR LOS ARGUMENTOS
            
            #li $s0,1 #Se inicializa a 1 el palindrome
            addi $sp, $sp, -8 #Hago un push
            sw $ra, 4($sp)
            sw $a1, 0($sp)
            ble $a1, $zero, revex
            addi $a1, $a1, -1 
            add $t0, $a0, $a1 #n-1 + a0posc del caract a evaluar de la segunda mitad
            lb $t1, 0($t0)
            lb $t2, 0($a0)
            sb $t1, 0($a0)
            sb $t2, 0($t0)

            beq $t1, $t2, palin
                        move $s0, $zero
            
palin:            
            addi $a1, $a1, -1 #(n-1)-1
            addi $a0, $a0, 1 #a0+1
            jal reverse_r
            lw $ra, 4($sp) #Hago un pop
            lw $a1, 0($sp)
            addi $sp, $sp, 8
            and $s0, $v0, $s0


revex:
            move $v0, $s0 #$v0 guardo si es palíndroma
            
            jr $ra

main:
			# INTRODUCE AQUÍ EL CÓDIGO DE LA FUNCIÓN main QUE REPRODUZCA LA SALIDA COMO EL GUIÓN
			# INVOCANDO A LA FUNCIÓN strlen DESPUÉS DE CADA MODIFICACIÓN DE LAS CADENAS
menu0:
            la	$a0,msgread
            li	$v0,4
	        syscall
            #Ponemos la opción por teclado
            li $v0,5
            syscall
            move $t7, $v0
            blt $t7,1, menu0
            bgt $t7,2, menu0




            la	$a0,cadena
            li	$v0,4
	        syscall
            la	$a0,cadena2
            li	$v0,4
	        syscall
            la	$a0,cadtiene
            li	$v0,4
	        syscall

            la $a0, cadena2
            jal strlen
            move $a0,$v0
            move $s0, $a0
            li	$v0,1
	        syscall
            
        
            la	$a0,cadcarac
            li	$v0,4
	        syscall

            la $a0, cadena2 # Parametro 1 direccion de la cadena
            move $a1, $s0 # 2 parametro n caracteres
            li $s0,1
            beq $t7,1,recur
            jal reverse_i
            b comun
        recur:  
            jal reverse_r
        comun:
            la $a0, cadena2
            move $s1, $v0

            li	$v0,4
            syscall

            bne $s1,$zero, nopal
            la	$a0,cadnoespal
            li	$v0,4
	        syscall
            b fin

        nopal:
            la	$a0,cadespal
            li	$v0,4
	        syscall
        fin:
            li $v0,10
            syscall
            