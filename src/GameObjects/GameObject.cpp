#include "GameObject.h"

void GameObject::initialiseSprite(std::string file_path)
{
  texture.loadFromFile(file_path);
  sprite.setTexture(texture);
}


void GameObject::setPosition(float a, float b)
{
  sprite.setPosition(a, b);
}

const sf::Sprite GameObject::getSprite()
{
  return sprite;
}

void GameObject::setSprite(const sf::Sprite& sprite)
{
  GameObject::sprite = sprite;
}

void GameObject::setScale(int i, int j)
{
  sprite.setScale(i,j);
}
