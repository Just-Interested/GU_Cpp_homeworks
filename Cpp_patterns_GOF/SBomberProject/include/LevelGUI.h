#pragma once

#include <stdint.h>

#include "GameObject.h"
#include "Mediator.h"

class LevelGUI : public GameObject, public NotifiableObject {
public:

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };
    
    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }

    void Draw() const override;

    void BeNotified(std::string info) override;

    std::string GetTopNotification() const;

private:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;

    mutable uint64_t lastNotificationTime = 0;
    mutable std::vector<std::string> notifications;
    mutable std::string topNotification = "";
};



