//Archivo donde está toda la mecánica del juego completo
#include "Juego.h"
    int aj_pptls = 0;
    int ap_pptls = 0;
    int opcPC_pptls = 0;
    int gana_pptls = 0;
    int ganador1_pptls = 0;
    int ganador2_pptls = 0;
    int ganadorGlobal_pptls = 0;
    int resultado_pptls = 0; //almacena el resultado de cada jugada; sí falló, acertó o empató
    int borrarJugada_pptls =0;
    Mix_Chunk *sonido_pptls; //declaramos un sonido para usar


void Juego::jugar_pptls()
{
    if(borrarJugada_pptls==1)
    {
      aj_pptls = 0;
      ap_pptls = 0;
      opcPC_pptls = 0;
      gana_pptls = 0;
      ganador1_pptls = 0;
      ganador2_pptls = 0;
      ganadorGlobal_pptls = 0;
      resultado_pptls = 0;

      SDL_DestroyTexture(uno);
      SDL_DestroyTexture(dos);
      SDL_DestroyTexture(tres);
      SDL_DestroyTexture(cuatro);
      SDL_DestroyTexture(cinco);
      SDL_DestroyTexture(unopc);
      SDL_DestroyTexture(dospc);
      SDL_DestroyTexture(trespc);
      SDL_DestroyTexture(cuatropc);
      SDL_DestroyTexture(cincopc);
    }

    else if(borrarJugada_pptls==0)
    {
    int w=0,h=0;

    uno= IMG_LoadTexture(renderer, "uno.png");
    SDL_QueryTexture(uno, NULL, NULL, &w, &h);
    rect_uno.x = 95;
    rect_uno.y = 555;
    rect_uno.w = w;
    rect_uno.h = h;

    dos= IMG_LoadTexture(renderer, "dos.png");
    SDL_QueryTexture(dos, NULL, NULL, &w, &h);
    rect_dos.x = 83;
    rect_dos.y = 555;
    rect_dos.w = w;
    rect_dos.h = h;

    tres= IMG_LoadTexture(renderer, "tres.png");
    SDL_QueryTexture(tres, NULL, NULL, &w, &h);
    rect_tres.x = 85;
    rect_tres.y = 555;
    rect_tres.w = w;
    rect_tres.h = h;

    cuatro= IMG_LoadTexture(renderer, "cuatro.png");
    SDL_QueryTexture(cuatro, NULL, NULL, &w, &h);
    rect_cuatro.x = 83;
    rect_cuatro.y = 555;
    rect_cuatro.w = w;
    rect_cuatro.h = h;

    cinco= IMG_LoadTexture(renderer, "cinco.png");
    SDL_QueryTexture(cinco, NULL, NULL, &w, &h);
    rect_cinco.x = 85;
    rect_cinco.y = 555;
    rect_cinco.w = w;
    rect_cinco.h = h;

    unopc= IMG_LoadTexture(renderer, "uno.png");
    SDL_QueryTexture(unopc, NULL, NULL, &w, &h);
    rect_unopc.x = 532;
    rect_unopc.y = 555;
    rect_unopc.w = w;
    rect_unopc.h = h;

    dospc= IMG_LoadTexture(renderer, "dos.png");
    SDL_QueryTexture(dospc, NULL, NULL, &w, &h);
    rect_dospc.x = 519;
    rect_dospc.y = 555;
    rect_dospc.w = w;
    rect_dospc.h = h;

    trespc= IMG_LoadTexture(renderer, "tres.png");
    SDL_QueryTexture(trespc, NULL, NULL, &w, &h);
    rect_trespc.x = 522;
    rect_trespc.y = 555;
    rect_trespc.w = w;
    rect_trespc.h = h;

    cuatropc= IMG_LoadTexture(renderer, "cuatro.png");
    SDL_QueryTexture(cuatropc, NULL, NULL, &w, &h);
    rect_cuatropc.x = 519;
    rect_cuatropc.y = 555;
    rect_cuatropc.w = w;
    rect_cuatropc.h = h;

    cincopc= IMG_LoadTexture(renderer, "cinco.png");
    SDL_QueryTexture(cincopc, NULL, NULL, &w, &h);
    rect_cincopc.x = 522;
    rect_cincopc.y = 555;
    rect_cincopc.w = w;
    rect_cincopc.h = h;
}
   SDL_RenderCopy(renderer,juegopptls , NULL, &rect_juegopptls);
   SDL_RenderCopy(renderer, seleccionar2_pptls, NULL, &rect_seleccionar2pptls);

//////////////////////////////////////////////////////////////
if(gana_pptls==0)
        {
            if( getAciertosJug()==1 )
            SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
            if( getAciertosJug()==2 )
            SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
            if( getAciertosJug()==3 )
            SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
            if( getAciertosJug()==4 )
            SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
            if( getAciertosJug()==5 )
            SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
            if( getAciertosPc()==1 )
            SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
            if( getAciertosPc()==2 )
            SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
            if( getAciertosPc()==3 )
            SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
            if( getAciertosPc()==4 )
            SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
            if( getAciertosPc()==5 )
            SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
        }
        if(gana_pptls==1)
        {
        switch(aj_pptls)
        {
        case 1:SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
       if(ap_pptls==1)
         {
          SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
         }
       else if(ap_pptls==2)
         {
          SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
         }
       else if(ap_pptls==3)
         {
         SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
         }
         else if(ap_pptls==4)
         {
         SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
         }
         else if(ap_pptls==5)
         {
         SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
         }
         break;
        case 2:SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
       if(ap_pptls==1)
         {
          SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
         }
       else if(ap_pptls==2)
         {
          SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
         }
       else if(ap_pptls==3)
         {
         SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
         }
         else if(ap_pptls==4)
         {
         SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
         }
         else if(ap_pptls==5)
         {
         SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
         }
       break;
       case 3:SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
       if(ap_pptls==1)
         {
          SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
         }
       else if(ap_pptls==2)
         {
          SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
         }
       else if(ap_pptls==3)
         {
         SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
         }
         else if(ap_pptls==4)
         {
         SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
         }
         else if(ap_pptls==5)
         {
         SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
         }
         break;
      case 4:SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
         if(ap_pptls==1)
         {
          SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
         }
       else if(ap_pptls==2)
         {
          SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
         }
       else if(ap_pptls==3)
         {
         SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
         }
         else if(ap_pptls==4)
         {
         SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
         }
         else if(ap_pptls==5)
         {
         SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
         }
         break;
      case 5:SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
      if(ap_pptls==1)
        {
       SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
        }
      else  if(ap_pptls==2)
        {
       SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
        }
       else  if(ap_pptls==3)
        {
       SDL_RenderCopy(renderer, trespc , NULL, &rect_trespc);
        }
         else  if(ap_pptls==4)
        {
       SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
        }
         if(aj_pptls==5)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganaste , NULL, &rect_ganaste);
        }
        else if(ap_pptls==5)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,perdiste , NULL, &rect_perdiste);
        }
       break;
        }
     }
