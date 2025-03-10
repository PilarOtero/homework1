#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL};

string get_severity (Severity severity){
    switch (severity){
        case Severity :: DEBUG: return "DEBUG";
        case Severity :: INFO: return "INFO";
        case Severity :: WARNING: return "WARNING";
        case Severity :: ERROR: return "ERROR";
        case Severity :: CRITICAL: return "CRITICAL";  
        default: return "UNKNOWN"; 
    }
}

void logMessage (string message, Severity severity){
    ofstream file("log.txt", ios::app); 

    if (! file){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    file << "[" << get_severity(severity) << "]" << " <" << message << ">" << endl;
    file.close();
}

int main (){
    logMessage ("Debug message", Severity::DEBUG);
    logMessage ("Info message", Severity::INFO);
    logMessage ("Warning message", Severity::WARNING);       
    logMessage ("Error message", Severity::ERROR);
    logMessage ("Critical message", Severity::CRITICAL);

    return 0;
}