#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG = 1, INFO = 2, WARNING = 3, ERROR = 4, CRITICAL = 5};

void logMessage (string message, int severity){
    ofstream file("log.txt", ios::app); 

    if (! file){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    file << "[" << severity << "]" << "<" << message << ">" << endl;
}

int main (){
    logMessage ("Debug message", static_cast<int>(Severity::DEBUG));
    logMessage ("Info message", static_cast<int>(Severity::INFO));
    logMessage ("Warning message", static_cast<int>(Severity::WARNING));       
    logMessage ("Error message", static_cast<int>(Severity::ERROR));
    logMessage ("Critical message", static_cast<int>(Severity::CRITICAL));

    return 0;
}