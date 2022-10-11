
#include <conio.h>
#include <Windows.h>

#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================

FileLogger global_logger("log.txt");

int main(void)
{
    //MyTools::OpenLogFile("log.txt");
    
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
        Sleep(30);

        game.TimeFinish();

    } while (!game.GetExitFlag());

    //MyTools::CloseLogFile();
    return 0;
}
