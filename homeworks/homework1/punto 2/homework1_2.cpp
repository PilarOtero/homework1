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
    ofstream logfile("test.txt", ios::app); 

    if (! logfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    
    logfile << "[" << get_severity(severity) << "]" << " <" << message << ">" << endl;
    logfile.close();
}

void logMessage (string message, string file, int line){
    ofstream messagesfile ("test.txt", ios::app);

    if (! messagesfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }   

    messagesfile << "[ERROR]" << message << "in line " << line << "from file " << file << endl;
 }


int main (){
    logMessage ("Debug message", Severity::DEBUG);
    logMessage ("Info message", Severity::INFO);
    logMessage ("Warning message", Severity::WARNING);       
    logMessage ("Error message", Severity::ERROR);
    logMessage ("Critical message", Severity::CRITICAL);

    return 0;
}

