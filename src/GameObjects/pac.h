#pragma once
#include "GameObject.h"

class pac : public GameObject
{
 public:
 pac();
 void init();
 void update(float dt);
 void setDirection(int x, int y);

 void render(sf::RenderWindow& window);
 void life_lost();
 void power_up();
 void stop();

 bool super;
 int direction[2];
 int lives = 3;
 sf::Texture texture_up;
 sf::Texture texture_right;
 sf::Texture texture_left;
 sf::Texture texture_down;
 sf::Texture ship_up;
 sf::Texture ship_right;
 sf::Texture ship_left;
 sf::Texture ship_down;

 void reset();

private:

 int speed = 150;
 float super_timer;
 float origin_x;
 float origin_y;
};

