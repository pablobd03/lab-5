#include <stdio.h>
#include "lista.h"

int main() {
    //Crea la lista con algunos datos ya ingresados
    Lista *lista = crear_lista();
    insertar_inicio(lista, 10);
    insertar_inicio(lista, 20);
    printf("Lista creada:\n");
    imprimir_lista(lista);

    //Inserta datos al inicio
    printf("\nInsertando al inicio:\n");
    insertar_inicio(lista, 30);
    imprimir_lista(lista);

    //Inserta datos al final
    printf("\nInsertando al final dato 40 y 50:\n");
    insertar_final(lista, 40);
    insertar_final(lista, 50);
    imprimir_lista(lista);

    //Inserta dato en una posición específica
    printf("\nInsertando el dato 85 en posición 2:\n");
    insertar_posicion(lista, 85, 2);
    imprimir_lista(lista);

    //Busca dato existente en la lista
    printf("\nBuscando elemento con dato 40:\n");
    Nodo *encontrado = buscar(lista, 40);
    if (encontrado)
        printf("Encontrado: %d\n", encontrado->data);
    else
        printf("No encontrado\n");

    //Busca dato no existente en la lista
    printf("\nBuscando elemento con dato 99:\n");
    encontrado = buscar(lista, 99);
    if (encontrado)
        printf("Encontrado: %d\n", encontrado->data);
    else
        printf("No encontrado\n");

    //Elimina un dato de la lista
    printf("\nEliminando el elemento 20:\n");
    eliminar(lista, 20);
    imprimir_lista(lista);

    //Libera la memoria utilizada por la lista  
    liberar_lista(lista);
    return 0;
}
