#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL};

int get_severity (Severity level){
    switch (level){
        case Severity:: DEBUG: return 5;
        case Severity:: INFO: return 4;
        case Severity:: WARNING: return 3;
        case Severity:: ERROR: return 2;
        case Severity:: CRITICAL: return 1;
    }
}

