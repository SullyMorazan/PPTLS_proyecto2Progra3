//Destruye las texturas

#include "Juego.h"

void Juego::limpiar()
{
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(seleccionar);
    SDL_DestroyTexture(seleccionar2);
    SDL_DestroyTexture(juego);
    SDL_DestroyTexture(piedra2i);
    SDL_DestroyTexture(piedra2d);
    SDL_DestroyTexture(menu2);
    SDL_DestroyTexture(papeli);
    SDL_DestroyTexture(tijerai);
    SDL_DestroyTexture(juego);
    SDL_DestroyTexture(piedra2i);
    SDL_DestroyTexture(piedra2d);
    SDL_DestroyTexture(menu2);
    SDL_DestroyTexture(papeli);
    SDL_DestroyTexture(tijerai);

    SDL_DestroyTexture(menu2);
    SDL_DestroyTexture(siluetasi );
    SDL_DestroyTexture(siluetasd);
    SDL_DestroyTexture(ganandoi);
    SDL_DestroyTexture(ganandod);
    SDL_DestroyTexture(ganadas2i);
    SDL_DestroyTexture(ganadas2d);
    SDL_DestroyTexture(ganadas3i);
    SDL_DestroyTexture(ganadas3d );
    SDL_DestroyTexture(juegorapido);
    SDL_DestroyTexture(ganador_rapido );
    SDL_DestroyTexture(empate_rapido );
    SDL_DestroyTexture(perdedor_rapido );


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

