#include <utility>

#include "LogVisitor.h"
#include "MyTools.h"

void LogVisitor::log(Plane& plane){
    std::string message;
    message = "Plane coordinates: x = " + std::to_string(plane.GetX()) + " y = " + std::to_string(plane.GetY()) + ". ";
    message += "Plane speed = " + std::to_string(plane.GetSpeed()) + ". ";
    std::pair<double, double> direction = plane.GetDirection();
    message += "Plane direction: x = " + std::to_string(direction.first) + " y = " + std::to_string(direction.second) + ".";
    MyTools::WriteToLog(message);
}

void LogVisitor::log(Bomb& bomb){
    std::string message;
    message = "Bomb coordinates: x = " + std::to_string(bomb.GetX()) + " y = " + std::to_string(bomb.GetY()) + ". ";
    message += "Bomb speed = " + std::to_string(bomb.GetSpeed()) + ". ";
    std::pair<double, double> direction = bomb.GetDirection();
    message += "Bomb direction: x = " + std::to_string(direction.first) + " y = " + std::to_string(direction.second) + ".";
    MyTools::WriteToLog(message);
}