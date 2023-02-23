﻿ /*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Fecha : 2013-2020
 */

#include "grafo.h"

GRAFO::~GRAFO()
{
    if(!LS.empty())
        LS.clear();
    if(!LP.empty())
        LP.clear();
    m = 0;
    n = 0;
    delete this;
 
    
}




void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    if(!LS.empty())
        LS.clear();
    if(!LP.empty())
        LP.clear();
    m = 0;
    n = 0;
    
    
    cout <<m<<endl;
    ifstream textfile; //definimos el objeto textfile como ifstream
    ElementoLista  dummy;
    int a,b;

    textfile.open(nombrefichero);  // abrimos el fichero para lectura
    if (textfile.is_open())
        textfile >> (unsigned & ) n >> (unsigned& )m >> (unsigned &) dirigido;
    else{
        errorapertura=1;
        return;
    }
   //Guardamos el espacio de memoria para los sucesores y predecesores.
    LS.resize(n);
    if (dirigido == 0)
        LP.resize(n); 
    

    while(textfile >> a >> b){
        dummy.j = a-1;
        dummy.c = b-1;
        LS[dummy.j].push_back(dummy);
        
        if (dirigido== 0){
            LP[dummy.c].push_back(dummy);
    // GRAFO(nombrefichero,&errorapertura);
        }
    }
}

void GRAFO::Info_Grafo()
{
    if (dirigido == 1)
    {
        cout << "Grafo dirigido ";
    }
    else
    {
        cout << "Grafo no dirigido ";
    };
    cout << " | nodos " << n << " | ";
    if (dirigido == 1)
    {
        cout << " arcos ";
    }
    else
    {
        cout << "aristas ";
    };
    cout << m << " " << endl;
}

unsigned GRAFO::Es_dirigido()
{
	return dirigido;
}

void Mostrar_Lista(vector<LA_nodo> L)
{
};

void GRAFO :: Mostrar_Listas (int l)
{
    ElementoLista dummy;
    if (dirigido==1){
    dummy.j =1;
        for(int i=0;i<n;i++){
            if(dirigido==1){
                cout<<"Sucesores del ";
            
                cout<<dummy.j <<":";
                for (int k =0; k < LS[i].size(); k++){
                    dummy= LS[i][k];
                    cout<< " "<< dummy.c +1<< " ";
                    }       
            cout<< endl;       
            dummy.j +=2;
            }
        }
    }



    if(dirigido==0){
        for (int match =0; match <n; match++){
            cout<< endl;
            cout<<"Adyacentes de "<< match + 1<< ":  ";
            for(int i=0;i<n;i++){
                
                for (int k =0; k < LS[i].size(); k++){
                    dummy= LS[i][k];
                    if (dummy.j == match)
                        cout<<  dummy.c +1<< " ";
                    if (dummy.c == match){
                        cout<<dummy.j +1 <<" ";
                    }       
                
               
                
                }
            }
            
        }
    }
    cout<<endl;

};

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
	visitado[i] = true;
    cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++){
        //cout<< LS[i].size();
       // cout<< LS[i][j].j << " "<< LS[i][j].c << endl;
        if (visitado[(LS[i][j].c)]  == false)
            dfs((LS[i][j].c), visitado);
    }
}

void GRAFO::ComponentesConexas()
{
    vector<bool> marca;
    marca.resize(n);
    int conex=0, i;
    for (i=0;i<n;i++)
        marca[i]=false;
    i=0;
    while(i<n){
        if(marca[i]==false){
            conex +=1;
            cout<<endl<<"componente conexa numero"<< conex<<endl;
            dfs(i,marca);
            cout<< endl;
        }
        i+=1;
    }

}

void GRAFO::ListaPredecesores() 
{
    
    ElementoLista dummy;
   
        for (int match =0; match <n; match++){
            cout<< endl;
            cout<<"Predecesores de "<< match + 1<< ":  ";
            for(int i=0;i<n;i++){
                
                for (int k =0; k < LS[i].size(); k++){
               dummy= LS[i][k];
                if (dummy.c == match){
                   cout<<dummy.j +1 <<"  ";
                }
                
                }
            }
            
        }
     cout<<endl;

}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
    ifstream textfile; //definimos el objeto textfile como ifstream
    ElementoLista  dummy;
    int a,b;

    textfile.open(nombrefichero);  // abrimos el fichero para lectura
    if (textfile.is_open())
        textfile >> (unsigned & ) n >> (unsigned& )m >> (unsigned &) dirigido;
    else{
        errorapertura=1;
        return;
    }
   //Guardamos el espacio de memoria para los sucesores y predecesores.
    LS.resize(n);
    if (dirigido == 0)
        LP.resize(n); 
    

    while(textfile >> a >> b){
        dummy.j = a-1;
        dummy.c = b-1;
        LS[dummy.j].push_back(dummy);
        
        if (dirigido== 1){
            LP[dummy.c].push_back(dummy);
        }
    } 
    

}




