#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Nombre_del_alumno[100];

char * v[5];
void MostrasPersonas(char *v[],int tam);
void BuscarNombre(int id,char*v[]);
int BuscarNombre(char clave[],char*v[]);
int main(){
 
   for (int i = 0; i < 5; i++){
   printf("Coloque el nombre de la persona: ");
   scanf("%s",Nombre_del_alumno);
   int tamCadena = strlen(Nombre_del_alumno);
   v[i] = (char *)malloc((tamCadena +1) * sizeof(char) );
   strcpy(v[i],Nombre_del_alumno);
   }
   MostrasPersonas(v,5);
   int id=0;
    printf("\nColocar id de la persona : ");
    scanf("%d",&id);

   BuscarNombre(id,v);
   char clave[50];
   printf("Ingresa la palabra a buscar:");
   scanf("%s",clave);
  int idEncontrado;  
  idEncontrado = BuscarNombre(clave,v);
printf("El id encontrado es : %d",idEncontrado);

   for (int j = 0; j < 5; j++)
   {
     free(v[j]);
   }
   
return 0;
}
void MostrasPersonas(char *v[],int tam){

   for (int j = 0; j < tam; j++)
   {
     printf("Nombres: %s\n",v[j]);
   }
}
void BuscarNombre(int id,char* v[]){

    if (id >= 0 &&  id < 5)
    {
                  printf("Nombre encontrado: %s\n",v[id]);       
     }else{
        printf("valor no encontrado");
     }

}
int BuscarNombre(char clave[],char*v[]){

for (int i = 0; i < 5; i++) {
        // strstr busca "clave" dentro de v[i]
        // Si la encuentra, devuelve un puntero (distinto de NULL)
        if (strstr(v[i], clave) != NULL) {
            return i; // Retorna el primer índice donde hubo coincidencia
        }
    }
    
    return -1; // Si recorrió todo y no encontró nada
}
