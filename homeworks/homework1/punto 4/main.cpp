#include "functions.cpp"

int main(){
    string str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    string str2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";

    char * char1 = new char[str1.length()];
    char * char2 = new char[str2.length()];

    for (int i = 0; i < str1.length(); i ++){
        char1[i] = str1[i];
        char2[i] = str2[i];
    }

    constexpr const char * char3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    constexpr const char * char4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed porttitor nunc quis metus vulputate hendrerit. ";
    
    cout << "VERIFICACIÓN EN TIEMPO DE EJECUCIÓN\n" << endl;
    cout << "char1: " << char1 << "\n" << "char2: " << char2 << endl;
    if (equal_chars(char1, char2)){
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
    
    cout << "Ver si las 2 cadenas son iguales tomó: "<< elapsedTime1.count() << " nanosegundos" << endl;


    //VERIFICACIÓN EN TIEMPO DE COMPILACIÓN
    cout << "\nVERIFICACIÓN EN TIEMPO DE COMPILACIÓN\n" << endl;
    cout << "char1: " << char3 << "\n" << "char2: " << char4 << endl;
    
    if (equal_chars_compilation(char1, char2)){
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
    
    cout << "Ver si las 2 cadenas son iguales tomó: "<< elapsedTime2.count() << " nanosegundos" << endl;
}

