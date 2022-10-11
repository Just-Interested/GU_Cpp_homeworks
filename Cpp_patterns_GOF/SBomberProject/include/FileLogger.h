#pragma once
#include <fstream>
#include <ios>

class FileLogger {
private:
    std::ofstream logOut;
public:
    FileLogger(std::string logFileName);
    ~FileLogger();
    void WriteToLog(const std::string& str);

	void WriteToLog(const std::string& str, int n);

	void WriteToLog(const std::string& str, double d);
    
    std::string GetCurDateTime();
};


extern FileLogger global_logger;