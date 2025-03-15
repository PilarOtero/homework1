#include <iostream>
#include <string>

using namespace std;

//JUSTIFICACION DE LA ELECCION DE STRING -> es un tipo de dato que se maneja de manera sencilla y, al no ser un puntero, como en el caso de char *, no necesito liberar la memoria.
bool equal_strings(string str1, string str2){
    //Si el largo de las cadenas es distinto, no son iguales
    if (str1.length() != str2.length()) return false;

    //Si las cadenas estan vacias, son iguales
    if (str1.empty() && str2.empty()) return true;

    //Si el primer caracter de la cadena es igual, se llama a la funcion con substr (crea un substring sin el primer caracter)
    if (str1[0] == str2[0]) return equal_strings(str1.substr(1), str2.substr(1));
    return false;
}

int main(){
    string str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str3 = "Hola mundo";
    
    cout << "string1: " << str1 << "\n" << "string2: " << str2 << endl;
    if (equal_strings(str1, str2)){
        cout << "Son iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }

    cout << "\nstring1: " << str1 << "\n" << "string3: " << str3 << endl;
    if (equal_strings(str1, str3)){
        cout << "\nSon iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }
    return 0;
}

