#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos; 
} Cliente;
float calcuarCosto(Producto p);
int main() {
    srand(time(NULL)); // Importante para que los aleatorios cambien
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    char auxNombre[100]; // Buffer temporal para el nombre

    int Cantclientes;

    printf("Cantidad de clientes (max 5): ");
    scanf("%d", &Cantclientes);

    // Validamos que sea entre 1 y 5 como pide la consigna
    if (Cantclientes > 0 && Cantclientes <= 5) {
        // Reservamos memoria para el arreglo de clientes
        Cliente *Clientes = (Cliente *) malloc(Cantclientes * sizeof(Cliente));

        for (int i = 0; i < Cantclientes; i++) {
            Clientes[i].ClienteID = i + 1; // Numerado iterativo
            printf("Cliente ID: ");
            scanf("%d",&Clientes[i].ClienteID);
            
            printf("Nombre del cliente: ");
            scanf("%s", auxNombre);
            // Reservamos memoria para el nombre
            Clientes[i].NombreCliente = (char *) malloc((strlen(auxNombre) + 1) * sizeof(char));
            strcpy(Clientes[i].NombreCliente, auxNombre);

            Clientes[i].CantidadProductosAPedir = (rand() % 5 + 1);
            
            // Reservamos memoria para los productos de este cliente especifico
            Clientes[i].Productos = (Producto *) malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto));
        
            float totalCliente = 0;
            for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++) {
                Clientes[i].Productos[j].ProductoID = j + 1;
                
                Clientes[i].Productos[j].Cantidad = rand() % 10 + 1; 
                
                int indiceAleatorio = rand() % 5;
                Clientes[i].Productos[j].TipoProducto = TiposProductos[indiceAleatorio];
                
                Clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10;
                
                printf("  > Producto %d: %s , Cant: %d , Precio: %.2f\n", 
                        Clientes[i].Productos[j].ProductoID, 
                        Clientes[i].Productos[j].TipoProducto, 
                        Clientes[i].Productos[j].Cantidad, 
                        Clientes[i].Productos[j].PrecioUnitario);
                   float costo= calcuarCosto(Clientes[i].Productos[j]);
               printf("Costo : %f\n", costo); 
                totalCliente += costo;
            }
            printf("Total a pagar: %.2f\n",totalCliente);
        }
        
        // Al final, liberar la memoria (buena practica para el TP)
        for(int i = 0; i < Cantclientes; i++){
            free(Clientes[i].NombreCliente);
            free(Clientes[i].Productos);
        }
        free(Clientes);

    } else {
        printf("Cantidad invalida de clientes. Debe ser entre 1 y 5.\n");
    }

    return 0;
}

float calcuarCosto(Producto p){
return p.Cantidad * p.PrecioUnitario;
}