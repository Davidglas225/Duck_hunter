#pragma once

#include <cstdlib>

class Duck {

private:
    int position;

public:
    Duck();
    void updatePosition();
    int getPosition() const;
};
