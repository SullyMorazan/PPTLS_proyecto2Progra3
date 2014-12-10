//Archivo donde está toda la mecánica del juego completo
#include "Juego.h"
    int aj = 0;
    int ap = 0;
    int opcPC = 0;
    int gana = 0;
    int ganador1 = 0;
    int ganador2 = 0;
    int ganadorGlobal = 0;
    int resultado = 0; //almacena el resultado de cada jugada; sí falló, acertó o empató
    int borrarJugada =0;
    Mix_Chunk *sonido; //declaramos un sonido para usar


void Juego::jugar()
{
    if(borrarJugada==1)
    {
      aj = 0;
      ap = 0;
      opcPC = 0;
      gana = 0;
      ganador1 = 0;
      ganador2 = 0;
      ganadorGlobal = 0;
      resultado = 0;

      SDL_RenderClear(renderer);
      SDL_DestroyTexture(ganandoi);
      SDL_DestroyTexture(ganadas2i);
      SDL_DestroyTexture(ganadas3i);
      SDL_DestroyTexture(ganandod);
      SDL_DestroyTexture(ganadas2d);
      SDL_DestroyTexture(ganadas3d);
    }

    else if(borrarJugada==0)
    {
    int w=0,h=0;
    ganandoi= IMG_LoadTexture(renderer, "ganandoi.png");
    SDL_QueryTexture(ganandoi, NULL, NULL, &w, &h);
    rect_ganandoi.x = 239;
    rect_ganandoi.y = 563;
    rect_ganandoi.w = w;
    rect_ganandoi.h = h;

    ganandod= IMG_LoadTexture(renderer, "ganandod.png");
    SDL_QueryTexture(ganandod, NULL, NULL, &w, &h);
    rect_ganandod.x = 364;
    rect_ganandod.y = 563;
    rect_ganandod.w = w;
    rect_ganandod.h = h;

    ganadas2i= IMG_LoadTexture(renderer, "ganadas2i.png");
    SDL_QueryTexture(ganadas2i, NULL, NULL, &w, &h);
    rect_ganadas2i.x = 150;
    rect_ganadas2i.y = 550;
    rect_ganadas2i.w = w;
    rect_ganadas2i.h = h;

    ganadas2d= IMG_LoadTexture(renderer, "ganadas2d.png");
    SDL_QueryTexture(ganadas2d, NULL, NULL, &w, &h);
    rect_ganadas2d.x = 340;
    rect_ganadas2d.y = 550;
    rect_ganadas2d.w = w;
    rect_ganadas2d.h = h;

    ganadas3i= IMG_LoadTexture(renderer, "ganadas3i.png");
    SDL_QueryTexture(ganadas3i, NULL, NULL, &w, &h);
    rect_ganadas3i.x = 81;
    rect_ganadas3i.y = 550;
    rect_ganadas3i.w = w;
    rect_ganadas3i.h = h;

    ganadas3d= IMG_LoadTexture(renderer, "ganadas3d.png");
    SDL_QueryTexture(ganadas3d, NULL, NULL, &w, &h);
    rect_ganadas3d.x = 340;
    rect_ganadas3d.y = 550;
    rect_ganadas3d.w = w;
    rect_ganadas3d.h = h;
}
   SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
   SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
   SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
   SDL_RenderCopy(renderer,menu2 , NULL, &rect_menu2);
   SDL_RenderCopy(renderer, seleccionar2, NULL, &rect_seleccionar2);
   SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
   SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);

