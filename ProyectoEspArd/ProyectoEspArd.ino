//https://mydevices.com/cayenne/docs-2/bring-your-own-thing-api/#bring-your-own-thing-api-supported-data-types

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "ssid";
char wifiPassword[] = "wifiPassword";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "MQTT_USERNAME";
char password[] = "MQTT_PASSWORD";
char clientID[] = "CLIENT_ID";

unsigned long lastMillis = 0;
//-----------------------------
const int Led_01 = 14;
const int LedPWM = 12;
//-----------------------------
int ValorADC = 0;
int MyTemperatura = 0;
float PorcentajeCo2 = 14.56;
//-----------------------------

void setup() {
  //--------------------------
  pinMode(Led_01, OUTPUT);
  pinMode(LedPWM, OUTPUT);
  //--------------------------
	Serial.begin(9600);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();

	//Publish data every 10 seconds (10000 milliseconds). Change this value to publish at a different interval.
	if (millis() - lastMillis > 10000) {
		lastMillis = millis();

    //-----------------------------
    ValorADC = analogRead(A0);  
    MyTemperatura = map(ValorADC, 0, 1023, 0, 100);
    
    //Write data to Cayenne here. This example just sends the current uptime in milliseconds.
    Cayenne.virtualWrite(0 , MyTemperatura , TYPE_TEMPERATURE , UNIT_CELSIUS);
    Cayenne.virtualWrite(1 , ValorADC);
    Cayenne.virtualWrite(2 , PorcentajeCo2);

    PorcentajeCo2 = PorcentajeCo2 + 4.72;
    if(PorcentajeCo2>100){PorcentajeCo2=0;}
    //-----------------------------
    
		//Write data to Cayenne here. This example just sends the current uptime in milliseconds.
		//Cayenne.virtualWrite(0, lastMillis);
		//Some examples of other functions you can use to send data.
		//Cayenne.celsiusWrite(1, 22.0);
		//Cayenne.luxWrite(2, 700);
		//Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
	}
}

CAYENNE_IN(3)
{ 
   int Valor_Canal_03 = getValue.asInt();
   digitalWrite(Led_01, Valor_Canal_03);
}

CAYENNE_IN(4)
{ 
   int MySlider = getValue.asInt();
   analogWrite(LedPWM, MySlider);
   /*
   if (x_valor_1){Serial.println("Mensaje 1");}
   if (x_valor_2){Serial.println("Mensaje 2");}
   if (x_valor_3){Serial.println("Mensaje 3");} 
   */
}

/*
//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
*/
