#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY};

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
    ofstream logfile("log.txt", ios::app); 

    if (! logfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    
    logfile << "[" << get_severity(severity) << "]" << " <" << message << ">" << endl;
    logfile.close();
}

void logMessage (string message, string file, int line){
    ofstream messagesfile ("log.txt", ios::app);

    if (! messagesfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }   

    messagesfile << "[ERROR] <" << message << "in line " << line << "from file " << file << ">" << endl;
 }

 void logMessage (string access_message, string username){
    ofstream accessfile ("log.txt", ios::app);
    
}


int main (){
    int severity;
    string message; 

    logMessage ("Debug message", Severity::DEBUG);
    logMessage ("Info message", Severity::INFO);
    logMessage ("Warning message", Severity::WARNING);       
    logMessage ("Error message", Severity::ERROR);
    logMessage ("Critical message", Severity::CRITICAL);
    

    cout << "Ingrese la severidad de su problema (0 - 4): ";
    cin >> severity;
    cout << "Ingrese el problema: ";
    cin.ignore();
    getline(cin, message);

    logMessage(message, static_cast<Severity>(severity));
    logMessage(message, __FILE__, __LINE__);
}

