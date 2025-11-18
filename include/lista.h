#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    int data;
    struct Nodo *next;
} Nodo;

typedef struct Lista {
    Nodo *head;
} Lista;

// Funciones para las listas
Lista* crear_lista();
void insertar_inicio(Lista *lista, int data);
void insertar_final(Lista *lista, int data);
void insertar_posicion(Lista *lista, int data, int posicion);

void eliminar(Lista *lista, int data);
Nodo* buscar(Lista *lista, int data);

void imprimir_lista(Lista *lista);
void liberar_lista(Lista *lista);

#endif
