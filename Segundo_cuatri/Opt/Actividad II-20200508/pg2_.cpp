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
    
    cout << "c. cargar grafo desde fichero"<<endl;
    cout << "i. mostrar la informacion basica del grafo "<<endl;
    cout << "a. Mostrar la lista de adyascentes del grafo"<<endl;
    cout << "o. Mostrar componentes conexas del grafo"<<endl;
    cout << "k. Mostrar árbol generador mínimo coste"<<endl;
    cout << "q. Finalizar programa"<<endl;
    
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

            }
        }
        while (opcion != 'q');
    };
    cout << "Fin del programa";
	return(0);
};
