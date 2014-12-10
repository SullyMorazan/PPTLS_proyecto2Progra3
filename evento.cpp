#include "Juego.h"
#include<stdio.h>


void Juego::evento(SDL_Event* Event)
{
        if(Event->type == SDL_QUIT)//evento cuando cierra la ventana del juego
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }

       if(Event->type == SDL_KEYDOWN)
        {
       switch(Event->key.keysym.sym)
        {
        case(SDLK_UP)://si presiona la tecla de arriba
            if(rect_seleccionar.y==593 || rect_seleccionar.y==533 || rect_seleccionar.y==473||rect_seleccionar.y==413
               ||rect_seleccionar.y==353||rect_seleccionar.y==293)//si el puntero (la mano) esta posicionado en la opcion "Instrucciones" o "Salir"
            {
              for(int i=0; i<60; i++) //for para subir el puntero a la posicion que sigue hacia arriba
              rect_seleccionar.y--; //va subiendo el puntero hacia la siguiente posicion hacia arriba
            }
        break;
        case(SDLK_DOWN)://si presiona la tecla de abajo
            if(rect_seleccionar.y==233 || rect_seleccionar.y==293 || rect_seleccionar.y==353||rect_seleccionar.y==413
               ||rect_seleccionar.y==473 ||rect_seleccionar.y==533)//si el puntero esta en la opcion "Inicar Juego' o "Instrucciones"
            {
             for(int i=0; i<60; i++)//for para subir el puntero a la posicion que sigue hacia abajo
             rect_seleccionar.y++;//va bajando el puntero hacia la siguiente posicion hacia abajo
            }
         break;
         case SDLK_m: state = MENU;

         break;
         case SDLK_s:
             if(rect_seleccionar.y==233)
                     {
                      state = NOMBRE_JUGADOR;
                      opcjuego = 233;
                     }
                      if(rect_seleccionar.y==293)
                      {
                      state = NOMBRE_JUGADOR;
                      opcjuego = 293;
                      }

                      if(rect_seleccionar.y==353)
                      {
                        state = NOMBRE_JUGADOR;
                        opcjuego = 353;
                      }

                      if(rect_seleccionar.y==413)
                      {
                        state = NOMBRE_JUGADOR;
                        opcjuego = 413;
                      }
                      if(rect_seleccionar.y==473)
                      state = INSTRUCCIONES;
                      if(rect_seleccionar.y==533)
                      state = PUNTUACION;
                      if(rect_seleccionar.y==593)
                      state = SALIR;
         break;

        }
    }
}
