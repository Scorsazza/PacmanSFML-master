#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  void initialiseSprite(std::string file_path);
  /** Position functions*/
  void setPosition(float  x ,float y);

  void setScale(int i, int i1);

  void setSprite(const sf::Sprite& sprite);

  const sf::Sprite getSprite();

  sf::Texture texture;

  sf::Sprite sprite;

 protected:

};