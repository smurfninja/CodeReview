#include "CardGameController.h"
#include "GoFishController.h"
#include <iostream>
int main()
{
  CardGameController* controller = new GoFishController();
  controller->startGame();
  return 0;
}
