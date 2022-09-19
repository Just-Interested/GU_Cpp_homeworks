#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <FileLogger.h>



class FileLoggerSingletone : public FileLogger {
public:
    static FileLoggerSingletone& getInstance()
    {
        static FileLoggerSingletone theInstance;
        return theInstance;
    }

    void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

    void __fastcall WriteToLog(const std::string& str, const std::string& prefix);

    void __fastcall WriteToLog(const std::string& str, int n, const std::string& prefix);

	void __fastcall WriteToLog(const std::string& str, double d, const std::string& prefix);

private:
    FileLoggerSingletone(){};
    FileLoggerSingletone(const FileLoggerSingletone&) = delete;
    FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
    std::string GetCurDateTime();
};