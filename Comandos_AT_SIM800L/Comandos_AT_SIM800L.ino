/*  Comandos AT SIM800L
 * AT – Verifica que la comunicacion es correcta. contesta con un OK.
 * ATI - Muestra la versión del modulo.
 * AT+CSQ – Calidad de la señal, 0-31.
 * AT+CBC - Regresa el status de la batería, % y voltaje.
 * AT+CMGF=1 - Activa el modo sms.
 * Rafael Lozano Rolon
 * soporte@taloselectronics.com
*/

#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial SIM800L(2, 3);   // Definimos los pines RX y TX del Arduino conectados al Bluetooth

void setup()
{
  SIM800L.begin(115200);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
}

void loop()
{
  if (SIM800L.available())   // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(SIM800L.read());
  }

  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    SIM800L.write(Serial.read());
  }
}
