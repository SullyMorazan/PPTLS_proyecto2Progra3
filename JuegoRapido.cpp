//Archivo donde está toda la mecánica del juego rapidp
#include "Juego.h"

    int opcPCrapido = 0;
    int ganarapido = 3;
    Mix_Chunk *sonidorapido; //declaramos un sonido para usar

void Juego::jugarRapido()
{
        if(ganarapido==0)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,empate_rapido , NULL, &rect_empaterapido);
        SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
        SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
        SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
        SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);
        }
        else if(ganarapido==1)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganador_rapido , NULL, &rect_ganadorrapido);
        SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
        SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
        SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
        SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);
        }
        else if(ganarapido==2)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,perdedor_rapido , NULL, &rect_perdedorrapido);
        SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
        SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
        SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
        SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);
        }
        else if(ganarapido==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
        SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
        SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
        SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
        SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);
        }

   SDL_RenderPresent(renderer);
}
////////////////////////////////////////////////////////////////////////////
void Juego::animIniciorapida()
{
    atexit(SDL_Quit);

    if(SDL_Init(SDL_INIT_AUDIO) < 0) { //iniciamos el audio
    exit (-1);
    }

    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) < 0)
    // iniciamos el audio a la frecuencia 22hz, 16 bits, 2 canales y un buffer de 4096 (segun el //sonido poner mas o menos cantidad de buffer)
    {
    exit(-1);
    }

    sonidorapido = Mix_LoadWAV("sonido_cuentaregresiva.wav");

    atexit(Mix_CloseAudio);

    Mix_PlayChannel(-1,sonidorapido,0); //-1 canal donde suena, sonido, 0 normal -1infinito
    for(int c= 0; c<3; c++)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
    SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
    SDL_RenderPresent(renderer);
    Sleep(500);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,piedrai , NULL, &rect_piedrai);
    SDL_RenderCopy(renderer,piedrad , NULL, &rect_piedrad);
    if(c==0){SDL_RenderCopy(renderer,cuenregresiva3, NULL, &rect_cuenregresiva3);}
    if(c==1){SDL_RenderCopy(renderer,cuenregresiva2, NULL, &rect_cuenregresiva2);}
    if(c==2){SDL_RenderCopy(renderer,cuenregresiva1, NULL, &rect_cuenregresiva1);}
    SDL_RenderPresent(renderer);
    Sleep(500);
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
    SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
    SDL_RenderPresent(renderer);
    Sleep(500);
    Mix_FreeChunk (sonidorapido); //liberamos sonido
}
////////////////////////////////////////////////////////////////////////////

void Juego::imprimirJugadaRapida(int opc)//Recibe la jugada del jugador
{
    //Jugada que eligio el jugador
    if(opc==1)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,piedrai , NULL, &rect_piedrai);
    imprimirJugadaPCrapida(1);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

    if(opc==2)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,papeli , NULL, &rect_papeli);
    imprimirJugadaPCrapida(2);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

     if(opc==3)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido , NULL, &rect_juegorapido);
    SDL_RenderCopy(renderer,tijerai,NULL, &rect_tijerai);
    imprimirJugadaPCrapida(3);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }
}
//////////////////////////////////////////////////////////////////
int Juego::jugadaPCrapida()
{
   srand( time(0));
   int opcPCrapido = 1 + rand() % 3;
   return opcPCrapido;
}
////////////////////////////////////////////////////////////////////
void Juego::imprimirJugadaPCrapida(int opcJugador)
{
    opcPCrapido=jugadaPCrapida();
    if(opcPCrapido==1)
    {
    SDL_RenderCopy(renderer,piedrad,NULL, &rect_piedrad);
    }
    if(opcPCrapido==2)
    {
    SDL_RenderCopy(renderer,papeld,NULL, &rect_papeld);
    }
     if(opcPCrapido==3)
    {
    SDL_RenderCopy(renderer,tijerad,NULL, &rect_tijerad);
    }
    opciones(opcJugador,opcPCrapido);
}
///////////////////////////////////////////////////////////////////////
int Juego::ganadorJugadarapida()
{
if(this->getOpcJugador()==this->getOpcPc()){return 0;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==2){return 2;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==1){return 1;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==3){return 1;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==1){return 2;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==3){return 2;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==2){return 1;}
}
//////////////////////////////////////////////////////////////////////////
void Juego::evento3(SDL_Event* Event3)
 {
 if(Event3->type == SDL_QUIT)
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }
    if(Event3->type == SDL_KEYDOWN)
     {

     switch(Event3->key.keysym.sym)
     {
         case SDLK_m :// borrarJugadarapida = 1;
               ganarapido = 3;
               state = MENU;
               while(SDL_PollEvent(&Event))
                {
                evento(&Event);//funcion que recibe el evento que esta realizando
                }

         break;
         case SDLK_e: //borrarJugadarapida=0;
           ganarapido = 3;
           if(rect_seleccionar2.x==255)
           {
            animIniciorapida();
            imprimirJugadaRapida(1);
            ganarapido = ganadorJugadarapida();
            }
         if(rect_seleccionar2.x==315)
        {
            animIniciorapida();
            imprimirJugadaRapida(2);
            ganarapido = ganadorJugadarapida();
        }
        if(rect_seleccionar2.x==375)
          {
            animIniciorapida();
            imprimirJugadaRapida(3);
            ganarapido = ganadorJugadarapida();
          }
          /////////////////////////////////////////////////////////ESCRITURA DE PUNTOS////////////////
          if(ganarapido == 1)
          {
            ifstream salida;
            salida.open("puntuacion.txt",ios::in);

            ofstream entrada;
            entrada.open("temp.txt", ios::out);

            bool encontrado = false;

            string nombre;
            int puntos = 0;
            int puntos2 = 0;

            if(salida.is_open() && entrada.is_open())
            {
                salida>>nombre;
                while(!salida.eof())
                {
                    salida>>puntos;
                    if(nombre == nombrej)
                    {
                        encontrado = true;
                        puntos2 = puntos + 1;
                        entrada<<nombre<<"\t"<<puntos2<<"\n";
                        entrada.flush();
                    }
                     else
                    {
                         entrada<<nombre<<"\t"<<puntos<<"\n";
                         entrada.flush();
                    }
                    salida>>nombre;
                }
            }

                if(encontrado==false)
                {
                       puntos2 = 1;
                       entrada<<nombrej<<"\t"<<puntos2<<"\n";
                       entrada.flush();
                }

                entrada.close();
                salida.close();
                remove("puntuacion.txt");
                rename("temp.txt","puntuacion.txt");
          }
                break;
          case SDLK_RIGHT:
                 if(rect_seleccionar2.x==255 || rect_seleccionar2.x==315)
                 {
                     for(int i=0; i<60; i++)
                     rect_seleccionar2.x++;
                 }
                break;
         case SDLK_LEFT:
                  if(rect_seleccionar2.x==315 || rect_seleccionar2.x==375)
                  {
                    for(int i=0; i<60; i++)
                    rect_seleccionar2.x--;
                  }
                break;
     }
     }
 }
