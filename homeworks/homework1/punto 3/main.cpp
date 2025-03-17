#include "main.h"
#include "functions.cpp"

int main(){
    //Creo la lista
    unique_ptr<forwardList> list = make_unique<forwardList>();

    //Tests de las funciones
    cout << "PUSH FRONT DE ELEMENTOS" << endl;
    push_front(list, 3);
    push_front(list, 2);
    push_front(list, 1);
    push_front(list, 0);
    print_list(list);
    cout << "\n" << endl;

    cout << "PUSH BACK DE ELEMENTOS " << endl;
    push_back(list, 4);
    push_back(list, 6);
    print_list(list);
    cout << "\n" << endl;

    cout << "INSERT EN POSICIÓN 5" << endl;
    insert(list, 5, 5);
    cout << "Lista despues de insertar el elemento: ";
    print_list(list);
    cout << "\n" << endl;

    cout << "INSERT EN POSICIÓN QUE NO EXISTE" << endl;
    insert(list, 7, 10);
    cout << "Lista despues de insertar el elemento: ";
    print_list(list);
    cout << "\n" << endl;
    
    cout << "ERASE DEL ELEMENTO EN LA POSICIÓN 0" << endl;
    erase(list, 0); 
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);
    cout << "\n" << endl;

    cout << "ERASE DE ELEMENTO EN POSICIÓN INVALIDA" << endl;
    erase(list, -1);
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);
    cout << "\n" << endl;

    cout << "ERASE EN POSICIÓN MAYOR AL LARGO DE LA LISTA" << endl;
    erase(list, 10);
    cout << "Lista despues de borrar el elemento: ";
    print_list(list);

    return 0;
}
