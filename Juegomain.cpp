
#include "Juego.h"
#include <SDL_mixer.h>
#include <stdio.h>

Juego::Juego()//Inicializacion de las variables
{
    window = NULL;
    ejecutando = true;
    menu = NULL;
    seleccionar = NULL;
    seleccionar2 = NULL;
    juego = NULL;
    piedra2i = NULL;
    piedra2d = NULL;
    piedrai = NULL;
    piedrad = NULL;
    papeli = NULL;
    papeld = NULL;
    tijerai= NULL;
    tijerad = NULL;
    menu2 = NULL;
    siluetasi = NULL;
    siluetasd = NULL;
    ganandoi = NULL;
    ganandod = NULL;
    ganadas2i = NULL;
    ganadas2d = NULL;
    ganadas3i = NULL;
    ganadas3d = NULL;
    juegorapido = NULL;
    ganador_rapido = NULL;
    perdedor_rapido = NULL;
    empate_rapido =   NULL;
    opcjuego = 0;
    }

int Juego::ejecutar()
{
state = MENU;
init_SDL(); //crea la ventana y el renderer
loadContenido();//carga el contenido que son las imagenes
 while(ejecutando) //ejecuta el juego
 {
    while(SDL_PollEvent(&Event)) //ejecuta los eventos del juego
      {
        evento(&Event);//funcion que recibe el evento que esta realizando
      }
     switch(state)
      {
     case MENU :  inicio();
                 if( Event.key.keysym.sym == SDLK_s && rect_seleccionar.y==500)
                 {
                 SDL_Quit();
                 return 0;
                 }

     break;
     case NOMBRE_JUGADOR : puntuacion();
                       if(opcjuego == 233)
                       state = JUEGO;
                       else if(opcjuego == 293)
                       state = JUEGORAPIDO;
                       else if(opcjuego == 353)
                       state = JUEGO_PPTLS;
                       else if(opcjuego == 413)
                       state = JUEGO_PPTLSRAPIDO;
     break;
     case JUEGO :jugar();
                 SDL_Event Event2;
                 while(SDL_PollEvent(&Event2)) //ejecuta los eventos del juego
                {
                evento2(&Event2);//funcion que recibe el evento que esta realizando
                }
    break;
    case JUEGORAPIDO :jugarRapido();
                      SDL_Event Event3;
                 while(SDL_PollEvent(&Event3)) //ejecuta los eventos del juego
                {
                evento3(&Event3);//funcion que recibe el evento que esta realizando
                }
     break;
     case JUEGO_PPTLS : jugar_pptls();
                    SDL_Event Event2pptls;
                while(SDL_PollEvent(&Event2pptls)) //ejecuta los eventos del juego
                {
                evento2pptls(&Event2pptls);//funcion que recibe el evento que esta realizando
                }
     break;
     case JUEGO_PPTLSRAPIDO : jugarRapido_pptls();
                              SDL_Event Event3pptls;
                 while(SDL_PollEvent(&Event3pptls)) //ejecuta los eventos del juego
                {
                evento3pptls(&Event3pptls);//funcion que recibe el evento que esta realizando
                }
     break;
     case INSTRUCCIONES : Instrucciones();//funcion que recibe el evento que esta realizando
                 SDL_Event Event4;
                 while(SDL_PollEvent(&Event4)) //ejecuta los eventos del juego
                {
                 evento4(&Event4);
                }
             break;
     case PUNTUACION :mostrarPuntaje();
     break;
     case SALIR :  SDL_Quit();
                   return 0;
     break;
    default :SDL_Quit();
     }
        }// cierra el while que ejecuta el juego
        limpiar();//limpia todo al salirse del juego
        return 0;
}//Cierre de la función ejecutar

////////////////////////////////////M A I N/////////////////////////////////M A I N/////////
int main( int argc, char* args[] )
{
        Juego MiJuego; //se instancia el objeto juego
////////////////////////////////////MÚSICA//////////////////////////////////
Mix_Music *musica; //declaramos la musica de fondo

atexit(SDL_Quit);

if(SDL_Init(SDL_INIT_AUDIO) < 0) { //iniciamos el audio
exit (-1);
}

if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) < 0)
// iniciamos el audio a la frecuencia 22hz, 16 bits, 2 canales y un buffer de 4096 (segun el //sonido poner mas o menos cantidad de buffer)
{
exit(-1);
}

atexit(Mix_CloseAudio);

// cargamos los sonidos

musica = Mix_LoadMUS("sonido_menu.WAV"); //no creo q necesite explicacion

Mix_PlayMusic(musica, -1); //hacemos sonar la musica, 0 normal -1 infinito
///////////////////////////////////////////////////////////////////////////
    return MiJuego.ejecutar();//llama la funcion que ejecuta el juego

   // Mix_HaltMusic(); //paramos la musica
    Mix_FreeMusic(musica); //liberamos la musica

    SDL_Quit();

    return 0;
}

/////////F U E N T E S   D E   A Y U D A///////
//YOUTUBE: Canal de nemo rap:
 //        programacion en c++ con SDL primer proyecto
//         programacion en c++ con SDL primer proyecto part. 2
//         programacion en c++ con SDL primer proyecto part. 3
//BLOG:    Tutorial SDL: Sonido by Eskema->http://www.gp32spain.com/foros/showthread.php?22298-Tutorial-SDL-Sonido-by-Eskema

