//Archivo donde está toda la mecánica del juego completo
#include "Juego.h"

    int opcPCrapido_pptls = 0;
    int ganarapido_pptls = 3;

   // Mix_Chunk *sonido_pptls; //declaramos un sonido para usar

void Juego::jugarRapido_pptls()
{
        if(ganarapido_pptls==0)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,empatasterapido_pptls, NULL, &rect_empatasterapidopptls);
        SDL_RenderCopy(renderer, seleccionar2_pptls, NULL, &rect_seleccionar2pptls);
        }
        else if(ganarapido_pptls==1)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganasterapido_pptls , NULL, &rect_ganasterapidopptls);
        SDL_RenderCopy(renderer, seleccionar2_pptls, NULL, &rect_seleccionar2pptls);
        }
        else if(ganarapido_pptls==2)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,perdisterapido_pptls , NULL, &rect_perdisterapidopptls);
        SDL_RenderCopy(renderer, seleccionar2_pptls, NULL, &rect_seleccionar2pptls);
        }
        else if(ganarapido_pptls==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
        SDL_RenderCopy(renderer, seleccionar2_pptls, NULL, &rect_seleccionar2pptls);
        }

   SDL_RenderPresent(renderer);
}
////////////////////////////////////////////////////////////////////////////
void Juego::animIniciorapida_pptls(int opc2)
{
   /* atexit(SDL_Quit);

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

    Mix_PlayChannel(-1,sonidorapido,0); */  //-1 canal donde suena, sonido, 0 normal -1infinito
    for(int c= 0; c<5; c++)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);

    if(opc2==1){SDL_RenderCopy(renderer,piedra_pptls, NULL, &rect_piedrapptls);}
    if(opc2==2){SDL_RenderCopy(renderer,papel_pptls, NULL, &rect_papelpptls);}
    if(opc2==3){SDL_RenderCopy(renderer,tijera_pptls, NULL, &rect_tijerapptls);}
    if(opc2==4){SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);}
    if(opc2==5){SDL_RenderCopy(renderer,spock_pptls, NULL, &rect_spockpptls);}
    SDL_RenderPresent(renderer);
    Sleep(290);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);

    if(c==0){SDL_RenderCopy(renderer,piedrapc_pptls, NULL, &rect_piedrapcpptls);}
    if(c==1){SDL_RenderCopy(renderer,papelpc_pptls, NULL, &rect_papelpcpptls);}
    if(c==2){SDL_RenderCopy(renderer,tijerapc_pptls, NULL, &rect_tijerapcpptls);}
    if(c==3){SDL_RenderCopy(renderer, lagartopc_pptls , NULL, &rect_lagartopcpptls);}
    if(c==4){SDL_RenderCopy(renderer,spockpc_pptls, NULL, &rect_spockpcpptls);}

    if(opc2==1){SDL_RenderCopy(renderer,piedra_pptls, NULL, &rect_piedrapptls);}
    if(opc2==2){SDL_RenderCopy(renderer,papel_pptls, NULL, &rect_papelpptls);}
    if(opc2==3){SDL_RenderCopy(renderer,tijera_pptls, NULL, &rect_tijerapptls);}
    if(opc2==4){SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);}
    if(opc2==5){SDL_RenderCopy(renderer,spock_pptls, NULL, &rect_spockpptls);}
    SDL_RenderPresent(renderer);
    Sleep(290);
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    if(opc2==1){SDL_RenderCopy(renderer,piedra_pptls, NULL, &rect_piedrapptls);}
    if(opc2==2){SDL_RenderCopy(renderer,papel_pptls, NULL, &rect_papelpptls);}
    if(opc2==3){SDL_RenderCopy(renderer,tijera_pptls, NULL, &rect_tijerapptls);}
    if(opc2==4){SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);}
    if(opc2==5){SDL_RenderCopy(renderer,spock_pptls, NULL, &rect_spockpptls);}
    SDL_RenderPresent(renderer);
    Sleep(290);
  //  Mix_FreeChunk (sonidorapido); //liberamos sonido
}
////////////////////////////////////////////////////////////////////////////

