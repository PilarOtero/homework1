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

unique_ptr<node> create_node(int value){
    return make_unique<node>(value, nullptr);
}

void push_front(list * linkedlist, int value){
    unique_ptr<node> new_head = create_node(value);

    new_head->next = move(linkedlist->head);
    linkedlist->head = move(new_head);


    if (!linkedlist->tail){
        linkedlist->tail = new_head.get();
    }
}

void push_back()

