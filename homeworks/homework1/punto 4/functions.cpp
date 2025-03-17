#include <iostream>
#include "main.h"

/*JUSTIFICACIÓN DE LA ELECCIÓN DE STRING -> es un tipo de dato que se maneja de manera sencilla y, al no ser un puntero, 
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


//VERIFICACIÓN EN TIEMPO DE COMPILACION
constexpr int charlength(const char * str){
    if (*str == '\0') return 0;
    return 1 + charlength(str + 1);
}

constexpr bool equal_strings_compilation(const char * char1, const char *char2){
    //CASO BASE: las 2 cadenas estan vacías
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
