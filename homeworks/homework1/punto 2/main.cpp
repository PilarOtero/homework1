#include "functions.cpp"

int main (){
    try {
        int severity;
        ofstream logfile("log.txt", ios::trunc);

        cout << "Ingrese la severidad de su problema (1-DEBUG, 2-INFO, 3-WARNING, 4-ERROR, 5-CRITICAL, 6-SECURITY, 7-TRAGIC, 8-OUT): ";
        cin >> severity;

        switch (severity){
            case 8:
                cout << "Cerrando programa..." << endl;
                break;
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

