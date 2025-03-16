#include <fstream>
#include <string>
#include <iostream>
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

int main (){
    try {
        int severity;
        ofstream logfile("log.txt", ios::trunc);

        cout << "Ingrese la severidad de su problema (1-DEBUG, 2-INFO, 3-WARNING, 4-ERROR, 5-CRITICAL, 6-SECURITY, 7-TRAGIC): ";
        cin >> severity;

        switch (severity){
            case 6: 
                security();
                break;
            case 7: 
                throw runtime_error("TRAGIC EVENT");
                break;
            default: 
                message(static_cast<Severity>(severity));
                break;
        }
    }   
    catch (runtime_error &e){
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    return 0;
}

