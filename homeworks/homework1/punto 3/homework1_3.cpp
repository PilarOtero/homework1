#include <iostream>
#include <memory>

using namespace std;

struct node {
    int value;
    unique_ptr<node> * next;
};

struct linkedList {
    unique_ptr<node> * head;
    unique_ptr<node> * tail;    
    int size;
};

unique_ptr<node> create_node(int value){
    return make_unique<node>(value, nullptr);
}

void push_front(linkedList * list, int value){
    unique_ptr<node> new_head = create_node(value);

    new_head->next = move(list->head);
    list->head = std::move(new_head);


    if (! list->tail){
        list->tail = new_head.get();
    }
    
    list->size++;
}   

void push_back(linkedList * list, int value){
    unique_ptr<node> new_tail = create_node(value);

    if (list->tail){
        list->tail->next = move(new_tail);
        list->tail = list->tail->next.get();

    } else{
        list->head = move(new_tail);
        list->tail = list->head.get();
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


