#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

bool init();
bool load();
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);