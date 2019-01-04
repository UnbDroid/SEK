#define BT_CONN 1 // Numero da porta BlueTooth

#define MOTOR_PORTA OUT_B
#define COR_ESQUERDA IN_4
#define COR_DIREITA IN_1

#define SENSOR_US_ESQUERDA IN_3
#define SENSOR_US_DIREITA IN_2
#define SENSOR_GYRO IN_1
#define TOUCH IN_4

#define PRETO 1
#define AZUL 2
#define VERDE 3
#define AMARELO 4
#define VERMELHO 5
#define BRANCO 6

sub BTCheck(int conn){
     if (!BluetoothStatus(conn)==NO_ERR){
          ClearScreen();
          TextOut(5,LCD_LINE2,"Erro");
          Wait(1000);
          Stop(true);
      }
}

void set_sensor_color(char porta, char color)
{
     if(color == VERMELHO){
          RemoteSetInputMode(BT_CONN, porta, SENSOR_TYPE_COLORRED, SENSOR_MODE_RAW);
     }else if(color == VERDE){
          RemoteSetInputMode(BT_CONN, porta, SENSOR_TYPE_COLORGREEN, SENSOR_MODE_RAW);
     }else if(color == AZUL){
          RemoteSetInputMode(BT_CONN, porta, SENSOR_TYPE_COLORBLUE, SENSOR_MODE_RAW);
     }else if(color == BRANCO){
          RemoteSetInputMode(BT_CONN, porta, SENSOR_TYPE_COLORFULL, SENSOR_MODE_RAW);
     }
}

int get_value_color(char porta)
{
     InputValuesType params;

     params.Port = porta;
     RemoteGetInputValues(BT_CONN, params);

     return params.RawValue;
}