void Juego::imprimirJugadaRapida_pptls(int opc)//Recibe la jugada del jugador
{
    //Jugada que eligio el jugador
    if(opc==1)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    SDL_RenderCopy(renderer,piedra_pptls , NULL, &rect_piedrapptls);
    imprimirJugadaPCrapida_pptls(1);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

    if(opc==2)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    SDL_RenderCopy(renderer,papel_pptls , NULL, &rect_papelpptls);
    imprimirJugadaPCrapida_pptls(2);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

     if(opc==3)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    SDL_RenderCopy(renderer,tijera_pptls,NULL, &rect_tijerapptls);
    imprimirJugadaPCrapida_pptls(3);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

      if(opc==4)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    SDL_RenderCopy(renderer,lagarto_pptls,NULL, &rect_lagartopptls);
    imprimirJugadaPCrapida_pptls(4);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }

      if(opc==5)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juegorapido_pptls , NULL, &rect_juegorapidopptls);
    SDL_RenderCopy(renderer,spock_pptls,NULL, &rect_spockpptls);
    imprimirJugadaPCrapida_pptls(5);
    SDL_RenderPresent(renderer);
    Sleep(700);
    }
}
//////////////////////////////////////////////////////////////////
int Juego::jugadaPCrapida_pptls()
{
   srand( time(0));
   int opcPCrapidoPPTLS = 1 + rand() % 5;
   return opcPCrapidoPPTLS;
}
////////////////////////////////////////////////////////////////////
void Juego::imprimirJugadaPCrapida_pptls(int opcJugador)
{
    opcPCrapido_pptls=jugadaPCrapida_pptls();
    if(opcPCrapido_pptls==1)
    {
    SDL_RenderCopy(renderer, piedrapc_pptls , NULL, &rect_piedrapcpptls);
    }
    if(opcPCrapido_pptls==2)
    {
    SDL_RenderCopy(renderer, papelpc_pptls , NULL, &rect_papelpcpptls);
    }
     if(opcPCrapido_pptls==3)
    {
    SDL_RenderCopy(renderer, tijerapc_pptls , NULL, &rect_tijerapcpptls);
    }
    if(opcPCrapido_pptls==4)
    {
    SDL_RenderCopy(renderer, lagartopc_pptls , NULL, &rect_lagartopcpptls);
    }
    if(opcPCrapido_pptls==5)
    {
    SDL_RenderCopy(renderer, spockpc_pptls , NULL, &rect_spockpcpptls);
    }

    opciones(opcJugador,opcPCrapido_pptls);
}
///////////////////////////////////////////////////////////////////////
int Juego::ganadorJugadarapida_pptls()
{
if(this->getOpcJugador()==this->getOpcPc()){return 0;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==2){return 2;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==1){return 1;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==3){return 1;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==1){return 2;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==4){return 1;}
else if(this->getOpcJugador()==4 && this->getOpcPc()==1){return 2;}
else if(this->getOpcJugador()==1 && this->getOpcPc()==5){return 2;}
else if(this->getOpcJugador()==5 && this->getOpcPc()==1){return 1;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==3){return 2;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==2){return 1;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==4){return 2;}
else if(this->getOpcJugador()==4 && this->getOpcPc()==2){return 1;}
else if(this->getOpcJugador()==2 && this->getOpcPc()==5){return 1;}
else if(this->getOpcJugador()==5 && this->getOpcPc()==2){return 2;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==4){return 1;}
else if(this->getOpcJugador()==4 && this->getOpcPc()==3){return 2;}
else if(this->getOpcJugador()==3 && this->getOpcPc()==5){return 2;}
else if(this->getOpcJugador()==5 && this->getOpcPc()==3){return 1;}
else if(this->getOpcJugador()==4 && this->getOpcPc()==5){return 1;}
else if(this->getOpcJugador()==5 && this->getOpcPc()==4){return 2;}
}
//////////////////////////////////////////////////////////////////////////
void Juego::evento3pptls(SDL_Event* Eventpptls3)
 {
 if(Eventpptls3->type == SDL_QUIT)
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }
    if(Eventpptls3->type == SDL_KEYDOWN)
     {

     switch(Eventpptls3->key.keysym.sym)
     {
         case SDLK_m :// borrarJugadarapida = 1;
               ganarapido_pptls = 3;
               state = MENU;
               while(SDL_PollEvent(&Event))
                {
                evento(&Event);//funcion que recibe el evento que esta realizando
                }

         break;
         case SDLK_e: //borrarJugadarapida=0;
           ganarapido_pptls = 3;
           if(rect_seleccionar2pptls.x==125)
        {
            animIniciorapida_pptls(1);
            imprimirJugadaRapida_pptls(1);
            ganarapido_pptls = ganadorJugadarapida_pptls();
            }
         if(rect_seleccionar2pptls.x==225)
        {
            animIniciorapida_pptls(2);
            imprimirJugadaRapida_pptls(2);
            ganarapido_pptls = ganadorJugadarapida_pptls();
        }
        if(rect_seleccionar2pptls.x==325)
          {
            animIniciorapida_pptls(3);
            imprimirJugadaRapida_pptls(3);
            ganarapido_pptls = ganadorJugadarapida_pptls();
          }

           if(rect_seleccionar2pptls.x==425)
          {
            animIniciorapida_pptls(4);
            imprimirJugadaRapida_pptls(4);
            ganarapido_pptls = ganadorJugadarapida_pptls();
          }

           if(rect_seleccionar2pptls.x==525)
          {
            animIniciorapida_pptls(5);
            imprimirJugadaRapida_pptls(5);
            ganarapido_pptls = ganadorJugadarapida_pptls();
          }

        //////////////////////////////////////////ESCRITURA DE PUNTOS//////////////////////
        if(ganarapido_pptls==1)
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
                 if(rect_seleccionar2pptls.x==125 || rect_seleccionar2pptls.x==225 || rect_seleccionar2pptls.x==325 || rect_seleccionar2pptls.x==425)
                 {
                     for(int i=0; i<100; i++)
                     rect_seleccionar2pptls.x++;
                 }
                break;
         case SDLK_LEFT:
                  if(rect_seleccionar2pptls.x==525|| rect_seleccionar2pptls.x==425 || rect_seleccionar2pptls.x==325 || rect_seleccionar2pptls.x==225)
                  {
                    for(int i=0; i<100; i++)
                    rect_seleccionar2pptls.x--;
                  }
                break;
     }
     }
 }
