# include <iostream>
# int main(void) {
#	const int nrows = 4, ncols = 3;
#	int matrix[nrows][ncols] = {{11,12,13},{21,22,23},{31,32,33},{41,42,43}};
	
#	std::cout << "Practica 4. Trabajando con Matrices\n";
#	int selection;
#	do {
#		int i,j;
#		for (i = 0; i < nrows ; i++) {
#			for (j = 0; j < ncols ; j++)
#				std::cout << matrix[i][j] << " ";
#			std::cout << std::endl;
#		}
		
#		do {
#			std::cout << "Elija opcion <0> Salir, <1> invertir fila, <2> invertir columna: ";
#			std::cin >> selection;
#		} while (selection < 0 || selection > 2);
		
#		
#			if (selection == 1) {
#				int f,aux;
#				do {
#					std::cout << e f"Seleccionila [" << 1 << "," << nrows << "]: ";
#					std::cin >> f;
#				} while (f < 1 || f > nrows);
#				f--;
#				for (j = 0; j <= (ncols-1) / 2; j++) {
#					aux = matrix[f][j];
#					matrix[f][j] = matrix[f][ncols-1-j];
#					matrix[f][ncols-1-j] = aux;
#				}				
#			} else {  # selection es 2
#				int c,aux;
#				do {
#					std::cout << "Seleccione columna [" << 1 << "," << ncols << "]: ";
#					std::cin >> c;
#				} while ( c < 1 || c > ncols);
#				c--;
#				for (i = 0; i <= (nrows-1) / 2; i++) {
#					aux = matrix[i][c];
#					matrix[i][c] = matrix[nrows-1-i][c];
#					matrix[nrows-1-i][c] = aux;
#				}	
#			}
#		}		
#	} while (selection != 0);
#	return(0);
#}




    .data

titulo:     .asciiz "Practica 4. Trabajando con Matrices\n"
msgread:    .asciiz "Elija opcion <1> Matriz de teclado <2> matriz estandar: "
msgnrow:    .asciiz "Introduce el numero de filas: "
msgncol:    .asciiz "Introduce el numero de columnas: "
msgopcion:  .asciiz "Elija opcion <0> Salir, <1> invertir fila, <2> invertir columna: "
msgfila:    .asciiz "Seleccione fila [1  , "
msgfila2:   .asciiz "] : "  
msgcol:     .asciiz "Seleccione columna [ 1 ,"

msgspace:   .asciiz " "
msgendl:   .asciiz "\n "

nrows:      .word 4
ncols:      .word 3



matrix:    .word 11, 12, 13
            .word 21, 22, 23
            .word 31, 32, 33
            .word 41, 42, 43

newmatrix: .space 400

    .text
main:

    la	$a0,titulo
    li	$v0,4
	syscall

##  s1 --> ncols
##  s2 --> nrows
##  s3 --> nrows*ncols
##  s4 --> i (index)
##  a1 --> Base address of matrix (or newmatrix)

# read matrix from standard input
menu0: 
    la	$a0,msgread
    li	$v0,4
	syscall
    #Ponemos la opción por teclado
    li $v0,5
    syscall
    move $s0, $v0
    beq $s0, 2,origmatrix
    blt $s0,1, menu0
    bgt $s0,2, menu0
    # Read number of rows and number of columns
    la	$a0,msgnrow
    li	$v0,4
	syscall
    #Ponemos la opción por teclado
    li $v0,5
    syscall
    move $s2, $v0
    la	$a0,msgncol
    li	$v0,4
	syscall
    #Ponemos la opción por teclado
    li $v0,5
    syscall
    move $s1, $v0

    mul $s3, $s1, $s2 #Filas por columnas 
    li $s4, 0 # Valor de i
formatread:
    bge $s4,$s3,printmat
    sll $t1, $s4,2   # i*4
    li $v0,5
    syscall
    move $t2, $v0
    sw $t2,newmatrix($t1)      
    addi $s4,$s4,1
    b formatread    

origmatrix:
    lw $s1, ncols
    lw $s2, nrows
    
    li $s4, 0 # Valor de i
    mul $s3, $s1, $s2 #Filas por columnas 
    la $a1, matrix

    la	$a0,msgspace
    li	$v0,4
	syscall
    b bucle
    
printmat:
    la $a1, newmatrix
    li $s4, 0
    
bucle:
    
    addi $s0, $s4,1
    rem $s0, $s0,$s1 
#    la $a1, matrix
    sll $s5, $s4,2
#    lw $a0, matrix($s5)
    add $s5, $a1,$s5
    lw $a0, 0($s5)

    li $v0, 1
    syscall 
    la	$a0,msgspace
    li	$v0,4
	syscall
    bne $s0,$zero,notendl
    la	$a0,msgendl
    li	$v0,4
    syscall
notendl:
    addi $s4, $s4,1
    blt $s4, $s3, bucle

