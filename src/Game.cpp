
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
  //resources = std::make_unique<ResourceHandler>("Data");
}

Game::~Game()
{
  init();
}

bool Game::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }



  // inits menu text
  title_text.setString("Pac-man");
  title_text.setFont(font);
  title_text.setCharacterSize(100);
  title_text.setFillColor(sf::Color(0,255,0,255));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    80 - title_text.getGlobalBounds().height / 2);

  secondary_title_text.setString("Roswell Edition");
  secondary_title_text.setFont(font);
  secondary_title_text.setCharacterSize(100);
  secondary_title_text.setFillColor(sf::Color(0,255,0,255));
  secondary_title_text.setPosition(
    250,
    200 - title_text.getGlobalBounds().height / 2);

  // inits play text
  play_option.setString("Play");
  play_option.setFont(font);
  play_option.setCharacterSize(75);
  play_option.setPosition(
    200,
    500 - play_option.getGlobalBounds().height / 2);


  // inits exit text
  exit_option.setString("Exit");
  exit_option.setFont(font);
  exit_option.setCharacterSize(75);
  exit_option.setPosition(
    900,
    500 - exit_option.getGlobalBounds().height / 2);



  score_counter.setString("Score: " + std::to_string(score));
  score_counter.setFont(font);
  score_counter.setCharacterSize(50);
  score_counter.setFillColor(sf::Color(255,0 ,0,255));
  score_counter.setPosition(
    window.getSize().x / 2 - score_counter.getGlobalBounds().width / 2  + 450,
    10);

  life_counter.setString("Lives: " + std::to_string(pac.lives));
  life_counter.setFont(font);
  life_counter.setCharacterSize(50);
  life_counter.setFillColor(sf::Color(0,0,255,255));
  life_counter.setPosition(
    window.getSize().x / 2 - life_counter.getGlobalBounds().width / 2  - 500,
    10);

  background_texture.loadFromFile("Data/Images/ufo.png");
  background.setTexture(background_texture);
  background.setScale(0.35, 0.3);

  //load map

  if(!map.load("../Data/Map/map.tmx"))
  {
    std::cout << "\nfailed\n";
  }

  // loads map tile set

  if (!tileMap.loadFromFile("../Data/Map/terrainTiles_default.png"))
  {
    std::cout << "\nfailed\n";
  }

  const auto& layers = map.getLayers();
  const auto layer = layers[0]->getLayerAs<tmx::TileLayer>();
  const auto& tiles = layer.getTiles();
  int coin_count = 0;
  for(int j = 0; j < tiles.size(); j++)
  {
    idx = j / 19;
    idy = j % 19;
    tilesSprites[idx][idy].sprite.setTexture(tileMap);
    tilesSprites[idx][idy].sprite.setPosition(idy*64,idx*64);

    // this work
    int x = ((int(tiles[j].ID)%10)*64) - 64;
    //this works
    int y = ((int(tiles[j].ID)/10)*64);

    tilesSprites[idx][idy].sprite.setTextureRect(sf::IntRect(x,y,64,64));
    tilesSprites[idx][idy].init(tiles[j].ID);
    if (tilesSprites[idx][idy].id != 1)
    {
      coin_array[coin_count].init(idy,idx);
      coin_count +=1;
    }
  }

  for (int a = 0; a < 4; a++)
  {
    ship_array[a].init(a);
  }

  return true;
}

void Game::update(float dt)
{
  if (state == 0)
  {

  }
  else if (state == 1)
  {
    updateGame(dt);
  }
}

