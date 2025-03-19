#include <iostream>
#include "main.h"

int charlength(char * str){
    if (*str == '\0') return 0;
    return 1 + charlength(str + 1);
}

bool equal_chars(char * char1, char * char2){
    //Si las cadenas 2 están vacias, son iguales
    if (char1 == '\0' && char2 == '\0') return true;
    
    //Si el largo de las cadenas es distinto, no son iguales
    if (charlength(char1) != charlength(char2)) return false;

    //Si el primer caracter de la cadena es igual, se llama a la función con substr (crea un substring sin el primer caracter)
    if (*char1 == *char2) return equal_chars(char1 + 1, char2 + 1);
    return false;
}


//VERIFICACIÓN EN TIEMPO DE COMPILACION
constexpr int charlength_compilation(const char * str){
    if (*str == '\0') return 0;
    return 1 + charlength(str + 1);
}

constexpr bool equal_chars_compilation(const char * char1, const char *char2){
    //CASO BASE: las 2 cadenas estan vacías
    if (*char1 == '\0' && *char2 == '\0') return true;
    
    //Si el largo de las cadenas es distinto
    if (charlength_compilation(char1) != charlength_compilation(char2)) return false;

    if (*char1 == *char2) return equal_chars_compilation(char1 + 1, char2 + 1);
    return false;

}

/*CONCLUSIÓN:
En este ultimo punto, elegi usar const char * para que el compilador pueda evaluar las variables en tiempo de compilación (usando string, 
al alocar la memoria en forma dinámica, se evalúa en la ejecución, por lo que en funciones del tipo constexpr no es viable).
Vemos, gracias a chornos, que al evaluar en tiempo de compilación, se tarda por lo menos 10 veces menos en comparar las cadenas, algo lógico al 
realizar todo en la propia compilación. 
*/
