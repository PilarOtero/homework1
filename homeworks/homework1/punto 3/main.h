#include <memory>

using namespace std;

struct node;
struct forwardList;  

unique_ptr<node> create_node(int value);

void push_front(unique_ptr<forwardList> &list, int value);

void push_back(unique_ptr<forwardList> &list, int value);

void insert(unique_ptr<forwardList> &list, int value, int position);

void erase(unique_ptr<forwardList> &list, int position);    

void print_list(unique_ptr<forwardList> &list);