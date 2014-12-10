#include "Juego.h"

void Juego::inicio()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, menu, NULL, &rect_menu);
    SDL_RenderCopy(renderer, seleccionar, NULL, &rect_seleccionar);
    SDL_RenderPresent(renderer);
}

void Juego::Instrucciones()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, instrucciones, NULL, &rect_instrucciones);
    SDL_RenderPresent(renderer);
     }

 void Juego::evento4(SDL_Event* Event4)
 {
 if(Event4->type == SDL_QUIT)
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }
    if(Event4->type == SDL_KEYDOWN)
     {

     switch(Event4->key.keysym.sym)
     {
         case SDLK_m : state = MENU;
               while(SDL_PollEvent(&Event))
                {
                evento(&Event);//funcion que recibe el evento que esta realizando
                }
     }
     }
 }

