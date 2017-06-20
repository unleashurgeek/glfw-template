#pragma once

#include <glad/glad.h>

class Game {
  public:
    Game();
    void init();
    void update(GLdouble delta);
    void draw();
};