//Creacion de la pantalla con el contenido que vamos a presentar

#include "Juego.h"

bool Juego::init_SDL()
{
      //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Juego Piedra Papel, Tijera, Lagarto, Spock", 170 , 32, 662/*WIDTH*/, 662/*HEIGHT*/, SDL_WINDOW_RESIZABLE )) == NULL)
    {
        return false;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    return true;
}
