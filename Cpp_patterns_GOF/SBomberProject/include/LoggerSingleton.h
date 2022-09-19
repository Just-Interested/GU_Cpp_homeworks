#pragma once

#include <FileLoggerSingletone.h>

class LoggerSingleton : public FileLogger{
public: 
    static LoggerSingleton& getInstance()
    {
        static LoggerSingleton theInstance;
        return theInstance;
    }

    void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

    //std::ostream& GetFileStream();

private:
    int lineNumber = 1;
    LoggerSingleton(){};
    LoggerSingleton(const LoggerSingleton&) = delete;
    LoggerSingleton& operator=(const LoggerSingleton&) = delete;
};