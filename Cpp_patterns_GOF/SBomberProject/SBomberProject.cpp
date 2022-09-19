
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include <FileLoggerSingletone.h>
#include <LoggerSingleton.h>

using namespace std;

//========================================================================================================================

int main(void)
{
    //FileLoggerSingletone::getInstance().OpenLogFile("log.txt");
    LoggerSingleton::getInstance().OpenLogFile("log1.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    //FileLoggerSingletone::getInstance().CloseLogFile();
    LoggerSingleton::getInstance().CloseLogFile();
    return 0;
}
