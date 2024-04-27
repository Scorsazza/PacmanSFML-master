#include "coins.h"

void coins::init(int x_grid_pos, int y_grid_pos)
{
  visible = true;
  int num = rand()%30;
  if (num == 2)
  {
    initialiseSprite("Data/Images/powerup.png");
    power = true;
  }
  else
  {
    initialiseSprite("Data/Images/cow.png");
    power = false;
  };
  x_pos = (x_grid_pos*64) + 32 - (sprite.getGlobalBounds().width / 2);
  y_pos = (y_grid_pos*64) + 32 - (sprite.getGlobalBounds().height / 2);
  setPosition(x_pos,y_pos);
}

bool coins::pickup()
{
  visible = false;
  setPosition(-10000,-10000);
  if (power)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void coins::render(sf::RenderWindow& window)
{
  if (visible)
  {
    window.draw(sprite);
  }
}

void coins::reset()
{
  visible = true;
  setPosition(x_pos,y_pos);
}


