#include "Duck.hpp"

Duck::Duck() : position(0) {}

void Duck::updatePosition() {
  position = rand % 7;
}

int Duck::getPosition() const {
  return position;
}
