#include "functions.cpp"

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

