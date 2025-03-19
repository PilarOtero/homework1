using namespace std;

enum class Severity {DEBUG = 1, INFO, WARNING, ERROR, CRITICAL, SECURITY, TRAGIC, OUT};

const string get_severity (Severity severity);

void logMessage (string message, Severity severity);

void logMessage (string message, string file, int line);

void logMessage (Severity severity, string access_message, string username);

