#include "FileLogger.h"

#include <chrono>

FileLogger::FileLogger(std::string logFileName){
    logOut.open(logFileName, std::ios_base::out);
    logOut << std::string(__FUNCTION__) << " was invoked" << std::endl;
}


FileLogger::~FileLogger(){
    logOut << std::string(__FUNCTION__) << " was invoked" << std::endl;
    if (logOut.is_open())
    {
        logOut.close();
    }
}

std::string FileLogger::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

void FileLogger::WriteToLog(const std::string& str){
    if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << std::endl;
        }
};

void FileLogger::WriteToLog(const std::string& str, int n){
    if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << std::endl;
        }
};

void FileLogger::WriteToLog(const std::string& str, double d){
    if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << std::endl;
        }
};