#ifndef AIMIND
#define AIMIND

#include "controller.h"
#include "scene.h"

class AiMind {
public:
    const Ship* me;
    const Ship* target;

    float alertness = 0.25f; // 0 sleeping, 1 = terminator
    float happyTrigger = 1.0f; //if bullet will fly withing this dist from target FIRE

    AiMind();
    AiMind(const Ship* m, const Ship* t);
    void  rethink(ShipController & output);
    bool isActive();
};

#endif // !AIMIND
