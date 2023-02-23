# PRACTICA 1. PRINCIPIOS DE COMPUTADORES






# la directiva .text informa al compilador del comienzo del codigo
			.text
main:
			# Las siguientes tres instrucciones imprimen por consola la cadena etiquetada como titulo
			la $a0,titulo
			li $v0,4
			syscall

			# Las siguientes tres instrucciones imprimen por consola la cadena etiquetada como nombre
			la $a0,alumno
			li $v0,4
			syscall

			lw $t0,num1  # carga en el registro $t0 el valor etiquetado como num1
			lw $t1,num2  # carga en el registro $t1 el valor etiquetado como num2
#			lw $t3,num4  # carga en el registro $t1 el valor etiquetado como num2
			add $t2,$t0,$t1  # realiza la siguiente operacion $t2 = $t0 + $t1

			add $t4, $t2, $t3 # realiza la siguiente operacion $t4 = $t2 + $t3

			# Las siguientes instrucciones representan un bucle d
			# en cada iteracion se resta una unidad al registro $t3
			li $t6,555
buclewhile: beq $t6,$zero,fin_buclewhile
				 addi $t3,-1
				 addi $t6,-1
				 b buclewhile

fin_buclewhile:


			# Las siguientes tres instrucciones imprimen el valor del registro $t3
			move $a0,$t3
			li $v0,1
			syscall


			# las siguientes dos instrucciones terminan el programa y devuelven el control al S.O.
			li	$v0,10
			syscall

			# la directiva .data informa al compilador del comienzo de la definicion de datos

			.data

num1:			.word	37
num2:		    	.word	49
num3:			.word	0x1A45F44E
real1:			.float  2,183
doble1:			.double	17530552,23
titulo:			.asciiz "PRINCIPIO DE COMPUTADORES. Practica 1.\n"
alumno:			.asciiz "alu0101339542@ull.edu.es, Daniel Perez Lozano\n"
