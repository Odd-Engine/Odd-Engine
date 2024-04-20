#include <iostream>

#include "Image.h"

Image::Image() : x(0), pos(0, 0)
{
  std::cout << "Image\n";
  std::cout << pos.x << ", " << pos.y << "\n";
}