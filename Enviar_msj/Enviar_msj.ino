#include <SoftwareSerial.h>
#define Gsm_tx 2
#define Gsm_rx 3

SoftwareSerial MOD_SIM800L(Gsm_tx, Gsm_rx);
String Numero_cliente = "3334874861";

void setup()
{
  Serial.begin(9600); 
  MOD_SIM800L.begin(115200);
  Enviar_msj(Numero_cliente, "Inicializacion completa");
}
void loop()
{
  
}
void Enviar_msj(String numero, String msj)
{
  //Se establece el formato de SMS en ASCII
  String config_numero = "AT+CMGS=\"+52" + numero + "\"\r\n";
  Serial.println(config_numero);

  //configurar modulo como modo SMS
  MOD_SIM800L.write("AT+CMGF=1\r\n");
  delay(1000);
  
  //Enviar comando para un nuevos SMS al numero establecido
  MOD_SIM800L.print(config_numero);
  delay(1000);

  //Enviar contenido del SMS
  MOD_SIM800L.print(msj);
  delay(1000);

  //Enviar Ctrl+Z
  MOD_SIM800L.write((char)26);
  delay(1000);
  Serial.println("Mensaje enviado");
}
