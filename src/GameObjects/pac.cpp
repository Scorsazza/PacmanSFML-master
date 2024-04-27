#include <iostream>
#include "pac.h"

pac::pac()
{
  init();
}

void pac::init()
{
  texture.loadFromFile("Data/Images/ship.png");
  texture_up.loadFromFile("Data/Images/ship.png");
  texture_right.loadFromFile("Data/Images/ship.png");
  texture_left.loadFromFile("Data/Images/ship.png");
  texture_down.loadFromFile("Data/Images/ship.png");
  ship_up.loadFromFile("Data/Images/ship.png");
  ship_right.loadFromFile("Data/Images/ship.png");
  ship_left.loadFromFile("Data/Images/ship.png");
  ship_down.loadFromFile("Data/Images/ship.png");
  sprite.setScale(0.8,0.8);
  sprite.setTexture(texture);
  sprite.setPosition(200, 210);
  origin_x = sprite.getOrigin().x;
  origin_y = sprite.getOrigin().y;

  direction[0] = 1;
  direction[1] = 0;
}

void pac::update(float dt)
{
  if (super)
  {
    super_timer -= dt;
    if (super_timer <= 0)
    {
      super = false;
      setDirection(direction[0],direction[1]);
    }
  }
  sprite.move(dt * direction[0] * speed, dt * direction[1] * speed);
}

void pac::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void pac::setDirection(int x, int y)
{
  if (x == 1)
  {
    if (super)
    {
      sprite.setTexture(ship_right);
    }
    else
    {
      sprite.setTexture(texture_right);
    }

  }
  else if (x == -1)
  {
    if (super)
    {
      sprite.setTexture(ship_left);
    }
    else
    {
      sprite.setTexture(texture_left);
    }
  }
  else if (y == 1)
  {
    if (super)
    {
      sprite.setTexture(ship_right);
    }
    else
    {
      sprite.setTexture(texture_down);
    }
  }
  else if (y == -1)
  {
    if (super)
    {
      sprite.setTexture(ship_left);
    }
    else
    {
      sprite.setTexture(texture_up);
    }
  }

  direction[0] = x;
  direction[1] = y;
}
void pac::life_lost() {
  lives -= 1;
  sprite.setPosition(200, 200);
  setDirection(1,0);
}

void pac::reset() {
  lives = 3;
  sprite.setPosition(200, 200);
  setDirection(1,0);
  super = false;
}

void pac::power_up()
{
  super = true;
  super_timer = 10;
  setDirection(direction[0],direction[1]);
}

void pac::stop()
{
  direction[0] = 0;
  direction[1] = 0;
}
