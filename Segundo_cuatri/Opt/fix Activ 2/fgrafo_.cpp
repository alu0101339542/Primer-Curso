 /*
 *  GRAFO.CPP - Implementaci�n de la clase GRAFOS
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
    int a,b,co;

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
    

    while(textfile >> a >> b>>co){
        dummy.j = b;
        dummy.c = co;
        LS[a-1].push_back(dummy);
        
        if (dirigido== 1){
            LP[dummy.j-1].push_back(dummy);
    // GRAFO(nombrefichero,&errorapertura);
        }
    }
    

}

unsigned GRAFO::Es_dirigido()
{
    return dirigido;
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

void Mostrar_Lista(vector<LA_nodo> L)
{


}


void GRAFO :: Mostrar_Listas (int l)
{
     ElementoLista dummy;
    if (dirigido==1){
        for(int i=0;i<n;i++){
                cout<<"Sucesores|costes del nodo";
            
                cout<< i+1 <<":";
                for (int k =0; k < LS[i].size(); k++){
                    dummy= LS[i][k];
                    cout<< " "<< dummy.j <<"|"<< dummy.c<< " ";
                    }       
            cout<< endl;       
    
            
        }
    }



    if(dirigido==0){
        for (int match =0; match <n; match++){
            cout<< endl;
            cout<<"Adyacentes|costes de "<< match + 1<< ":  ";
            for(int i=0;i<n;i++){
                if( i == match){
                    for(int k =0; k < LS[i].size(); k++){
                        dummy= LS[i][k];
                        cout<<dummy.j<<"|"<<dummy.c<<"           ";
                    }
                    continue;
                }
                for (int k =0; k < LS[i].size(); k++){
                    dummy= LS[i][k];
                    if (dummy.j == match +1)
                        cout<<  i+1 <<"|"<< dummy.c<< "           ";
                        
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
    for (unsigned j = 0; j < LS[i].size(); ++j){
        //cout<<LS[i][j].j<<endl;
        if (visitado [(LS[i][j].j)-1] == false)
            dfs ((LS[i][j].j)-1, visitado);
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
  /*  for(i=0;i<n;i++){
        for (unsigned j=0; j< LS[i].size();j++){
            cout << "-->" << LS[i][j].j ;
        }
        cout << endl;
    }
    */
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
//Método para ordenar las aristas según su peso de menor a mayor.
//Los argumentos del método son el vector de aristas y k siendo el último elemento
// ordenado
void GRAFO::swap(vector<AristaPesada> &aristas, int k){
    int t, minimo, indx;
    AristaPesada dummy;
    minimo= aristas[k].peso;
    indx = k;
    for(int i =k; i<m; i++){
        if(aristas[i].peso<minimo){
            minimo = aristas[i].peso;
            indx=i;
        }
    }
    
    //Guardamos en una estruc aux la arista de menor peso 
    dummy.extremo1= aristas[indx].extremo1;
    dummy.extremo2= aristas[indx].extremo2;
    dummy.peso= aristas[indx].peso;

    aristas[indx].extremo1= aristas[k].extremo1;
    aristas[indx].extremo2= aristas[k].extremo2;
    aristas[indx].peso= aristas[k].peso;

    aristas[k].extremo1= dummy.extremo1;
    aristas[k].extremo2= dummy.extremo2;
    aristas[k].peso= dummy.peso;
}

