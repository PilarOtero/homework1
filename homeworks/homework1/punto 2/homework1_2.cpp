#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG = 1, INFO = 2, WARNING = 3, ERROR = 4, CRITICAL = 5};


void logMessage (string message, Severity severity){
    ofstream file("log.txt", ios::app); 

    if (! file){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    file << "[" << get_severity(severity) << "]" << message << endl;
}