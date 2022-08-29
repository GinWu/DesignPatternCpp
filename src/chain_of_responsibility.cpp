#include <iostream>
#include <string>

using namespace std;

class AbstractLogger {
public:
    static const int INFO = 1;
    static const int DEBUG = 2;
    static const int ERROR = 3;
    AbstractLogger() {
        _nextLogger = nullptr;
    }
    void setNextLogger(AbstractLogger* logger) {
        _nextLogger = logger;
        
    }

    void logMessage(int level, string message) {
        
        if (_level <= level) {
            write(message);
        }
        if (_nextLogger != nullptr) {
            _nextLogger->logMessage(level, message);
        }
    }

    virtual void write(string message) = 0;
    virtual ~AbstractLogger() {
        delete _nextLogger;
        _nextLogger = nullptr;
    }
protected:
    int _level;
    AbstractLogger* _nextLogger;
};

class ConsoleLogger: public AbstractLogger {
public:
    ConsoleLogger(int level) {
        _level = level;

    }
    void write(string message) {
        cout << "[INFO] " << message << endl;
    }
};

class ErrorLogger: public AbstractLogger {
public:
    ErrorLogger(int level) {
        _level = level;

    }
    void write(string message) {
        cout << "[ERROR]" << message << endl;
    }
};

class FileLogger: public AbstractLogger {
public:
    FileLogger(int level) {
        _level = level;

    }
    void write(string message) {
        cout << "[DEBUG]" << message << endl;
    }
};

int main() {
    AbstractLogger* errorLogger = new ErrorLogger(AbstractLogger::ERROR);
    AbstractLogger* fileLogger = new FileLogger(AbstractLogger::DEBUG);
    AbstractLogger* consoleLogger = new ConsoleLogger(AbstractLogger::INFO);

    errorLogger->setNextLogger(fileLogger);
    fileLogger->setNextLogger(consoleLogger);

    errorLogger->logMessage(AbstractLogger::INFO, "This is an information.");
    errorLogger->logMessage(AbstractLogger::DEBUG, "This is a debug information.");
    errorLogger->logMessage(AbstractLogger::ERROR, "This is an error information.");

    system("pause");
    return 0;
}