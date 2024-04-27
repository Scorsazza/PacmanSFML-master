#include "ship.h"
#include <iostream>

ship::ship()
{

}

ship::~ship()
{

}

void ship::init(int id_input)
{
  path_pos = 0;
  sprite.setOrigin(21, 23);
  switch (id_input)
  {
    case 0:
      id = id_input;
      initialiseSprite("Data/Images/ship_red.png");
      sprite.setPosition(8*64 + 32 - (sprite.getGlobalBounds().width / 2), 8 * 64 + 32 - (sprite.getGlobalBounds().height / 2));

      setDirection(path[0][0],path[0][1]);
      break;
    case 1:
      id = id_input;
      initialiseSprite("Data/Images/ship_blue.png");
      sprite.setPosition(9*64 + 32 - (sprite.getGlobalBounds().width / 2), 8 * 64 + 32 - (sprite.getGlobalBounds().height / 2));

      setDirection(Bpath[0][0],Bpath[0][1]);
      break;
    case 2:
      id = id_input;
      initialiseSprite("Data/Images/ship_green.png");
      sprite.setPosition(10*64 + 32 - (sprite.getGlobalBounds().width / 2), 8 * 64 + 32 - (sprite.getGlobalBounds().height / 2));

      setDirection(Gpath[0][0],Gpath[0][1]);
      break;
    case 3:
      id = id_input;
      initialiseSprite("Data/Images/ship_purple.png");
      sprite.setPosition(11*64 + 32 - (sprite.getGlobalBounds().width / 2), 8 * 64 + 32 - (sprite.getGlobalBounds().height / 2));

      setDirection(Apath[0][0],Apath[0][1]);
      break;
  }
}



Vector2 ship::normalise(float x, float y)
{
  float magnitude = sqrtf((x * x) + (y * y));

  if (!magnitude)
    return Vector2(0,0);

  x /= magnitude;
  y /= magnitude;

  return Vector2(x,y);
}

void ship::setDirection(float x, float y)
{
  x_destination = x * 64 + 10 + 21;
  y_destination = y * 64 + 10 + 23;
}

void ship::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}
void ship::update(float dt)
{

  if ((abs(x_destination - sprite.getPosition().x) > 1) || (abs(y_destination - sprite.getPosition().y) > 1))
  {
    float x_diff = x_destination - sprite.getPosition().x;
    float y_diff = y_destination - sprite.getPosition().y;


    sprite.move(normalise(x_diff, y_diff).x * 3, normalise(x_diff, y_diff).y * 3);


    if (normalise(x_diff, y_diff).x == 1)
    {
      sprite.setRotation(-90);
    }
    else if (normalise(x_diff, y_diff).x == -1)
    {
      sprite.setRotation(90);
    }
    else if (normalise(x_diff, y_diff).y == 1)
    {
      sprite.setRotation(0);
    }
    else if (normalise(x_diff, y_diff).y == -1)
    {
      sprite.setRotation(180);
    }

  }
  else
  {
    switch (id)
    {
      case 0:
        sprite.setPosition(x_destination,y_destination);
        path_pos += 1;
        if (path_pos >= 12)
        {
          path_pos = 0;
        }
        setDirection(path[path_pos][0],path[path_pos][1]);
        break;
      case 1:
        sprite.setPosition(x_destination,y_destination);
        path_pos += 1;
        if (path_pos >= 16)
        {
          path_pos = 0;
        }
        setDirection(Bpath[path_pos][0],Bpath[path_pos][1]);
        break;
      case 2:
        sprite.setPosition(x_destination,y_destination);
        path_pos += 1;
        if (path_pos >= 12)
        {
          path_pos = 0;
        }
        setDirection(Gpath[path_pos][0],Gpath[path_pos][1]);
        break;
      case 3:
        sprite.setPosition(x_destination,y_destination);
        path_pos += 1;
        if (path_pos >= 17)
        {
          path_pos = 0;
        }
        setDirection(Apath[path_pos][0],Apath[path_pos][1]);
        break;
    }

  }
}

