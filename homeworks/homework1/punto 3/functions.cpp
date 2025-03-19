#include <iostream>
#include <memory>
#include "main.h"

struct node {
    int value;
    unique_ptr<node> next;
};

struct forwardList {
    unique_ptr<node> head;   
    int size;
};

unique_ptr<node> create_node(int value){
    //Crea un nodo con el valor indicad
    auto new_node = make_unique<node>();
    new_node->value = value;
    new_node->next = nullptr;       
    
    return new_node;
}

void push_front(unique_ptr<forwardList> &list, int value){
    //Agrega al nodo al principio de la lista
    auto new_head = create_node(value);

    new_head->next = move(list->head);
    list->head = move(new_head);

    list->size ++;
}   

void push_back(unique_ptr<forwardList> &list, int value){
    //Agrega al nodo al final de la lista (como tail)
    auto new_tail = create_node(value);
   
    if (! list->head) list->head = move(new_tail);
    else{
        auto current = list->head.get();

        while (current->next){
            current = current->next.get();  
        }
        //Defino el nuevo nodo como el ultimo de la lista
        current->next = move(new_tail);
    }
    list->size ++;
}

void insert(unique_ptr<forwardList> &list, int value, int position){
    if (position < 0){
        cout << "La posición debe ser mayor a 0" << endl;
        return;
    }

    //La posición es mayor al tamaño de la lista
    if (position >= list->size){
        position = list->size; 
    }
    
    //El nodo se inserta como tail
    if (position == 0){
        push_front(list, value);
        return;
    }
    
    //El nodo se inserta en la posición indicada (para eso itero la lista)
    auto current = list->head.get();
    
    for (int i = 0; i < position - 1; i ++){
        current = current->next.get();
    }

    auto new_node = create_node(value);
    new_node->next = move(current->next);
    current->next = move(new_node);
    
    list->size ++;
}


void erase(unique_ptr<forwardList> &list, int position){
    //Elimina el valor de la lista ubicado en la posición indicada
    if (position < 0){
        cout << "La posición debe ser mayor a 0" << endl;
        return;
    }

    //La posición es mayor al tamaño de la lista, elimino el ultimo elemento
    if (position >= list->size){
        cout << "La posición indicada se encuentra fuera del rango de la lista." << endl;
        position = list->size - 1;
    }

    //Elimino el primer elemento
    if (position == 0){
        list->head = move(list->head->next);
        list->size --;
        return;
    }

    //Recorro la lista hasta llegar a la posición indicada y elimino
    auto current = list->head.get();
    
    for (int i = 0; i < position - 1; i ++){
        current = current->next.get();
    }

    current->next = move(current->next->next);
    list->size --;
}

void print_list(unique_ptr<forwardList> &list){
    //Recorre la lista para imprimir los valores (unidos con un "->")
    node * current = list->head.get();

    while (current){
        cout << current->value << "->";
        current = current->next.get();
    }
    cout << "nullptr";
    cout << "\n";
}