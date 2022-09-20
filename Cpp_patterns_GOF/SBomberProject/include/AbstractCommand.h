#pragma once

class AbstractCommand
{
public:
    virtual ~AbstractCommand() {};
    virtual void Execute() = 0;
};

