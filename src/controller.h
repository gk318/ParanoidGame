#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "bat.h"

class Controller {
 public:
  void HandleInput(bool &running, ParanoidBat &bat) const;

 private:
  void ChangeDirection(ParanoidBat &bat, ParanoidBat::Direction input) const;
};

#endif