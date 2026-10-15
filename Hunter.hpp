#pragma once

#include <cstdint>

class Hunter{

private:
    int position;
    char lastChar;

public:
    Hunter();
    void initHunter();
    void checkButtonsAndUpdatePosition();
    bool shoot();
    int getPosition() const;
};