//////////////////////////////////////////////////////////////
if(gana==0)
        {
            if( getAciertosJug()==1 )
            SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
            if( getAciertosJug()==2 )
            SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
            if( getAciertosJug()==3 )
            SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
            if( getAciertosPc()==1 )
            SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
            if( getAciertosPc()==2 )
            SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
            if( getAciertosPc()==3 )
            SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
        }
        if(gana==1)
        {
        switch(aj)
        {
        case 1:SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
       if(ap==1)
         {
          SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
         }
       else if(ap==2)
         {
          SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
         }
       else if(ap==3)
         {
         SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
         }
         break;
        case 2:SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
       if(ap==1)
         {
         SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
         }
       else  if(ap==2)
        {
        SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
        }
      else if(ap==3)
        {
        SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
        }
       break;
       case 3:SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
      if(ap==1)
        {
       SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
        }
      else  if(ap==2)
        {
       SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
        }
         if(aj==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganaste , NULL, &rect_ganaste);
        }
        else if(ap==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,perdiste , NULL, &rect_perdiste);
        }
       break;
        }
     }

    if(gana==2)
    {
    switch(ap)
       {
    case 1:
      SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if(aj==1)
    {
      SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    }
    else if(aj == 2)
    {
      SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    }
   else if(aj==3)
    {
      SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    }
    break;
   case 2:
      SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);

   if(aj==1)
    {
     SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    }
    else if(aj == 2)
    {
     SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    }
 else if(aj==3)
    {
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    }
    break;
    case 3:
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    if(aj==1)
    {
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    }
    else if(aj == 2)
    {
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    }
     if(aj==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganaste , NULL, &rect_ganaste);
        }
        else if(ap==3)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,perdiste , NULL, &rect_perdiste);
        }
    break;
    }
    }
SDL_RenderPresent(renderer);
}
////////////////////////////////////////////////////////////////////////////
void Juego::animInicio()
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

    sonido = Mix_LoadWAV("sonido_cuentaregresiva.wav");

    atexit(Mix_CloseAudio);


    Mix_PlayChannel(-1,sonido,0); //-1 canal donde suena, sonido, 0 normal -1infinito
    for(int c= 0; c<3; c++)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
    SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(500);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,piedrai , NULL, &rect_piedrai);
    SDL_RenderCopy(renderer,piedrad , NULL, &rect_piedrad);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if(c==0){SDL_RenderCopy(renderer,cuenregresiva3, NULL, &rect_cuenregresiva3);}
    if(c==1){SDL_RenderCopy(renderer,cuenregresiva2, NULL, &rect_cuenregresiva2);}
    if(c==2){SDL_RenderCopy(renderer,cuenregresiva1, NULL, &rect_cuenregresiva1);}
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(500);
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,piedra2i , NULL, &rect_piedra2i);
    SDL_RenderCopy(renderer,piedra2d , NULL, &rect_piedra2d);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(500);
    Mix_FreeChunk (sonido); //liberamos sonido
}
////////////////////////////////////////////////////////////////////////////

