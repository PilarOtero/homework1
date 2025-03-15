#include <iostream>
#include <memory>

using namespace std;

struct node {
    int value;
    unique_ptr<node> next;
};

struct forwardList {
    unique_ptr<node> head;   
    int size;
};

unique_ptr<node> create_node(int value){
    unique_ptr<node> new_node = make_unique<node>();
    new_node->value = value;
    new_node->next = nullptr;       
    
    return new_node;
}

void push_front(forwardList * list, int value){
    unique_ptr<node> new_head = create_node(value);

    new_head->next = move(list->head);
    list->head = move(new_head);

    list->size ++;
}   

void push_back(forwardList * list, int value){
    unique_ptr<node> new_tail = create_node(value);
   
    if (! list->head) list->head = move(new_tail);
    else{
        node * current = list->head.get();

        while (current->next){
            current = current->next.get();  
        }
        //Defino el nuevo nodo como el ultimo de la lista
        current->next = move(new_tail);
    }
    list->size ++;
}

void insert(forwardList * list, int value, int position){
    unique_ptr<node> new_node = create_node(value);

    //La posicion es mayor al tamaño de la lista
    if (position > list->size){
        cout << "La posicion indicada se encuentra fuera del rango de la lista:" << endl;
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
        node * current = list->head.get();
        int current_pos = 0;

        while (current_pos < position - 1){
            current = current->next.get();
            current_pos++;
        }

        new_node->next = move(current->next);
        current->next = move(new_node);
        list->size ++;
    }
}

void erase(forwardList * list, int position){
    if (position > list->size){
        cout << "La posicion indicada se encuentra fuera del rango de la lista:" << endl;
        position = list->size - 1;
    }
    if (position == 0){
        list->head = move(list->head->next);
    }
    else {
        node * current = list->head.get();
        int current_pos = 0;

        while (current_pos < position - 1){
            current = current->next.get();
            current_pos++;
        }
        current->next = move(current->next->next);
    }
    list->size --;
}

void print_list(forwardList * list){
    node * current = list->head.get();

    while (current){
        cout << current->value << "->";
        current = current->next.get();
    }
    cout << "nullptr";
    cout << "\n";
}

