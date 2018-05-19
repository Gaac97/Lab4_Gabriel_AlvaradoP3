#include <iostream>
#include <string.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
void Ejercicio1();
int** Ejecicio2();
void Ejercicio3(char**,int);
void llenar_matriz(int,char,char**);
void acomodar_mensaje(char,char);
char** CrearMatrizL(int);
int** CrearMatriz(int);
char** llenarMatriz(int,int**,int);
int*** CrearMatrizTri(int);
void PrintM(char**,int);
void imprimirMatriz(int**,int);
int UltimaMatriz(int,char,char**);
char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void FreeMatriz(char**&,int&);


int main(){
int opcion=0;
int size=5;
int*** Tri=NULL;
char** Matriz3=NULL;
while(opcion!=4){
	cout<<"Ingrese ejercicio"<<endl;
	cout <<"1.Eercicio 1"<<endl;
	cout<< "2.Ejercicio 2"<< endl;
	cout<< "3.Ejercicio 3" <<endl;
	cout <<"4.Liberar memoria"<<endl;
	cout<< " Salir 4"<<endl;
	
	cin>>opcion;

	if(opcion==1){
		//Ejercicio1();

	}

	if(opcion==2){
		//Ejercicio2();
		

		}
	if (opcion==3){

		Ejercicio3(Matriz3, size);

				

	}

	if(opcion==4){
	FreeMatriz(Matriz3,size);
	}

	}
return 0;
}//Fin


void imprimirMatriz(int**matriz, int size){
        for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        if (matriz[i][j]<10){
                                cout<<"0" << matriz[i][j];
                        }else{
                                cout<<"[ "<< matriz[i][j]<< "] ";
                        }
                }
                cout<<endl;
        }

}

void PrintM(char** matriz,int size){
	for(int i=0; i<size; i++){
              for(int j=0; j<size; j++){

                    if (matriz[i][j]<10){
                          cout<<"0" << matriz[i][j];
                     }else{
                           cout<<"[ "<< matriz[i][j]<< "] ";
                          }
                  }
                  cout<<endl;
         }

	

}

void FreeMatriz(char**& matriz, int& size){
        //Liberar arreglo de ints
        for(int i = 0; i<size;i++){
                delete[]matriz[i];
                matriz[i] = NULL;
        }
        //Liberar arreglo de apuntadores a int
        delete[] matriz;
        matriz = NULL;
        size = 0;
}

int UltimaLetra(int size,char letra, char** matriz){

	for(int i=0;i<size;i++){
		for(int j=0; j<size; j++){
			if(letra == matriz[i][j]){

			return 1;
			}
		
		}
	
	}
	return -1;

}

char** llenar_matriz(int size,char clave[],char**matriz){
    int fila=0;
    int columna=0;
    int aux;
    for(int i=0;i<strlen(clave);i++){
         aux=UltimaLetra(size,clave[i],matriz);
         if(aux==-1&&clave[i]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
                        matriz[fila][columna]=clave[i];
                        columna++;
         }
    }

        for(int j=0;j<strlen(alf);j++){
        aux=UltimaLetra(size,alf[j],matriz);
        if(aux==-1&&alf[j]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
        	      }
                        matriz[fila][columna]=alf[j];
                        columna++;
 	      }
	}

return matriz;
}

void acomodar_mensaje (char l2[],char l[]){
        int j=0;
        for(int i=0;i<strlen(l);i++){
                if(l[i]!=32){
                   l2[j]=l[i];
                   j++;
                }
        }
        l2[j]='\0';
        //cout<<m2<<endl;

        int i=0;
        j=1;
        while(j<=strlen(l2)){
                if(l2[i]==l2[j]){
                        for(int k=strlen(l2)+1;k>j;k--){
                                l2[k]=l2[k-1];
                        }
                        l2[j]='x';
                }
                i=i+2;
                j=j+2;
        }

        if(strlen(l2)%2!=0){
                l2[strlen(l2)+1]='\0';
                l2[strlen(l2)]='x';
        }
      
}


int** llenarMatriz(int** matriz, int size){
        srand(time(NULL));
        for(int i=0; i<size;i++){
                for(int j=0; j<size;j++){
                        int random = 10 + rand()%(11-1);

                        matriz[i][j]= random;
                }
        }
    return matriz;
}


int** CrearMatriz(int size){
int** arr = new int*[size];

        for(int i = 0 ; i<size;i++){
                 arr[i]= new int [size];

        }

        for(int j=0; j<size;j++){
                for(int z =0; z<size;z++){

                arr[j][z] = 0;
        }
}

}


char** CrearMatrizL(int size){

char** arr = new char*[size];


        for(int i = 0 ; i<size;i++){
                 arr[i]= new char [size];

        }

        for(int j=0; j<size;j++){
                for(int z=0; z<size;z++){
                arr[j][z] = '0';


	}
    }
return arr;
}

void Ejercicio3(char** matriz,int size){
 char m[100];
 char clave[100];
        cout<<"Ingrese mensaje a cifrar:"<<endl;
        cin.getline(m,100);
	cin.getline(m,100);
        cout<<"Ingrese clave:"<<endl;
        cin.getline(clave,100);
 	matriz = CrearMatrizL(size);


	 llenar_matriz(size,clave,matriz);
	 

        char m2[100];
        acomodar_mensaje(m2,m);

	PrintM(matriz,size);


        int i=0;
        int j=1;
        while(j<=strlen(m2)){
                int fila1,fila2,columna1,columna2;
                if(m2[i]=='j'){
                        m2[i]='i';
                }
                if(m2[j]=='j'){
                        m2[j]='i';
                }
                for(int x=0;x<size;x++){
			for(int y=0;y<size;y++){

                                if(m2[i]==matriz[x][y]){
                                        fila1=x;
                                        columna1=y;
                                }
                                if(m2[j]==matriz[x][y]){
                                        fila2=x;
                                        columna2=y;
                                }
                        }
                }
                if(fila1==fila2){
                        m2[i]=matriz[fila1][(columna1+1)%size];
                        m2[j]=matriz[fila1][(columna2+1)%size];
                }
                else if(columna1==columna2){
                        m2[i]=matriz[(fila1+1)%size][columna1];
                        m2[j]=matriz[(fila2+1)%size][columna1];
                }
                else{
                        m2[i]=matriz[fila1][columna2];
                        m2[j]=matriz[fila2][columna1];
                }
                i=i+2;
                j=j+2;
        }
        cout<<"El mensaje cifrado es:";
        for(int i=0;i<strlen(m2);i++){
                cout<<m2[i];
                if(i%2!=0){
                        cout<<" ";
                }
        }
        cout<<endl<<endl;

}




