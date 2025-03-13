#include <iostream>
#include <memory>

using namespace std;

struct node {
    int value;
    unique_ptr<node> * next;
};

struct list {
    unique_ptr<node> * head;
    unique_ptr<node> * tail;    
};

node * create_node(int value){
    node * created_node = new node;
    created_node->next = nullptr;
    created_node->value = value;
    
    return created_node;
}

void push_front(list * linkedlist, int value){
    node * head = create_node(value);

    head->next = linkedlist->head;
    linkedlist->head = head;


    if (!linkedlist->tail){
        linkedlist->tail = head;
    }
}

void push_back()

