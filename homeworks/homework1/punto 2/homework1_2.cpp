#include <iostream>
#include <fstream>
#include <string>
#include "homework1_2.h"

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

int main (){
    try {
        int severity;
        string message; 
        ofstream logfile("log.txt", ios::trunc);

        string access_message, username;
        
        cout << "Ingrese la severidad de su problema (1 = DEBUB, 2 = INFO, 3 = WARNING, 4 = ERROR, 5 = CRITICAL, 6  SECURITY): ";
        cin >> severity;

        switch (severity){
            case 4: 
                break;
            case 6: 
                cout << "Ingrese el mensaje de acceso: ";
                cin.ignore(); getline(cin, access_message);
                cout << "Ingrese su username: ";
                cin >> username;
        
                logMessage(Severity::SECURITY, access_message, username);
                break;
            default: 
                cout << "Ingrese el problema: ";   
                cin.ignore(); getline(cin, message);
            
                logMessage(message, static_cast<Severity>(severity));
                break;
        }
        

    
        logfile.close();
        return 0;
    }   
    catch (runtime_error &e){
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
}