void Juego::imprimirJugada(int opc)//Recibe la jugada del jugador
{
    //Jugada quen eligio el jugador
    if(opc==1)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,piedrai , NULL, &rect_piedrai);
    imprimirJugadaPC(1);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado=  ganadorJugada();
    if(resultado==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado==0 && aj<2 && ap<3) |(resultado==0 && aj<3 && ap<2)|(resultado==1 && aj==1 && ap==2)|
        (resultado==2 && aj==2 && ap==1)|(resultado==2 && aj<3 && ap<2) |(resultado==1 && ap<3 && aj<2)|
        (aj==1 && ap==0) | (aj==0 && ap==1) |(aj==0 && ap==0)|(resultado==2 && aj==2 && ap==0)|(resultado==1 && aj==0 && ap==2))
    {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

    if(opc==2)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,papeli , NULL, &rect_papeli);
    imprimirJugadaPC(2);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado=  ganadorJugada();
    if(resultado==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado==0 && aj<2 && ap<3) |(resultado==0 && aj<3 && ap<2)|(resultado==1 && aj==1 && ap==2)|
        (resultado==2 && aj==2 && ap==1)|(resultado==2 && aj<3 && ap<2) |(resultado==1 && ap<3 && aj<2)|
        (aj==1 && ap==0) | (aj==0 && ap==1) |(aj==0 && ap==0)|(resultado==2 && aj==2 && ap==0)|(resultado==1 && aj==0 && ap==2))
    {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

     if(opc==3)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,juego , NULL, &rect_juego);
    SDL_RenderCopy(renderer,tijerai,NULL, &rect_tijerai);
    imprimirJugadaPC(3);
    SDL_RenderCopy(renderer,siluetasi , NULL, &rect_siluetasi);
    SDL_RenderCopy(renderer,siluetasd , NULL, &rect_siluetasd);
    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,ganandoi , NULL, &rect_ganandoi);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,ganadas2i , NULL, &rect_ganadas2i);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,ganadas3i , NULL, &rect_ganadas3i);
    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,ganandod , NULL, &rect_ganandod);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,ganadas2d , NULL, &rect_ganadas2d);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,ganadas3d , NULL, &rect_ganadas3d);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado=  ganadorJugada();
    if(resultado==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado==0 && aj<2 && ap<3) |(resultado==0 && aj<3 && ap<2)|(resultado==1 && aj==1 && ap==2)|
        (resultado==2 && aj==2 && ap==1)|(resultado==2 && aj<3 && ap<2) |(resultado==1 && ap<3 && aj<2)|
        (aj==1 && ap==0) | (aj==0 && ap==1) |(aj==0 && ap==0)|(resultado==2 && aj==2 && ap==0)|(resultado==1 && aj==0 && ap==2))
    {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }
}
//////////////////////////////////////////////////////////////////
int Juego::jugadaPC()
{
   srand( time(0));
   int opcPC = 1 + rand() % 3;
   return opcPC;
}
////////////////////////////////////////////////////////////////////
void Juego::imprimirJugadaPC(int opcJugador)
{
    opcPC=jugadaPC();
    if(opcPC==1)
    {
    SDL_RenderCopy(renderer,piedrad,NULL, &rect_piedrad);
    }
    if(opcPC==2)
    {
    SDL_RenderCopy(renderer,papeld,NULL, &rect_papeld);
    }
     if(opcPC==3)
    {
    SDL_RenderCopy(renderer,tijerad,NULL, &rect_tijerad);
    }
    opciones(opcJugador,opcPC);
}
///////////////////////////////////////////////////////////////////////
int Juego::ganadorJugada()
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
void Juego::evento2(SDL_Event* Event2)
 {
 if(Event2->type == SDL_QUIT)
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }
    if(Event2->type == SDL_KEYDOWN)
     {

     switch(Event2->key.keysym.sym)
     {
         case SDLK_m : borrarJugada = 1;

               state = MENU;
               while(SDL_PollEvent(&Event))
                {
                evento(&Event);//funcion que recibe el evento que esta realizando
                }

         break;
         case SDLK_e: borrarJugada=0;
             if(ganadorGlobal<3)
        {
           if(rect_seleccionar2.x==255)
        {
            animInicio();
            imprimirJugada(1);
            gana = ganadorJugada();
           if(gana==1 && aj<3)
            {
             aj = aj + 1;
             ganador1 = ganador1 +1;
            if(ganador1==3)
              {
            ganadorGlobal = 3;
            ganador2 = 0;
              }
            }
         else if(gana==2 && ap<3)
            {
            ap = ap + 1;
            ganador2 = ganador2 +1;
            if(ganador2==3)
              {
            ganadorGlobal = 3;
            ganador1 = 0;
              }
            }
        aciertos(aj,ap);
        }
         if(rect_seleccionar2.x==315)
        {
            animInicio();
            imprimirJugada(2);
            gana = ganadorJugada();
         if(gana==1 && aj<3)
            {
            aj = aj + 1;
            ganador1 = ganador1 +1;
         if(ganador1==3)
            {
            ganadorGlobal = 3;
            ganador2 = 0;
            }
            }
        else if(gana==2 && ap<3)
            {
            ap = ap + 1;
            ganador2 = ganador2 +1;
            if(ganador2==3)
            {
            ganadorGlobal = 3;
            ganador1 = 0;
            }
            }
      aciertos(aj,ap);
        }
        if(rect_seleccionar2.x==375)
          {
            animInicio();
            imprimirJugada(3);
            gana = ganadorJugada();
            if(gana==1 && aj<3)
            {
            aj = aj + 1;
            ganador1 = ganador1 +1;
            if(ganador1==3)
            {
            ganadorGlobal = 3;
            ganador2 = 0;
            }
            }
           else if(gana==2 && ap<3)
            {
            ap = ap + 1;
            ganador2 = ganador2 +1;
            if(ganador2==3)
            {
            ganadorGlobal = 3;
            ganador1 = 0;
            }
            }
      aciertos(aj,ap);
          }
          if(ganador1 == 3)
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
                        puntos2 = puntos + 3;
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
                       puntos2 = 3;
                       entrada<<nombrej<<"\t"<<puntos2<<"\n";
                       entrada.flush();
                }

                entrada.close();
                salida.close();
                remove("puntuacion.txt");
                rename("temp.txt","puntuacion.txt");
          }
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
