#include <iostream>
#include "main.h"

/*JUSTIFICACIÓN DE LA ELECCION DE STRING -> es un tipo de dato que se maneja de manera sencilla y, al no ser un puntero, 
como en el caso de char *, no necesito liberar la memoria.*/

bool equal_strings(string str1, string str2){
    //Si las cadenas 2 están vacias, son iguales
    if (str1.empty() && str2.empty()) return true;
    
    //Si el largo de las cadenas es distinto, no son iguales
    if (str1.length() != str2.length()) return false;

    //Si el primer caracter de la cadena es igual, se llama a la función con substr (crea un substring sin el primer caracter)
    if (str1[0] == str2[0]) return equal_strings(str1.substr(1), str2.substr(1));
    return false;
}


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
/*CONCLUSIÓN:
En este ultimo punto, elegi usar const char * para que el compilador pueda evaluar las variables en tiempo de compilación (usando string, 
al alocar la memoria en forma dinámica, se evalúa en la ejecución, por lo que en funciones del tipo constexpr no es viable).
Vemos, gracias a chornos, que al evaluar en tiempo de compilación, se tarda por lo menos 10 veces menos en comparar las cadenas, algo lógico al 
realizar todo en la propia compilación. 
*/

int main(){
    string str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";

    const char * char1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    const char * char2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    
    cout << "VERIFICACIÓN EN TIEMPO DE EJECUCIÓN\n" << endl;
    cout << "string1: " << str1 << "\n" << "string2: " << str2 << endl;
    if (equal_strings(str1, str2)){
        cout << "Son iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }

    //USANDO CHRONO
    auto startTime1 = chrono::high_resolution_clock::now();

    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<std::chrono::nanoseconds>(
    endTime1 - startTime1);
    
    cout << "Ver si los 2 strings eran iguales tomó: "<< elapsedTime1.count() << " nanosegundos" << endl;


    //VERIFICACIÓN EN TIEMPO DE COMPILACIÓN
    cout << "\nVERIFICACIÓN EN TIEMPO DE COMPILACIÓN\n" << endl;
    cout << "char1: " << char1 << "\n" << "char2: " << char2 << endl;
    
    if (equal_strings_compilation(char1, char2)){
        cout << "Son iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }

    //USANDO CRHONO
    auto startTime2 = chrono::high_resolution_clock::now();
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>(
    endTime2 - startTime2);
    
    cout << "Ver si los 2 chars eran iguales tomó: "<< elapsedTime2.count() << " nanosegundos" << endl;
}

