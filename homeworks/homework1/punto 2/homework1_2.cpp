#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG = 1, INFO, WARNING, ERROR, CRITICAL, SECURITY};

string get_severity (Severity severity){
    switch (severity){
        case Severity :: DEBUG: return "DEBUG";
        case Severity :: INFO: return "INFO";
        case Severity :: WARNING: return "WARNING";
        case Severity :: ERROR: return "ERROR";
        case Severity :: CRITICAL: return "CRITICAL"; 

        case Severity :: SECURITY: return "SECURITY";
        default: return "UNKNOWN"; 
    }
}

void logMessage (string message, Severity severity){
    ofstream logfile("log.txt", ios::app); 

    if (! logfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    logfile << "[" << get_severity(severity) << "]<" << message << ">" << endl;
    logfile.close();
}

void logMessage (string message, string file, int line){
    ofstream messagesfile ("log.txt", ios::app);

    if (! messagesfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }   

    messagesfile << "[ERROR] <" << message << "> in line " << line << " from file " << file << endl;
 }

 void logMessage (Severity severity, string access_message, string username){
    ofstream accessfile ("log.txt", ios::app);
    
    if (! accessfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    accessfile << "[" << get_severity(severity) << "]<" << access_message << "> logged in by " << username << endl;
}

//FALTA EL IV REQUISITO

int main (){
    int severity;
    string message; 
    ofstream logfile("log.txt", ios::trunc);

    //Test mensajes NO personalizados
    string line = "Testing...";
    logfile << line << endl;

    logMessage ("Debug message", Severity::DEBUG);
    logMessage ("Info message", Severity::INFO);
    logMessage ("Warning message", Severity::WARNING);       
    logMessage ("Error message", Severity::ERROR);
    logMessage ("Critical message", Severity::CRITICAL);

    ////VER logfile << "End of the test" << endl;

    cout << "Ingrese la severidad de su problema (1 - 4): ";
    cin >> severity;
    cout << "Ingrese el problema: ";   
    cin.ignore(); getline(cin, message);
    
    logMessage(message, static_cast<Severity>(severity));
    logMessage(message, __FILE__, __LINE__);

    string access_message, username;
    cout << "Ingrese el mensaje de acceso: ";
    cin.ignore(); getline(cin, access_message);
    cout << "Ingrese su username: ";
    cin >> username;

    logMessage(Severity::SECURITY, access_message, username);

    logfile.close();
    
    return 0;
}

