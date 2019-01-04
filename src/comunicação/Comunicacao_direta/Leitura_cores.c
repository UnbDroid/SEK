#include "Funcoes_testadas/comunicacao.h"

/* Funcoes de mostrar na tela do Takashi */

sub ShowColor(int l_value, int r_value, int color)
{
	ClearScreen();
	/*TextOut(40, LCD_LINE4, "LEFT");
	TextOut(70, LCD_LINE4, "RIGHT");
	TextOut(0, LCD_LINE4, "COLOR:");
	if(color == VERMELHO){
		TextOut(0, LCD_LINE6, " RED ");
	}else if(color == VERDE){
		TextOut(0, LCD_LINE6, "GREEN");
	}else if(color == AZUL){
		TextOut(0, LCD_LINE6, " BLUE");
	}else{
		TextOut(0, LCD_LINE6, "WHITE");
	}*/
	/* Esta comentado pois essa parte nao consigo compilar e passar ao cerebro */
	NumOut(40, LCD_LINE6, l_value);
	NumOut(70, LCD_LINE6, r_value);
	Wait(100);
}

/* Fim das funcoes do takashi */


task main()
{
	int left, right;
	int i = 0;
	char cores[3] = {VERMELHO, VERDE, AZUL};
	
	BTCheck(BT_CONN); // Checa a conexao

	SetSensorTouch(TOUCH); // Liga o sensor touch

	Wait(100);
	RemoteSetInputMode(BT_CONN, COR_ESQUERDA, SENSOR_TYPE_COLORRED, SENSOR_MODE_RAW); // Liga o sensor esquerdo de cor
	Wait(25);
	RemoteSetInputMode(BT_CONN, COR_DIREITA, SENSOR_TYPE_COLORRED, SENSOR_MODE_RAW);  // Liga o sensor direito de cor
	while(true)
	{
		if(Sensor(TOUCH) == 1)
		{
			i += 1;
			i %= 3;
			set_sensor_color(COR_ESQUERDA, cores[i]);
			Wait(25);
			set_sensor_color(COR_DIREITA, cores[i]);
			while(Sensor(TOUCH) == 1)
			{
				Wait(100);
			}
		}
		left = get_value_color(COR_ESQUERDA);
		right = get_value_color(COR_DIREITA);
		ShowColor(left, right, cores[i]);
		Wait(100);
	}
}