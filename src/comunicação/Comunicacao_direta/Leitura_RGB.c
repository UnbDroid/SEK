#include "Funcoes_testadas/comunicacao.h"

/* Funcoes de mostrar na tela do Takashi */

sub ShowRGB(int left[], int right[])
{
     /*ClearScreen();
     TextOut(40, LCD_LINE2, "LEFT");
     TextOut(70, LCD_LINE2, "RIGHT");
     TextOut(0, LCD_LINE4, "RED:");
     TextOut(0, LCD_LINE6, "GREEN:");
     TextOut(0, LCD_LINE8, "BLUE:"); */
     NumOut(40, LCD_LINE4, l_red);
     NumOut(40, LCD_LINE6, l_green);
     NumOut(40, LCD_LINE8, l_blue);
     NumOut(70, LCD_LINE4, r_red);
     /*NumOut(70, LCD_LINE6, r_green);
     NumOut(70, LCD_LINE8, r_blue);*/
     Wait(100);
}

/* Fim das funcoes do takashi */



task main()
{
     int i = 0;
     char cores[3] = {VERMELHO, VERDE, AZUL};
     
     BTCheck(BT_CONN); // Checa a conexao

     SetSensorTouch(TOUCH); // Liga o sensor touch

     set_sensor_color(COR_ESQUERDA, VERMELHO); // Liga o sensor esquerdo de cor
     Wait(50);
     set_sensor_color(COR_DIREITA,  VERMELHO); // Liga o sensor direito de cor
     
     while(true)
     {
          for(i = 0; i < 3; i++)
          {
               set_sensor_color(COR_ESQUERDA, cores[i]);
               set_sensor_color(COR_DIREITA,  cores[i]);
               Wait(25);     
               if(cores[i] == VERMELHO){
                    NumOut(40, LCD_LINE4, get_value_color(COR_ESQUERDA));
                    NumOut(70, LCD_LINE4, get_value_color(COR_DIREITA));
               }else if(cores[i] == VERDE){
                    NumOut(40, LCD_LINE6, get_value_color(COR_ESQUERDA));
                    NumOut(70, LCD_LINE6, get_value_color(COR_DIREITA));
               }else if(cores[i] == AZUL){
                    NumOut(40, LCD_LINE8, get_value_color(COR_ESQUERDA));
                    NumOut(70, LCD_LINE8, get_value_color(COR_DIREITA));
               }
          }
          Wait(100);
     }
}