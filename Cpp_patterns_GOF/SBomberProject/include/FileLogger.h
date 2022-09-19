#pragma once

#include <iostream>
#include <fstream>
#include <chrono>



class FileLogger{
public:
    virtual void __fastcall OpenLogFile(const std::string& FN) = 0;

	virtual void CloseLogFile() = 0;

	virtual void __fastcall WriteToLog(const std::string& str) = 0;

	virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;

	virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;

protected:
    std::ofstream logOut;
};