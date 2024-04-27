
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "ResourceHandler.h"
#include "GameObjects/pac.h"
#include "GameObjects/coins.h"
#include "GameObjects/ship.h"
#include "tile.h"
#include "GameObjects/BoundingBox.h"

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>



class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

  void mouseMoved(sf::Event event);

 private:
  sf::RenderWindow& window;
  //std::unique_ptr<ResourceHandler> resources;

  pac pac;


  tmx::Map map;
  sf::Texture tileMap;
  tile tilesSprites[32][32];
  //sf::Sprite tilesSprites[32][32];
  sf::Font font;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text exit_option;
  sf::Text secondary_title_text;
  sf::Texture background_texture;
  sf::Sprite background;

  sf::Text life_counter;
  sf::Text score_counter;
  int idx = 0, idy = 0;
  int score = 0;
  int state = 0;



  static bool collisionCheck(sf::Sprite entity, sf::Sprite item);


  coins coin_array[200];

  ship ship_array[4];

  void next_round();
  void updateGame(float dt);
  void renderGame();
  void reset();
};

#endif // PLATFORMER_GAME_H