void GRAFO::Kruskal()
{
    vector <AristaPesada> Aristas;

    /*Usaremos la busqueda del menor en cada momento, pues es el mejor para Kruskal que no exige tener todas las aristas ordenadas*/
    /*Cargamos todas las aristas de la lista de adyacencia*/

    Aristas.resize(m);

    unsigned k = 0;
    for (unsigned i = 0; i<n; i++){
        for (unsigned j=0; j<LS[i].size();j++){
            if (i < LS[i][j].j) {
                Aristas[k].extremo1 = i+1;
                Aristas[k].extremo2 = LS[i][j].j;
                Aristas[k++].peso = LS[i][j].c;
                }
        }
    };
    /*for (int i=0;i<m;i++){
        cout<<Aristas[i].extremo1<<", "<<Aristas[i].extremo2<< ", "<<Aristas[i].peso<< endl;
    }*/
    /*Inicializamos el indice a la cabeza del vector*/
    unsigned head = 0;
    AristaPesada AristaDummy; //Para los intercambios en la ordenacion parcial

    /*Inicializamos el contador de aristas en la soluci�n*/
    unsigned a = 0;

    /*Inicializamos el peso de la solucion*/
    unsigned pesoMST = 0;

    /*Inicializamos el registro de componentes conexas: cada nodo est� en su compomente conexa*/
    vector <unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0;q < n; q++){
        Raiz[q]=q+1;
    };
    /*Comenzamos Kruskal*/
     vector <AristaPesada> Tree;
     
     int kill;
    do {
        /* Implementamos el algoritmo de Kruskal */
           swap(Aristas, head);
           //cout<<"AHEad"<<Aristas[head].extremo1<< ", "<<Aristas[head].extremo2<<", "<< Aristas[head].peso<<endl;
           
           cout<<endl;
           //cout<<"AHEad"<<Aristas[head].extremo1<< ", "<<Aristas[head].extremo2<<", "<< Aristas[head].peso<<endl;
           if(Raiz[(Aristas[head].extremo1)-1]!= Raiz[(Aristas[head].extremo2)-1]){
                Tree.push_back(Aristas[head]);
                //cout <<"Tree:" << Tree[a].extremo1 <<" " << Tree[a].extremo2<<endl;
                kill= Raiz[(Aristas[head].extremo1)-1];
         //       cout<<"kil"<<kill;
                for(int j=0; j< n; j++){
                    if(Raiz[j]==kill){
                        Raiz[j]= Raiz[(Aristas[head].extremo2)-1];
                    }
                }
            a++;
           }
           /*for(int i=0; i<n; i++){
               cout<<" "<<Raiz[i];
           }*/
           head++;
        } while ((a < (n-1)) && (head < m));

        if (a == (n - 1)){
            cout<<"Aristas que forman parte de la solución: ";
            for (int i =0; i<Tree.size();i++){
                cout<< "["<<Tree[i].extremo1<<","<< Tree[i].extremo2<<"]"<<",   ";
                pesoMST+= Tree[i].peso;
            }
            cout << "El peso del arbol generador de minimo coste es " << pesoMST << endl;

        }
        else {
            for (int i =0; i<Tree.size();i++){
                pesoMST+= Tree[i].peso;
            }
            cout << "El grafo no es conexo, y el bosque generador de minimo coste tiene peso " << pesoMST << endl;
        };

}

void GRAFO::ListaPredecesores()
{
    ElementoLista dummy;
   
    for (int match =0; match <n; match++){
        cout<< endl;
        cout<<"Predecesores | coste  de "<< match + 1<< ":  ";
        for(int i=0;i<n;i++){
                
            for (int k =0; k < LS[i].size(); k++){
               dummy= LS[i][k];
                if (dummy.j == match+1){
                   cout<< i+1 << "|"<< dummy.c<< " ";;
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
    int a,b,co;
    textfile.open(nombrefichero);  // abrimos el fichero para lectura
    if (textfile.is_open())
        textfile >> (unsigned & ) n >> (unsigned& )m >> (unsigned& )dirigido;
    else{
        errorapertura=1;
        return;
    }

   //Guardamos el espacio de memoria para los sucesores y predecesores.
    LS.resize(n);
    if (dirigido == 1)
        LP.resize(n); 
    

    while(textfile >> a >> b >> co){
        dummy.j = b;
        dummy.c = co;
        LS[a-1].push_back(dummy);
        
        if (dirigido== 1){
            LP[dummy.j-1].push_back(dummy);
        }
    } 
    


}





