//Aqui tenemos todo lo que vamos a colocar dentro de la pantalla

#include "Juego.h"

void Juego::jugar()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
    SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
    SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
    SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);

    SDL_RenderPresent(renderer);
}
