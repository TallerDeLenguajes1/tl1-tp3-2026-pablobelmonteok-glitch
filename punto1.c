#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Nombre_del_alumno[100];

char * v[5];
void MostrasPersonas(char *v[],int tam);
int main(){
 
   for (int i = 0; i < 5; i++){
   printf("Coloque el nombre de la persona: ");
   scanf("%s",Nombre_del_alumno);
   int tamCadena = strlen(Nombre_del_alumno);
   v[i] = (char *)malloc((tamCadena +1) * sizeof(char) );
   strcpy(v[i],Nombre_del_alumno);
   }
   MostrasPersonas(v,5);

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