//////////////
    if(gana_pptls==2)
    {
    switch(ap_pptls)
       {
    case 1:
      SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if(aj_pptls==1)
    {
      SDL_RenderCopy(renderer, uno , NULL, &rect_uno);
    }
    else if(aj_pptls == 2)
    {
      SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    }
   else if(aj_pptls==3)
    {
      SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    }
    else if(aj_pptls==4)
    {
      SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    }
    else if(aj_pptls==5)
    {
      SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
    }
    break;
   case 2:
      SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);

   if(aj_pptls==1)
    {
      SDL_RenderCopy(renderer, uno , NULL, &rect_uno);
    }
    else if(aj_pptls == 2)
    {
      SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    }
   else if(aj_pptls==3)
    {
      SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    }
    else if(aj_pptls==4)
    {
      SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    }
    else if(aj_pptls==5)
    {
      SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
    }
    break;
    case 3:
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if(aj_pptls==1)
    {
      SDL_RenderCopy(renderer, uno , NULL, &rect_uno);
    }
    else if(aj_pptls == 2)
    {
      SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    }
   else if(aj_pptls==3)
    {
      SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    }
    else if(aj_pptls==4)
    {
      SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    }
    else if(aj_pptls==5)
    {
      SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
    }
    break;
    case 4:
    SDL_RenderCopy(renderer,cuatropc , NULL, &rect_cuatropc);
     if(aj_pptls==1)
    {
      SDL_RenderCopy(renderer, uno , NULL, &rect_uno);
    }
    else if(aj_pptls == 2)
    {
      SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    }
   else if(aj_pptls==3)
    {
      SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    }
    else if(aj_pptls==4)
    {
      SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    }
    else if(aj_pptls==5)
    {
      SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);
    }
    break;
    case 5:
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
       if(aj_pptls==1)
    {
      SDL_RenderCopy(renderer, uno , NULL, &rect_uno);
    }
    else if(aj_pptls == 2)
    {
      SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    }
   else if(aj_pptls==3)
    {
      SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    }
    else if(aj_pptls==4)
    {
      SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    }
    if(aj_pptls==5)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,ganaste , NULL, &rect_ganaste);
        }
        else if(ap_pptls==5)
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
void Juego::animInicio2(int opc2)
{
  /*  atexit(SDL_Quit);

    if(SDL_Init(SDL_INIT_AUDIO) < 0) { //iniciamos el audio
    exit (-1);
    }

    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) < 0)
    // iniciamos el audio a la frecuencia 22hz, 16 bits, 2 canales y un buffer de 4096 (segun el //sonido poner mas o menos cantidad de buffer)
    {
    exit(-1);
    }

    sonido_pptls = Mix_LoadWAV("sonido_cuentaregresiva.wav");

    atexit(Mix_CloseAudio);


    Mix_PlayChannel(-1,sonido_pptls,0); //-1 canal donde suena, sonido, 0 normal -1infinito*/
    for(int c= 0; c<5; c++)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);

    if(opc2==1){SDL_RenderCopy(renderer,piedra_pptls, NULL, &rect_piedrapptls);}
    if(opc2==2){SDL_RenderCopy(renderer,papel_pptls, NULL, &rect_papelpptls);}
    if(opc2==3){SDL_RenderCopy(renderer,tijera_pptls, NULL, &rect_tijerapptls);}
    if(opc2==4){SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);}
    if(opc2==5){SDL_RenderCopy(renderer,spock_pptls, NULL, &rect_spockpptls);}

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(290);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);

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

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(290);
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);

    if(opc2==1){SDL_RenderCopy(renderer,piedra_pptls, NULL, &rect_piedrapptls);}
    if(opc2==2){SDL_RenderCopy(renderer,papel_pptls, NULL, &rect_papelpptls);}
    if(opc2==3){SDL_RenderCopy(renderer,tijera_pptls, NULL, &rect_tijerapptls);}
    if(opc2==4){SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);}
    if(opc2==5){SDL_RenderCopy(renderer,spock_pptls, NULL, &rect_spockpptls);}

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(290);

