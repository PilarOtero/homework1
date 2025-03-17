#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

const string get_severity (Severity severity){
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

    messagesfile << "[ERROR] <" << message << " in line " << line << " from file " << file << ">" << endl;
    messagesfile.close();
 }

 void logMessage (Severity severity, string access_message, string username){
    ofstream accessfile ("log.txt", ios::app);
    
    if (! accessfile){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    accessfile << "[" << get_severity(severity) << "]<" << access_message << "> logged in by " << username << endl;
    accessfile.close();
}

void security (){
    string access_message, username;

    cout << "Ingrese el mensaje de acceso: ";
    cin.ignore(); getline(cin, access_message);
    cout << "Ingrese su username: ";
    getline(cin, username);

    logMessage(Severity::SECURITY, access_message, username);
}

void message(Severity severity){
    string message;

    cout << "Ingrese el problema: ";   
    cin.ignore(); getline(cin, message);

    logMessage(message, severity);
}
