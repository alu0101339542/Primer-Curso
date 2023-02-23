#Programa que lee dos números flotantes por teclado.
# Los almacena en memoria
#Llama a una función a la que se le pasa los dos flotantes por parámetros y calcula la suma
# La suma se imprimer por pantalla

 .data
msgvalores: .asciiz "Introduzca los valores de a,b (separados por retorno de carro): \n"

a:      .float 0.0
be:      .float 0.0
result: .word 0

   
   
   
    .text
suma:
add.s $f4, $f12, $f13
cvt.w.s $f5, $f4
mfc1 $s0, $f5
move $v0, $s0
jr $ra


main:
#Leemos los números por teclado
    la	$a0,msgvalores
    li	$v0,4
	syscall

    li $v0,6
    syscall
    swc1 $f0, a

    li $v0,6
    syscall
    swc1 $f0, be

    #Los gardamos en el registro que le pasaremos al funcion

    lwc1 $f12, a
    lwc1 $f13, be

    jal suma
    
    move $a0, $v0
    li	$v0,1
	syscall

    li $v0,10