void Game::updateGame(float dt)
{
  pac.update(dt);

  if (pac.getSprite().getPosition().x < 0)
  {
    pac.setPosition(window.getSize().x, pac.getSprite().getPosition().y);
  }
  if (pac.getSprite().getPosition().x > window.getSize().x)
  {
    pac.setPosition(0, pac.getSprite().getPosition().y);
  }

  for (auto & tank : ship_array)
  {
    tank.update(dt);
    if (collisionCheck(tank.getSprite(), pac.getSprite()))
    {
      std::cout << "collision trigger";
      if (!pac.super)
      {
        next_round();
      }
      else
      {
        tank.init(tank.id);
      }
    }
    for (int j = 0; j < 19*19; j++)
    {
      idx = j / 19;
      idy = j % 19;
      if (collisionCheck(pac.sprite, tilesSprites[idx][idy].sprite))
      {
        if (tilesSprites[idx][idy].id == 1)
        {
          pac.sprite.move(-10 * pac.direction[0], -10 * pac.direction[1]);
          pac.setDirection(0,0);
        }
      }
    }
    score_counter.setPosition(
      window.getSize().x / 2 - score_counter.getGlobalBounds().width / 2  + 450,
      10);
    score_counter.setString("Score: " + std::to_string(score));

    life_counter.setString("Lives remaining: " + std::to_string(pac.lives));

    if (pac.lives <= 0)
    {
      title_text.setString("You lost");
      play_option.setString("Replay");
      state = 0;
    }
    if (score >= 1770)
    {
      title_text.setString("You Won");
      play_option.setString("Replay");
      state = 0;
    }

  }

  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
  {
    for (int j = 0; j < 19*19; j++)
    {
      idx = j / 19;
      idy = j % 19;
      if (collisionCheck(pac.sprite, tilesSprites[idx][idy].sprite))
      {
        if (tilesSprites[idx][idy].id == 1)
        {
          pac.sprite.move(-10 * pac.direction[0], -10 * pac.direction[1]);
          pac.setDirection(0,0);
        }
        else
        {
          pac.setDirection(1,0);
        }
      }
    }
  }
  else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
  {

    for (int j = 0; j < 19*19; j++)
    {
      idx = j / 19;
      idy = j % 19;
      if (collisionCheck(pac.sprite, tilesSprites[idx][idy].sprite))
      {
        if (tilesSprites[idx][idy].id == 1)
        {
          pac.sprite.move(-10 * pac.direction[0], -10 * pac.direction[1]);
          pac.setDirection(0,0);
        }
        else
        {
          pac.setDirection(0,-1);
        }
      }
    }
  }
  else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
  {
    for (int j = 0; j < 19*19; j++)
    {
      idx = j / 19;
      idy = j % 19;
      if (collisionCheck(pac.sprite, tilesSprites[idx][idy].sprite))
      {
        if (tilesSprites[idx][idy].id == 1)
        {
          pac.sprite.move(-10 * pac.direction[0], -10 * pac.direction[1]);
          pac.setDirection(0,0);
        }
        else
        {
          pac.setDirection(-1,0);
        }
      }
    }
  }
  else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
  {
    for (int j = 0; j < 19*19; j++)
    {
      idx = j / 19;
      idy = j % 19;
      if (collisionCheck(pac.sprite, tilesSprites[idx][idy].sprite))
      {
        if (tilesSprites[idx][idy].id == 1)
        {
          pac.sprite.move(-10 * pac.direction[0], -10 * pac.direction[1]);
          pac.setDirection(0,0);
        }
        else
        {
          pac.setDirection(0,1);
        }
      }
    }
  }

  for (auto & coin : coin_array)
  {
    if (collisionCheck(pac.getSprite(), coin.getSprite()))
    {
      score += 10;
      if (coin.pickup())
      {
        pac.power_up();
      }
    }
  }
}

void Game::render()
{
  if (state == 0)
  {
    window.draw(background);
    window.draw(title_text);
    window.draw(secondary_title_text);
    window.draw(play_option);
    window.draw(exit_option);
  }
  else if (state == 1)
  {
    renderGame();
  }
}

void Game::renderGame()
{
  for (int i = 0; i < 32; ++i)
  {
    for (int j = 0; j < 32; ++j)
    {
      window.draw(tilesSprites[i][j].sprite);
    }
  }
  for (auto & coin : coin_array)
  {
    coin.render(window);
  }

  for (auto & tank : ship_array)
  {
    tank.render(window);
  }

  pac.render(window);
  window.draw(life_counter);
  window.draw(score_counter);
}

bool Game::collisionCheck(sf::Sprite entity, sf::Sprite item)
{
  BoundingBox entity_box = BoundingBox(entity);
  BoundingBox item_box = BoundingBox(item);
  if (entity_box.north_west.x < item_box.south_east.x && entity_box.south_east.x > item_box.north_west.x &&
      entity_box.north_west.y < item_box.south_east.y && entity_box.south_east.y > item_box.north_west.y)
  {
    return true;
  }
  return false;
}

void Game::mouseClicked(sf::Event event)
{
  if (state == 0)
  {
    sf::Vector2i click = sf::Mouse::getPosition(window);

    sf::FloatRect play_box = play_option.getGlobalBounds();
    sf::FloatRect exit_box = exit_option.getGlobalBounds();

    if (play_box.contains(click.x, click.y))
    {

      reset();
      state = 1;
    }
    else if (exit_box.contains(click.x, click.y))
    {
      window.close();
    }
  }
  else if (state == 1)
  {
    score += 100;
  }
}

void Game::keyPressed(sf::Event event)
{

}

void Game::next_round()
{
  pac.life_lost();

  for (int a = 0; a < 4; a++)
  {
    ship_array[a].init(a);
  }
}

void Game::mouseMoved(sf::Event event)
{
  if (state == 0)
  {
    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    sf::FloatRect play_box = play_option.getGlobalBounds();
    sf::FloatRect exit_box = exit_option.getGlobalBounds();
    if (play_box.contains(mouse.x, mouse.y))
    {
      play_option.setFillColor(sf::Color(255, 174, 255, 255));
      exit_option.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else if (exit_box.contains(mouse.x, mouse.y))
    {
      play_option.setFillColor(sf::Color(255, 255, 255, 255));
      exit_option.setFillColor(sf::Color(255, 174, 255, 255));
    }
    else
    {
      play_option.setFillColor(sf::Color(255, 255, 255, 255));
      exit_option.setFillColor(sf::Color(255, 255, 255, 255));
    }
  }
}

void Game::reset()
{
  score = 0;
  for (int a = 0; a < 4; a++)
  {
    ship_array[a].init(a);
  }
  pac.reset();
  for (auto & coin : coin_array)
  {
    coin.reset();
  }
}
