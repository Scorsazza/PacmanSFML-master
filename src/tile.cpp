//
//
//

#include <iostream>
#include "tile.h"
tile::tile() {}

void tile::init(int input_id)
{
  id = input_id;
  switch (id)
  {
    case 0:
      wall = true;
      break;
    case 3:
      junction = true;
      directions[0] = true; // up
      directions[1] = true; // right
      directions[2] = true; // down
      directions[3] = false; // left
      break;
    case 4:
      junction = true;
      directions[0] = true; // up
      directions[1] = false; // right
      directions[2] = true; // down
      directions[3] = true; // left
      break;
    case 5:
      junction = true;
      directions[0] = true; // up
      directions[1] = true; // right
      directions[2] = false; // down
      directions[3] = true; // left
      break;
    case 6:
      junction = true;
      directions[0] = false; // up
      directions[1] = true; // right
      directions[2] = true; // down
      directions[3] = true; // left
      break;
    case 10:
      wall = true;
      break;
    case 12:
      junction = true;
      directions[0] = true; // up
      directions[1] = true; // right
      directions[2] = true; // down
      directions[3] = true; // left
      break;
    case 13:
      junction = true;
      directions[0] = false; // up
      directions[1] = true; // right
      directions[2] = true; // down
      directions[3] = false; // left
      break;
    case 14:
      junction = true;
      directions[0] = false; // up
      directions[1] = false; // right
      directions[2] = true; // down
      directions[3] = true; // left
      break;
    case 15:
      junction = true;
      directions[0] = false; // up
      directions[1] = true; // right
      directions[2] = false; // down
      directions[3] = true; // left
      break;
  }
}
