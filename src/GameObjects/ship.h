#pragma once
#include <cmath>
#include "GameObject.h"
#include "Vector2.h"
class ship : public GameObject
{
 public:
  ship();
  ~ship();
  void init(int id);
  void update(float dt);
  void render(sf::RenderWindow& window);
  int id;

 protected:
  int path_pos = 0;
  int x_destination;
  int y_destination;
  Vector2 normalise(float x, float y);
  void setDirection(float x, float y);
  int path[12][2] =
    {
      {8,7},{8,5},{6,5},{6,3},{8,3},{8,1},{1,1},{1,5},{4,5},{4,8},{6,8},{6,7}
    };
  int Gpath[12][2] =
    {
      {10,7},{10,5},{12,5},{12,3},{14,3},{14,1},{17,1},{17,3},{14,3},{14,8},{12,8},{12,7}
    };
  int Bpath[16][2] =
    {
      {12,8},{14,8},{14,11},{17,11},{17,13},{16,13},{16,15},{17,15},{17,17},{10,17},{10,15},{12,15},{12,13},{10,13},{10,11},{12,11}
    };
  int Apath[17][2] =
    {
      {9,9},{6,9},{6,11},{4,11},{4,13},{6,13},{6,15},{8,15},{8,17},{10,17},{10,15},{12,15},{12,13},{14,13},{14,11},{12,11},{12,9}
    };

};

