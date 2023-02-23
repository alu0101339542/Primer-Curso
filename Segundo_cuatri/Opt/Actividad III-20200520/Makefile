#declare the variable
#By doing this you wont need to change for example g++ every time, you just change it once in the variable CC for instance
CC=g++

#son opciones de compilacion diferentes 
CFLAGS=-c -g -Wall #En vez de ser por ejenmplo g++ -c main.cpp ahora es g++ -c -g -Wall main.cpp Importante añadir el -g para poder depurar el programa

all: hello
	
grafo: main.o grafo.o pg3.o
	$(CC) grafo_.cpp  pg3_.cpp -o grafo
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
grafo.o: grafo_.cpp
	$(CC) $(CFLAGS) grafo_.cpp
pg3.o: pg3_.cpp
	$(CC) $(CFLAGS) pg3_.cpp
clean:
	 rm -rf *o grafo

