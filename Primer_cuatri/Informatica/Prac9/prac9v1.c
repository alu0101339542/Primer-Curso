#include <stdio.h>
int read_matrix(char *filename, int A[][3]){
    FILE *fnin;
    int i,j;
    fnin =fopen(filename,"r+");
    if (fnin == NULL){
        printf("Ha habido un error al encontrar el fichero \n");
        return -1;
    }
    for (i=0;  i<3 ;i++){
        if(fscanf(fnin, "%d %d %d\n", &A[i][0],&A[i][1],&A[i][2]) ==EOF){
            printf("Hemos llegado al final del fichero\n");
            return -1;
        }
    }
}
  
int printmatrix(int m[][3]){
    int i,j;
       for (i=0; i<3 ; i++){
           for (j=0; j<3 ;j++){
             printf("%d\t", m[i][j]);
            }
        printf("\n");
        }

}   
int transpose(int m[][3], int mt[][3]){
    int i,j;
       for (i=0; i<3 ;i++){
           for (j=0; j<3 ;j++){
             mt[i][j]=m[j][i];
            
            }
       
        }
        
}
int rowmax(int m[][3], int row){
    int j, rowmax=m[row][0];

    for(j=1; j<3 ;j++){
        if(m[row][j]>rowmax)
            rowmax=m[row][j];
    }
    return rowmax;
}
float average(int m[][3]){
    int mdiag;
    mdiag=(m[0][2]+m[1][1]+m[2][0])/3;
    return mdiag;
}
int product(int mA[][3], int mB[][3],int mP[][3]){
    int i,j,k;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            mP[i][j]=0;
            for(k=0;k<3;k++){
                mP[i][j]+= mA[i][k]*mB[k][j];
            }
        }
    } 
    return 0;
}
int menu(){
    int option;
    printf("Selecciona el numero de lo que desees ejecutar: \n");
    printf("--------------------------------------------\n");
    printf("1. Imprimir matrices A y B:\n");
    printf("2. Imprimir matrices traspuesta de A y B:\n");
    printf("3. Imprimir maximo en una fila de las matrices A y B:\n");
    printf("4. Imprimir media de la diagonal secundaria de A y B:\n");
    printf("5. Imprimir producto AxB y BxA:\n");
    printf("6. Salir del programa\n");
    printf("--------------------------------------------\n");
    scanf("%d",&option);
    return option;
}

int main (void){
    int option;
    int mA[3][3], mB[3][3], mP[3][3], i, j, mt[3][3],row, prod, max;
    float mdiag;

    read_matrix("MatrizA.txt",mA);
    read_matrix("MatrizB.txt",mB);
    option=menu();
    switch(option){
        case 1:
            printf("\n");
            printmatrix(mA);
            printf("\n");
            printmatrix(mB);
            break;
        case 2:
            printf("\n");
            transpose(mA, mt);
            printmatrix(mt);
            printf("\n");
            transpose(mB, mt);
            printmatrix(mt);
            break;
        case 3:
            printf("Que fila quieres");
            scanf("%d",&row);
            max= rowmax(mA,row);
            printf("El maximo de la fila %d es %d de A\n",row,max );
            max= rowmax(mB,row);
            printf("El maximo de la fila %d es %d de B\n",row,max );
            break;
        case 4:
            mdiag= average(mA);
            printf("La media de la segunda diagonal de A es: %f\n",mdiag);
            mdiag= average(mB);
            printf("La media de la segunda diagonal de B es: %f\n",mdiag);
            break;
        case 5:
            prod= product(mA,mB,mP);
            printf("AxB=: \n");
            printmatrix(mP);
            prod= product(mB,mA,mP);
            printf("BxA=: \n");
            printmatrix(mP);
            break;
        case 6:
            return -1;



    }
}

/*int main(void) {
    int mA[3][3], mB[3][3], mP[3][3], i, j, mt[3][3],row;
    read_matrix("MatrizA.txt",mA);
    printmatrix(mA);
    printf("\n");
    read_matrix("MatrizB.txt",mB);
    printmatrix(mB);
    printf("\n");
    transpose(mA, mt);
    row=0;
    int max= rowmax(mA,row);
    printf("El maximo de la fila %d es %d",row,max );
    float mdiag= average(mA);
    printf("La media de la segunda diagonal es: %f\n",mdiag);
    int prod= product(mA,mB,mP);
    printmatrix(mP);
    }
*/