do1:
    #Se imprime el menu
    la	$a0,msgopcion 
    li	$v0,4
	syscall
    #Ponemos la opción por teclado
    li $v0,5
    syscall
    move $s0, $v0
    beq $s0, $zero,exit
    blt $s0,$zero, do1
    bgt $s0,2, do1
    beq $s0, 2, do3# Si elegimos la opcion 2 salta a do3
#Opcion Filas
do2:
    la	$a0,msgfila # Print selcet row option
    li	$v0,4
    syscall
    move $a0, $s2
    li $v0,1
    syscall

    la	$a0,msgfila2 
    li	$v0,4
    syscall
    li $v0,5    # Pedimos numero de fila por teclado
    syscall
    move $t3, $v0 #t3 es el numero de fila "f"
    #Comprobamos que f esta en el rango
    blt $t3,1, do2
    bgt $t3, $s2, do2
    addi $t3,$t3,-1 

    li $s3,0 #Valor de aux
    li $s4,0#Valor de j

    addi $s7,$s1, -1
    divu $s7, $s7, 2 #(ncols-1) / 2
    
forcols:
    bgt $s4,$s7,endforcols
    mul $s5, $t3,$s1
    add $s5, $s4,$s5 #(f-1)*ncols+j Para calcular la posicion
    mul $s5, $s5, 4
    #lw $s3, matrix($s5) #Cargamos la matriz con el offset indicado anteriormente, guardandolo en el aux
    add $s5, $a1,$s5
    lw $s3, 0($s5)

    mul $s6, $t3,$s1 #(f-1)*ncols
    neg $t0,$s4
    #mul $t0,$s4,-1 
    add $s6, $t0,$s6 #(f-1)*ncols-j
    addi $s6, $s6, -1 # (f-1)*ncols-j-1
    add $s6, $s6, $s1
    mul $s6, $s6, 4
    add $s6, $a1,$s6
    lw $t1, 0($s6)
 #   lw $t1, matrix($s6) 
    sw $t1, 0($s5)
 #   sw $t1,matrix($s5)#Movemos el elemento de la matriz con el offset $s6, en $s5
    sw $s3, 0($s6)
#    sw $s3,matrix($s6) #Movemos el aux a 
    addi $s4,$s4,1
    b forcols
endforcols:
    move $s4, $zero
    mul $s3, $s1, $s2 #Filas por columnas
    b bucle
    

    
    

do3:
    #Imprimimos el mensaje
    la	$a0,msgcol 
    li	$v0,4
    syscall
    move $a0, $s1
    li $v0,1
    syscall
    la	$a0,msgfila2 
    li	$v0,4
    syscall

    li $v0,5
    syscall
    move $s0, $v0 #s0 es el numero de columna "c"
#    lw $s1, ncols
    #Comprobamos que c esta en el rango
    blt $s0,1, do3
    bgt $s0, $s1, do3
    
    addi $s0,$s0,-1 #C-1
    li $s4,0 #valor de i

    move $t0,$s2
 #   lw $t0, nrows
    addi $s7,$t0, -1
    divu $s7, $s7, 2 #(nrows-1) / 2

    #### Registros
    ##  t0 -->  nrows
    ##  s4 -->  i
    ##  s7 --> fin bucle (nrows-1)/2
    ##  s1 --> ncols
    ##  s0 --> c-1
    ##  s5 --> aux
    ##  s6 --> aux2
forow:
    bgt $s4,$s7,endforcols
    
    mul $s3, $s4, $s1
    add $s3, $s3, $s0
    sll $s3, $s3,2      #Filas por columnas#Calculamos el offset  (i*ncol+(c-1))*4
    #mul $s3, $s1, $s2 

    add $s3, $a1,$s3
    lw $s5, 0($s3)
 #   lw $s5, matrix($s3) #Cargamos en s5 (aux) el primer elemento
    
    #Creamos el offset del que guardaremos en la posión de ahora el auxiliar
    #lw $s4, nrows
    addi $t1, $s2, -1
 #   addi $t1, $t0, -1
    neg $t2, $s4
    
    add $t3, $t1, $t2   #nrow-1-i
    mul $t3, $t3, $s1
    add $t3,$t3,$s0
    sll $t3, $t3,2       #((nrow-1)-i)*ncols +(c-1)*4

    add $t3, $a1,$t3
    lw $s6, 0($t3)
#    lw $s6, matrix($t3)
    sw $s5, 0($t3)
#    sw $s5, matrix($t3)   #guardo la ultima fila en la primera
    sw $s6, 0($s3)
#    sw $s6,matrix($s3)  #Movemos el aux a la ultima posicion   
    add $s4, $s4,1 
    b forow                                                    

endforow:
    move $s4, $zero
    mul $s3, $s1, $s2 #Filas por columnas
    b bucle
     

   
exit:
    li $v0, 10
    syscall
    