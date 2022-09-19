#include <FileLoggerSingletone.h>

void __fastcall FileLoggerSingletone::OpenLogFile(const std::string& FN){
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile(){
    if (logOut.is_open())
    {
        logOut.close();
    }
}

std::string FileLoggerSingletone::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str){
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, int n){
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, double d){
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}


// next 3 functions added for usage in proxy class

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, const std::string& prefix){
    if (logOut.is_open())
    {
        logOut << prefix << GetCurDateTime() << " - " << str << std::endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, int n, const std::string& prefix){
    if (logOut.is_open())
    {
        logOut << prefix << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, double d, const std::string& prefix){
    if (logOut.is_open())
    {
        logOut << prefix << GetCurDateTime() << " - " << str << d << std::endl;
    }
}
