#include <iostream>
#include <memory>

using namespace std;

struct node {
    int value;
    unique_ptr<node> next;
};

struct linkedList {
    unique_ptr<node> head;   
    int size;
};

unique_ptr<node> create_node(int value){
    return make_unique<node>(value, nullptr);
}

void push_front(linkedList * list, int value){
    unique_ptr<node> new_head = create_node(value);

    new_head->next = move(list->head);
    list->head = move(new_head);

    list->size++;
}   

void push_back(linkedList * list, int value){
    unique_ptr<node> new_tail = create_node(value);
   
    if (! list->head) list->head = move(new_tail);
    else{
        node * current = list->head.get();

        while (current->next){
            current = current->next.get();  
        }
        //Defino el nuevo nodo como el nodo final de la lista
        current->next = move(new_tail);
    }
    list->size++;
}

void insert(linkedList * list, int value, int position){
    unique_ptr<node> new_node = create_node(value);

    //La posicion es mayor al tamaño de la lista
    if (position > list->size){
        cout << "La posicion indicada se encunetra por fuera del rango de la lista:";
        push_back(list, value);
    }
    //El nodo se inserta como tail
    else if (position == 0){
        push_front(list, value);
    }
    //El nodo se inserta como head
    else if (position == list->size){
        push_back(list, value);
    }
    else{
        
    }

}


