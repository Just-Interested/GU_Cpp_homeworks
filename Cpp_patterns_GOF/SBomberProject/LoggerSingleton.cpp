#include <LoggerSingleton.h>
#include <string>

void __fastcall LoggerSingleton::OpenLogFile(const std::string& FN){
    FileLoggerSingletone::getInstance().OpenLogFile(FN);
}

void LoggerSingleton::CloseLogFile(){
    FileLoggerSingletone::getInstance().CloseLogFile();
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str){
    //((LoggerSingleton&)(FileLoggerSingletone::getInstance())).GetFileStream() << lineNumber++ << ": ";
    std::string prefix = std::to_string(lineNumber++) + ": ";
    FileLoggerSingletone::getInstance().WriteToLog(str, prefix);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, int n){
    //((LoggerSingleton&)(FileLoggerSingletone::getInstance())).GetFileStream() << lineNumber++ << ": ";
    std::string prefix = std::to_string(lineNumber++) + ": ";
    FileLoggerSingletone::getInstance().WriteToLog(str, n, prefix);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, double d){
    //((LoggerSingleton&)(FileLoggerSingletone::getInstance())).GetFileStream() << lineNumber++ << ": ";
    std::string prefix = std::to_string(lineNumber++) + ": ";
    FileLoggerSingletone::getInstance().WriteToLog(str, d, prefix);
}

// std::ostream& LoggerSingleton::GetFileStream(){
//     return logOut;
// };