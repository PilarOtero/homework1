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
    auto new_node = make_unique<node>();
    new_node->value = value;
    new_node->next = nullptr;       
    
    return new_node;
}

void push_front(unique_ptr<forwardList> &list, int value){
    auto new_head = create_node(value);

    new_head->next = move(list->head);
    list->head = move(new_head);

    list->size ++;
}   

void push_back(unique_ptr<forwardList> &list, int value){
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
    if (position < 0) throw invalid_argument("La posicion debe ser mayor a 0"); 
    
    //La posicion es mayor al tamaño de la lista
    if (position > list->size){
        cout << "La posicion indicada se encuentra fuera del rango de la lista" << endl;
        position = list->size;
    }
    
    //El nodo se inserta como tail
    if (position == 0){
        push_front(list, value);
        return;
    }
    
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
    if (position < 0) throw invalid_argument("La posicion debe ser mayor a 0");
    
    if (position >= list->size){
        cout << "La posicion indicada se encuentra fuera del rango de la lista." << endl;
        position = position - 1;
    }
    if (position == 0){
        list->head = move(list->head->next);
        list->size --;
        return;
    }
    
    auto current = list->head.get();
    
    for (int i = 0; i < position - 1; i ++){
        current = current->next.get();
    }
    current->next = move(current->next->next);
    list->size --;

}

void print_list(unique_ptr<forwardList> &list){
    node * current = list->head.get();

    while (current){
        cout << current->value << "->";
        current = current->next.get();
    }
    cout << "nullptr";
    cout << "\n";
}

int main(){
    unique_ptr<forwardList> list = make_unique<forwardList>();

    cout << "Push front de elementos en la lista " << endl;
    push_front(list, 3);
    push_front(list, 2);
    push_front(list, 1);
    push_front(list, 0);

    print_list(list);

    cout << "Push back de elementos en la lista: " << endl;
    push_back(list, 4);
    push_back(list, 6);
    print_list(list);

    cout << "Insert en la posicion 5" << endl;
    insert(list, 5, 5);
    cout << "Lista despues de insertar el elemento: ";
    print_list(list);

    cout << "Insert en posicion que no existe" << endl;
    insert(list, 7, 10);
    cout << "Lista despues de insertar el elemento: ";
    print_list(list);
    
    cout << "Erase del elemento en la posicion 0" << endl;
    erase(list, 0); 
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);

    cout << "Erase elemento en posicion invalida" << endl;
    erase(list, -1);
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);

    cout << "Erase elemento en posicion que no existe" << endl;
    erase(list, 10);
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);

    return 0;
}
