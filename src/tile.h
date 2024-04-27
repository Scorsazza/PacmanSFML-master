//
//
//

#ifndef PACMANSFML_TILE_H
#define PACMANSFML_TILE_H

#include <SFML/Graphics.hpp>

class tile
{
 public:
  tile();
  void init(int id_input);
  sf::Sprite sprite;
  int id;
  bool junction = false;
  bool wall = false;
  bool directions[4];
};

#endif // PACMANSFML_TILE_H
