#Examen

 .data
titulo: 	.asciiz	"Introduzca el numero a buscar \n"
msgnoenc: 	.asciiz	"El numero no se ha encontrado \n"
#a:      .word 0


  
   
    .text
encuentra:
#a0 contiene la direccion de memoria donde comienza el vector de enteros
#a1 xontiene el numero a buscar
#a2 Tamaño de vector
li $t2,0 #Valor de la i en cada ite valdra 4 mas
move $t1, $a1
li $t3,0 #Valor del indice
bucle:
    lw $t0, $t2($a0)#valor del numero de la direccion de memoria que se le pasa
    
    bne $t0, $t1,noeq
    move $v1, $t3 #Valor de retorno del indice
    move $v2, $t0 #retornamos el numero
    jr $ra #Encontramos el valor y volvemos

noeq:
    addi $t2, $t2,4
    addi $t3, $t3,1
    bne $t2, $a2, bucle#Hariamos esto hasta que el vector este vacio

#si no encontramos el valor :
addi $v1,$v1,-1
jr $ra


SolicitaYBusca:


li $v0,5
syscall
move $a0,$v0

#Guardamos el ra anterior
addi $sp, $sp, -4
sw $ra,0($sp)
jal encuentra
#Te devuelve un entero de encuentra
move $s0, $v1 #indice del numero
move $s1, $v2 #Valor del numero
#Hacemos un pop para volver al main
lw $ra, 0($sp)
addi $sp, $sp,4
jr $ra #volvemos al main


main:


jal SolicitaYBusca
#Termina el programa
li $v0,10
syscall
