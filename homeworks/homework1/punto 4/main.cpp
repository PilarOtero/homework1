#include <iostream>
#include <string>

using namespace std;

/*JUSTIFICACION DE LA ELECCION DE STRING -> es un tipo de dato que se maneja de manera sencilla y, al no ser un puntero, como en el caso de char *,
no necesito liberar la memoria.*/

bool equal_strings(string str1, string str2){
    //Si las cadenas 2 estan vacias, son iguales
    if (str1.empty() && str2.empty()) return true;
    
    //Si el largo de las cadenas es distinto, no son iguales
    if (str1.length() != str2.length()) return false;

    //Si el primer caracter de la cadena es igual, se llama a la funcion con substr (crea un substring sin el primer caracter)
    if (str1[0] == str2[0]) return equal_strings(str1.substr(1), str2.substr(1));
    return false;
}

/*Uso const char * paara que el compilador pueda evaluar las variables en iempo de compilacion (usando string, al ser de memoria dinamia, 
se evalua en la ejecucion) */
constexpr int charlength(const char * str){
    if (*str == '\0') return 0;
    return 1 + charlength(str + 1);
}


constexpr bool equal_strings_compilation(const char * char1, const char *char2){
    //CASO BASE: las 2 cadenas estan vacias
    if (*char1 == '\0' && *char2 == '\0') return true;
    
    //Si el largo de las cadenas es distinto
    if (charlength(char1) != charlength(char2)) return false;

    if (*char1 == *char2) return equal_strings_compilation(char1 + 1, char2 + 1);
    return false;

}

int main(){
    string str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str3 = "Hola mundo";

    const char * char1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    const char * char2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    const char * char3 = "Hola mundo";
    
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

    //VERIFICACION EN TIEMPO DE COMPILACION
    cout << "\nVERIFICACION EN TIEMPO DE COMPILACION\n" << endl;
    cout << "char1: " << char1 << "\n" << "char3: " << char3 << endl;
    
    if (equal_strings_compilation(char1, char3)){
        cout << "Son iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }

    cout << "\nchar1: " << char1 << "\n" << "char2: " << char2 << endl;
    if (equal_strings_compilation(char1, char2)){
        cout << "Son iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }

    return 0;
}