//    Mix_FreeChunk (sonido_pptls); //liberamos sonido


}
////////////////////////////////////////////////////////////////////////////

void Juego::imprimirJugada2(int opc)//Recibe la jugada del jugador
{
    //Jugada quen eligio el jugador
    if(opc==1)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);
    SDL_RenderCopy(renderer,piedra_pptls , NULL, &rect_piedrapptls);
    imprimirJugadaPC2(1);

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado_pptls=  ganadorJugadaPPTLS();
    if(resultado_pptls==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado_pptls==0 && aj_pptls<4 && ap_pptls<5) |(resultado_pptls==0 && aj_pptls<5 && ap_pptls<3)|(resultado_pptls==1 && aj_pptls==3 && ap_pptls==4)|
        (resultado_pptls==2 && aj_pptls==4 && ap_pptls==3)|(resultado_pptls==2 && aj_pptls<5 && ap_pptls<4) |(resultado_pptls==1 && ap_pptls<5 && aj_pptls<4)|
        (aj_pptls==1 && ap_pptls==0) | (aj_pptls==0 && ap_pptls==1) |(aj_pptls==0 && ap_pptls==0)|(resultado_pptls==2 && aj_pptls==4 && ap_pptls==0)|
        (resultado_pptls==1 && aj_pptls==0 && ap_pptls==4))
    {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

    if(opc==2)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);
    SDL_RenderCopy(renderer,papel_pptls , NULL, &rect_papelpptls);
    imprimirJugadaPC2(2);

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado_pptls=  ganadorJugadaPPTLS();
    if(resultado_pptls==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado_pptls==0 && aj_pptls<4 && ap_pptls<5) |(resultado_pptls==0 && aj_pptls<5 && ap_pptls<3)|(resultado_pptls==1 && aj_pptls==3 && ap_pptls==4)|
        (resultado_pptls==2 && aj_pptls==4 && ap_pptls==3)|(resultado_pptls==2 && aj_pptls<5 && ap_pptls<4) |(resultado_pptls==1 && ap_pptls<5 && aj_pptls<4)|
        (aj_pptls==1 && ap_pptls==0) | (aj_pptls==0 && ap_pptls==1) |(aj_pptls==0 && ap_pptls==0)|(resultado_pptls==2 && aj_pptls==4 && ap_pptls==0)|(resultado_pptls==1 && aj_pptls==0 && ap_pptls==4))
    {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

     if(opc==3)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);
    SDL_RenderCopy(renderer, tijera_pptls , NULL, &rect_tijerapptls);
    imprimirJugadaPC2(3);

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado_pptls=  ganadorJugadaPPTLS();
    if(resultado_pptls==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
      if((resultado_pptls==0 && aj_pptls<4 && ap_pptls<5) |(resultado_pptls==0 && aj_pptls<5 && ap_pptls<3)|(resultado_pptls==1 && aj_pptls==3 && ap_pptls==4)|
        (resultado_pptls==2 && aj_pptls==4 && ap_pptls==3)|(resultado_pptls==2 && aj_pptls<5 && ap_pptls<4) |(resultado_pptls==1 && ap_pptls<5 && aj_pptls<4)|
        (aj_pptls==1 && ap_pptls==0) | (aj_pptls==0 && ap_pptls==1) |(aj_pptls==0 && ap_pptls==0)|(resultado_pptls==2 && aj_pptls==4 && ap_pptls==0)|
        (resultado_pptls==1 && aj_pptls==0 && ap_pptls==4))
        {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

     if(opc==4)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);
    SDL_RenderCopy(renderer, lagarto_pptls , NULL, &rect_lagartopptls);
    imprimirJugadaPC2(4);

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado_pptls=  ganadorJugadaPPTLS();
    if(resultado_pptls==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
     if((resultado_pptls==0 && aj_pptls<4 && ap_pptls<5) |(resultado_pptls==0 && aj_pptls<5 && ap_pptls<3)|(resultado_pptls==1 && aj_pptls==3 && ap_pptls==4)|
        (resultado_pptls==2 && aj_pptls==4 && ap_pptls==3)|(resultado_pptls==2 && aj_pptls<5 && ap_pptls<4) |(resultado_pptls==1 && ap_pptls<5 && aj_pptls<4)|
        (aj_pptls==1 && ap_pptls==0) | (aj_pptls==0 && ap_pptls==1) |(aj_pptls==0 && ap_pptls==0)|(resultado_pptls==2 && aj_pptls==4 && ap_pptls==0)|
        (resultado_pptls==1 && aj_pptls==0 && ap_pptls==4))
        {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }

     if(opc==5)
    {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, juegopptls, NULL, &rect_juegopptls);
    SDL_RenderCopy(renderer, spock_pptls , NULL, &rect_spockpptls);
    imprimirJugadaPC2(5);

    if( getAciertosJug()==1 )
    SDL_RenderCopy(renderer,uno , NULL, &rect_uno);
    if( getAciertosJug()==2 )
    SDL_RenderCopy(renderer,dos , NULL, &rect_dos);
    if( getAciertosJug()==3 )
    SDL_RenderCopy(renderer,tres , NULL, &rect_tres);
    if( getAciertosJug()==4 )
    SDL_RenderCopy(renderer,cuatro , NULL, &rect_cuatro);
    if( getAciertosJug()==5 )
    SDL_RenderCopy(renderer,cinco , NULL, &rect_cinco);

    if( getAciertosPc()==1 )
    SDL_RenderCopy(renderer,unopc , NULL, &rect_unopc);
    if( getAciertosPc()==2 )
    SDL_RenderCopy(renderer,dospc , NULL, &rect_dospc);
    if( getAciertosPc()==3 )
    SDL_RenderCopy(renderer,trespc , NULL, &rect_trespc);
    if( getAciertosPc()==4 )
    SDL_RenderCopy(renderer, cuatropc , NULL, &rect_cuatropc);
    if( getAciertosPc()==5 )
    SDL_RenderCopy(renderer,cincopc , NULL, &rect_cincopc);
    SDL_RenderPresent(renderer);
    Sleep(700);

    resultado_pptls=  ganadorJugadaPPTLS();
    if(resultado_pptls==0)
    {
    SDL_RenderCopy(renderer,empataste , NULL, &rect_empataste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==1)
    {
    SDL_RenderCopy(renderer,acertaste , NULL, &rect_acertaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
    if(resultado_pptls==2)
    {
    SDL_RenderCopy(renderer,fallaste , NULL, &rect_fallaste);
    SDL_RenderPresent(renderer);
    Sleep(1700);
    }
      if((resultado_pptls==0 && aj_pptls<4 && ap_pptls<5) |(resultado_pptls==0 && aj_pptls<5 && ap_pptls<3)|(resultado_pptls==1 && aj_pptls==3 && ap_pptls==4)|
        (resultado_pptls==2 && aj_pptls==4 && ap_pptls==3)|(resultado_pptls==2 && aj_pptls<5 && ap_pptls<4) |(resultado_pptls==1 && ap_pptls<5 && aj_pptls<4)|
        (aj_pptls==1 && ap_pptls==0) | (aj_pptls==0 && ap_pptls==1) |(aj_pptls==0 && ap_pptls==0)|(resultado_pptls==2 && aj_pptls==4 && ap_pptls==0)|
        (resultado_pptls==1 && aj_pptls==0 && ap_pptls==4))
        {
    SDL_RenderCopy(renderer,continuar , NULL, &rect_continuar);
    SDL_RenderPresent(renderer);
    Sleep(1300);
    }
    }
}
//////////////////////////////////////////////////////////////////
int Juego::jugadaPC2()
{
   srand( time(0));
   int opcPC2 = 1 + rand() % 5;
   return opcPC2;
}
////////////////////////////////////////////////////////////////////
void Juego::imprimirJugadaPC2(int opcJugador)
{
    opcPC_pptls=jugadaPC2();
    if(opcPC_pptls==1)
    {
    SDL_RenderCopy(renderer, piedrapc_pptls , NULL, &rect_piedrapcpptls);
    }
    if(opcPC_pptls==2)
    {
    SDL_RenderCopy(renderer, papelpc_pptls , NULL, &rect_papelpcpptls);
    }
     if(opcPC_pptls==3)
    {
    SDL_RenderCopy(renderer, tijerapc_pptls , NULL, &rect_tijerapcpptls);
    }
    if(opcPC_pptls==4)
    {
    SDL_RenderCopy(renderer, lagartopc_pptls , NULL, &rect_lagartopcpptls);
    }
    if(opcPC_pptls==5)
    {
    SDL_RenderCopy(renderer, spockpc_pptls , NULL, &rect_spockpcpptls);
    }

    opciones(opcJugador,opcPC_pptls);
}
///////////////////////////////////////////////////////////////////////
int Juego::ganadorJugadaPPTLS()
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
void Juego::evento2pptls(SDL_Event* Event2pptls)
 {
 if(Event2pptls->type == SDL_QUIT)
        {
            ejecutando = false; //hace que termine el while que esta ejecutando el juego
        }
    if(Event2pptls->type == SDL_KEYDOWN)
     {

     switch(Event2pptls->key.keysym.sym)
     {
         case SDLK_m : borrarJugada_pptls = 1;

               state = MENU;
               while(SDL_PollEvent(&Event))
                {
                evento(&Event);//funcion que recibe el evento que esta realizando
                }

         break;
         case SDLK_e: borrarJugada_pptls=0;
             if(ganadorGlobal_pptls<5)
        {
           if(rect_seleccionar2pptls.x==125)
        {
            animInicio2(1);
            imprimirJugada2(1);
            gana_pptls = ganadorJugadaPPTLS();
           if(gana_pptls==1 && aj_pptls<5)
            {
             aj_pptls = aj_pptls + 1;
             ganador1_pptls = ganador1_pptls +1;
            if(ganador1_pptls==5)
              {
            ganadorGlobal_pptls = 5;
            ganador2_pptls = 0;
              }
            }
         else if(gana_pptls==2 && ap_pptls<5)
            {
            ap_pptls = ap_pptls + 1;
            ganador2_pptls = ganador2_pptls +1;
            if(ganador2_pptls==5)
              {
            ganadorGlobal_pptls = 5;
            ganador1_pptls = 0;
              }
            }
        aciertos(aj_pptls,ap_pptls);
        }
         if(rect_seleccionar2pptls.x==225)
        {
            animInicio2(2);
            imprimirJugada2(2);
            gana_pptls = ganadorJugadaPPTLS();
         if(gana_pptls==1 && aj_pptls<5)
            {
            aj_pptls = aj_pptls + 1;
            ganador1_pptls = ganador1_pptls +1;
         if(ganador1_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador2_pptls = 0;
            }
            }
        else if(gana_pptls==2 && ap_pptls<5)
            {
            ap_pptls = ap_pptls + 1;
            ganador2_pptls = ganador2_pptls +1;
            if(ganador2_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador1_pptls = 0;
            }
            }
      aciertos(aj_pptls,ap_pptls);
        }
        if(rect_seleccionar2pptls.x==325)
          {
            animInicio2(3);
            imprimirJugada2(3);
            gana_pptls = ganadorJugadaPPTLS();
            if(gana_pptls==1 && aj_pptls<5)
            {
            aj_pptls = aj_pptls + 1;
            ganador1_pptls = ganador1_pptls +1;
            if(ganador1_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador2_pptls = 0;
            }
            }
           else if(gana_pptls==2 && ap_pptls<5)
            {
            ap_pptls = ap_pptls + 1;
            ganador2_pptls = ganador2_pptls +1;
            if(ganador2_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador1_pptls = 0;
            }
            }
      aciertos(aj_pptls,ap_pptls);
          }
          if(rect_seleccionar2pptls.x==425)
          {
            animInicio2(4);
            imprimirJugada2(4);
            gana_pptls = ganadorJugadaPPTLS();
            if(gana_pptls==1 && aj_pptls<5)
            {
            aj_pptls = aj_pptls + 1;
            ganador1_pptls = ganador1_pptls +1;
            if(ganador1_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador2_pptls = 0;
            }
            }
           else if(gana_pptls==2 && ap_pptls<5)
            {
            ap_pptls = ap_pptls + 1;
            ganador2_pptls = ganador2_pptls +1;
            if(ganador2_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador1_pptls = 0;
            }
            }
      aciertos(aj_pptls,ap_pptls);
          }
          if(rect_seleccionar2pptls.x==525)
          {
            animInicio2(5);
            imprimirJugada2(5);
            gana_pptls = ganadorJugadaPPTLS();
            if(gana_pptls==1 && aj_pptls<5)
            {
            aj_pptls = aj_pptls + 1;
            ganador1_pptls = ganador1_pptls +1;
            if(ganador1_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador2_pptls = 0;
            }
            }
           else if(gana_pptls==2 && ap_pptls<5)
            {
            ap_pptls = ap_pptls + 1;
            ganador2_pptls = ganador2_pptls +1;
            if(ganador2_pptls==5)
            {
            ganadorGlobal_pptls = 5;
            ganador1_pptls = 0;
            }
            }
      aciertos(aj_pptls,ap_pptls);
          }

          if(ganador1_pptls == 5)
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
                        puntos2 = puntos + 5;
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
                       puntos2 = 5;
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

