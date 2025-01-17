#pragma once
#include "GameModes/RocketGameMode.h"


class KeepAway final : public RocketGameMode
{
public:
    KeepAway() { typeIdx = std::make_unique<std::type_index>(typeid(*this)); }

    void RenderOptions() override;
    bool IsActive() override;
    void Activate(bool active) override;
    std::string GetGameModeName() override;

private:
    void onTick(ServerWrapper server, void* params);
    void onGiveScorePre(ActorWrapper caller);
    void onGiveScorePost(ActorWrapper caller) const;
    void onCarTouch(void* params);
    void onBallTouch(CarWrapper car);
    void resetPoints();

    const unsigned long long emptyPlayer = static_cast<unsigned long long>(-1);

    int lastNormalScore = 0;
    bool enableNormalScore = false;
    bool enableRumbleTouches = false;
    float secPerPoint = 1;
    float timeSinceLastPoint = 0;
    unsigned long long lastTouched = emptyPlayer;
};
