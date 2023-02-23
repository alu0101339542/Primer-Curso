#include <iostream>
#int main(void) {
#	float a,b,c,d;
#	std::cout << "Evaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s]" << std::endl;
#	std::cout << "Introduzca los valores de a,b,c y d (separados por retorno de carro): " << std::endl;
#	std::cin >> a;
#	std::cin >> b;
#	std::cin >> c;
#	std::cin >> d;
#	int r,s;
#	do {
#		std::cout << "Introduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro):" << std::endl;
#		std::cin >> r;
#		std::cin >> s;
#} while (r > s);
#	float f;
#	int x;
#	for ( x = r ; x <= s ; x++) {
#		f = a*x*x*x + b*x*x + c*x + d;
#		std::cout << "f(" << x << ") = " << f << std::endl;
#	}			
#}







    .data
titulo: 	.asciiz	"Evaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s] \n"
msgvalores: .asciiz "Introduzca los valores de a,b,c y d (separados por retorno de carro): \n"
msgrango:   .asciiz "Introduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro): \n" 
msgfunc1:   .asciiz "\n f("
msgfunc2:   .asciiz ") = "
a:      .word 0
be:      .word 0
c:      .word 0
d:      .word 0
result: .word 0

   
   
   
    .text
main:
#Leemos las frases
    la	$a0,titulo
    li	$v0,4
	syscall
    la	$a0,msgvalores
    li	$v0,4
	syscall
#Leemos por pantalla los valores
    li $v0,6
    syscall
    swc1 $f0,a

    li $v0,6
    syscall
    swc1 $f0,be

    li $v0,6
    syscall
    swc1 $f0,c

    li $v0,6
    syscall
    swc1 $f0,d
do:
 #Leemos la frase
    la	$a0,msgrango
    li	$v0,4
	syscall
 #Cargamos los valores de r y s
    li	$v0,5
	syscall
    move $s0, $v0
    li	$v0,5
	syscall
    move $s1, $v0
    bgt $s0,$s1, do

#Cargamos los valores de x y f y pasamos a flotante s
    addi $s2,$s0,0
   
    mtc1 $s1,$f23
    cvt.s.w $f23,$f23
    li.s $f4, 1.0
    


for:
    mtc1 $s2,$f22
    cvt.s.w $f22,$f22

    lwc1 $f5,a
    lwc1 $f6,be
    lwc1 $f7,c
    lwc1 $f8,d
    c.le.s $f22,$f23
    bc1f endfor
 #multiplicamos a
    mul.s $f3, $f22, $f22 
    mul.s $f3, $f22,$f3
    mul.s $f3, $f3,$f5
 #multiplicamos b
    mul.s $f5, $f22, $f22 
    mul.s $f5, $f5,$f6
  #multiplicamos c
    mul.s $f6, $f22, $f7
 #Hacemos la suma de los 4
    add.s $f21, $f3,$f5
    add.s $f21, $f21,$f6
    add.s $f21, $f21,$f8
 #Imprimimos los resultados
    swc1 $f21,result
    la	$a0,msgfunc1
    li	$v0,4
    syscall
    #Guardamos el valor de x nuevamente como entero
    cvt.w.s $f20,$f22
    mfc1 $s2,$f20
    move $a0,$s2
    li	$v0,1
    syscall

    la	$a0,msgfunc2
    li	$v0,4
    syscall
    l.s	$f12,result
    li	$v0,2
    syscall
 
    addi $s2,$s2,1
    b for
endfor:
   
   li $v0,10
   syscall