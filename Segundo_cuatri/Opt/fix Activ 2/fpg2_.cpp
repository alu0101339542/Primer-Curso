 /*
 *  PG1.CPP - Actividad I de Optimiza!cion.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Fecha : Marzo-2020
 */

#include <string.h>
#include "grafo.h"

void clrscr() //No funciona en todos los sistemas: opcional
{
	system("clear");
}


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{   
    if (dirigido ==0){
        cout << "c. cargar grafo desde fichero"<<endl;
        cout << "i. mostrar la informacion basica del grafo "<<endl;
        cout << "a. Mostrar la lista de adyascentes del grafo"<<endl;
        cout << "o. Mostrar componentes conexas del grafo"<<endl;
        cout << "k. Mostrar árbol generador mínimo coste"<<endl;
        cout << "q. Finalizar programa"<<endl;
    }
    if (dirigido  == 1){
        cout << "c. cargar grafo desde fichero"<<endl;
        cout << "i. mostrar la información básica del grafo "<<endl;
        cout << "s. Mostrar la lista de sucesores del grafo"<<endl;
        cout << "p. Mostrar la lista de predecesores del grafo"<<endl;
        cout << "q. Finalizar programa"<<endl;
    }
    cin >> opcion;
    
    
};


// El principal es simplemente un gestor de menu, diferenciando acciones para grafo dirigido y para no dirigido
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;

	clrscr();
    //Cargamos por defecto el fichero que se pasa como argumento del ejecutable
	if (argc > 1)
    {
		cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
		clrscr();
    }
    
    GRAFO G(nombrefichero, error_apertura);
    cout << "despues de actualizar" <<endl;
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero: revisa nombre y formato" << endl;
    }
    else
    {
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
                case 'c':
                cout<<"Escribe el nombre del nuevo fichero: "<<endl;
                cin>>nombrefichero;
                G.actualizar(nombrefichero, error_apertura);
                //Situar aquí el código de gestión de las opciones, según sea el grafo dirigido o no dirigido
                break;
                case 'i':
                    G.Info_Grafo();
                break;
                
                case 'p':
                    G.ListaPredecesores();
                break;
                case 'a':
                    G.Mostrar_Listas(G.Es_dirigido());
                break;
                case 'o':
                    G.ComponentesConexas();
                break;
                case 'k':
                    G.Kruskal();
                break;
                case 's':
                    G.Mostrar_Listas(G.Es_dirigido());
                   
                break;
            }
        }
        while (opcion != 'q');
    };
    cout << "Fin del programa";
	return(0);
};
