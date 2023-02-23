

	.data		# directiva que indica la zona de datos
titulo: 	.asciiz	"Encuentra el numero de veces que aparece una cifra en un entero.\n"
msgcifra:	.asciiz	"Introduzca la cifra a buscar (numero de 0 a 9): "
msgnumero:	.asciiz	"Introduzca un entero positivo donde se realizara la busqueda: "
msgbusqueda1:	.asciiz	"Buscando cifra "
msgbusqueda2:	.asciiz	" en el numero "
msgresultado1:	.asciiz	" ...\nLa cifra buscada se encontro en "
msgresultado2:	.asciiz	" ocasiones\n"
cifra:		.word 0
encontrado:	.word 0

	.text		# directiva que indica la zona de código
main:
	# IMPRIME EL TITULO POR CONSOLA
	#    std::cout << "Encuentra el número de veces que aparece una cifra en un entero." << std::endl;
	la	$a0,titulo
	li	$v0,4
	syscall


	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    do {
	#        std::cout << "Introduzca la cifra a buscar (numero de 0 a 9): ";
	#        std::cin >> cifra;
	#    } while ((cifra < 0) || (cifra > 9));
	# NOTA: utiliza $s0 para almacenar la cifra
do1:
	la	$a0, msgcifra
	li	$v0,4
	syscall
	
	li	$v0,5
	syscall
	move $s0, $v0										
	li $s3,10
	slti $s1, $s0, 0
	slt $s2, $s3, $s0
	or $s3, $s1,$s2 
	beq $s3,1,do1



	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    do {
	#        std::cout << "Introduzca un entero positivo donde se realizará la búsqueda: ";
	#        std::cin >> numero;
	#    } while (numero < 0);
	# NOTA: utiliza $s1 para almacenar el numero donde buscar la cifra
do2:
	la	$a0, msgnumero
	li	$v0,4
	syscall

	li	$v0,5
	syscall
	move $s1, $v0

	blt $s1,0,do2

	#IMPRIME MENSAJE DE BUSQUEDA POR CONSOLA, suponiendo que en $s0 esta la cifra a buscar
	# y en $s1 el numero en el que buscar la cifra
	la	$a0,msgbusqueda1
	li	$v0,4
	syscall

	move	$a0,$s0
	li	$v0,1
	syscall

	la	$a0,msgbusqueda2
	li	$v0,4
	syscall

	move	$a0,$s1
	li	$v0,1
	syscall

	# INTRODUCE AQUI EL CODIGO EQUIVALENTE A:
	#    int encontrado = 0;
	#    do {
	#        int resto = numero % 10;
	#        if (resto == cifra) encontrado++;
	#        numero = numero / 10;
	#    } while (numero != 0);
	# NOTA: utiliza $s2 para almacenar el contador encontrado
	lw $s2, encontrado
do3:
	li $s3, 0
	rem $s3,$s1,10
	divu $s1,$s1,10
	bne $s3,$s0,noen
	addi $s2, $s2,1
noen:
	bne $s3,$zero,do3



	#IMPRIME EL RESULTADO POR CONSOLA, suponiendo que en $s2 tenemos el contador de econtrados
	la	$a0,msgresultado1
	li	$v0,4
	syscall

	move	$a0,$s2
	li	$v0,1
	syscall

	la	$a0,msgresultado2
	li	$v0,4
	syscall

	# las siguientes dos instrucciones finalizan el programa
	li $v0,10
	syscall
 
