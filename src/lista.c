#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* crear_lista() {
    //Crea una lista vacía
    Lista *lista = (Lista*)malloc(sizeof(Lista)); //Reserva espacio en memoria para la lista
    lista->head = NULL;
    return lista;
}

void insertar_inicio(Lista *lista, int data) {
    if (lista==NULL) return;

    //Crea un nodo nuevo
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo)); 
    nuevo->data = data;
    nuevo->next = lista->head;
    lista->head = nuevo;
}

void insertar_final(Lista *lista, int data) {
    if (lista==NULL) return;

    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = data;
    nuevo->next = NULL;

    //Si la lista está vacía, el nuevo nodo es la cabeza
    if (lista->head == NULL) {
        lista->head = nuevo;
        return;
    }

    //Recorre toda las lista hasta el final
    Nodo *temp = lista->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nuevo; //Enlaza el último nodo con el nuevo
}

void insertar_posicion(Lista *lista, int data, int posicion) {
    if (lista==NULL) return;

    if (posicion == 0) {
        insertar_inicio(lista, data); //Si se quiere insertar en la posición 0 , se llama a la función de insertar al inicio    
        return;
    }

    //Crea un nodo nuevo
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = data;

    Nodo *temp = lista->head;
    int i = 0;

    //Recorre la lista hasta la posición anterior a la deseada
    while (temp != NULL && i < posicion - 1) {
        temp = temp->next;
        i++;
    }

    //Si la posición es mayor que el tamaño de la lista, se libera el nodo creado
    if (temp == NULL) {
        free(nuevo);
        printf("Posición fuera de rango\n");
        return;
    }

    //Actualiza los punteros next del nodo anterior y del nuevo nodo
    nuevo->next = temp->next;
    temp->next = nuevo;
}

void eliminar(Lista *lista, int data) {
    if (lista==NULL) return;

    Nodo *temp = lista->head;
    Nodo *prev = NULL;

    //Busca el nodo con el valor dado
    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                lista->head = temp->next; //Si el nodo a eliminar es el primero, actualiza la cabeza al siguiente nodo
            } else {
                prev->next = temp->next; //Enlaza el nodo anterior con el siguiente del nodo a eliminar
            }
            free(temp);
            return;
        }

        //Actualiza punteros para avanzar en la lista
        prev = temp;
        temp = temp->next;
    }
}

Nodo* buscar(Lista *lista, int data) {
    if (lista==NULL) return NULL;

    Nodo *temp = lista->head;
    
    //Recorre la lista buscando el valor
    while (temp != NULL) {
        if (temp->data == data)
            return temp; //Devuelve el puntero hacia el nodo encontrado
        temp = temp->next;
    }
    return NULL; //Devuelve NULL si no se encuentra el valor
}

void imprimir_lista(Lista *lista) {
    if (lista==NULL) return;

    Nodo *temp = lista->head;

    //Recorre la lista imprimiendo cada elemento
    printf("[ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void liberar_lista(Lista *lista) {
    if (lista==NULL) return;

    Nodo *temp = lista->head;

    //Recorre la lista liberando cada nodo
    while (temp != NULL) {
        Nodo *sig = temp->next;
        free(temp);
        temp = sig;
    }
    free(lista); //Libera la lista
}
