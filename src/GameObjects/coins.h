#pragma once

#include "GameObject.h"

class coins : public GameObject
{
 public:
  void init(int x_grid_pos, int y_grid_pos);
  bool pickup();
  void render(sf::RenderWindow& window);
  void reset();

 private:
  bool visible;
  bool power;
  float x_pos;
  float y_pos;
};


