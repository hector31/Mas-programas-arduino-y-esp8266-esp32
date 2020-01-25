/*
 * AskSensors HTTP Request
 * Description: Connect ESP8266 to AskSensors over HTTP
 *  Author: https://asksensors.com, 2018-2019
 *  github: https://github.com/asksensors/AskSensors-ESP8266-API
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Ticker.h>
#include <ESP8266HTTPClient.h>

#define WIFI_SSID           "SIEEC.ING-FLIA NARVAEZ"
#define WIFI_PASSWORD       "gladys27534498"
#define MAX_LOOP_TIME_MS     10000
// user config: TODO
const char* wifi_ssid = "SIEEC.ING-FLIA NARVAEZ";             // SSID
const char* wifi_password = "gladys27534498";         // WIFI
const char* apiKeyIn = "NuLRs01uLLeEKODKHmxSdLqdx8R7e32y";      // API KEY IN
const unsigned int writeInterval = 25000;   // write interval (in ms)
// sensor capactivo
const int AirValue = 810;   //you need to replace this value with Value_1
const int WaterValue = 385;  //you need to replace this value with Value_2
int intervals = (AirValue - WaterValue)/3;
int porcentaje;
int soilMoistureValue = 0;
// ASKSENSORS config.
String host = "http://api.asksensors.com";         // ASKSENSORS API host name
// bomba agua
int bomba_agua=5;  

ESP8266WiFiMulti WiFiMulti;
unsigned long startTime;
Ticker sleepTicker;

void sleepyTime() {
  const int elapsed = millis() - startTime;
  Serial.printf("Sleeping. Loop took %d ms\n", elapsed);
  // If this sleep happened because of timeout, clear the
  // Wifi state.
  if (elapsed >= MAX_LOOP_TIME_MS) {
    WiFi.disconnect();
  }
  Serial.println("I'm awake, but I'm going into deep sleep mode for 30 seconds");
  ESP.deepSleep(30e6, WAKE_RF_DEFAULT);
    
  // It can take a while for the ESP to actually go to sleep.
  // When it wakes up we start again in setup().
  delay(5000);
}
void medida(){
    if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
    {
      Serial.println("\nVery Wet");
      Serial.println((String)"Porcentaje:"+porcentaje+"%");
    }
    else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
    {
      Serial.println("\nWet");
      Serial.println((String)"Porcentaje:"+porcentaje+"%");
    }
    else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
    {
      Serial.println("\nDry");
      Serial.println((String)"Porcentaje:"+porcentaje+"%");
      Serial.println("\nEncendiendo bomba de agua espere.........");
      digitalWrite(bomba_agua, HIGH);   
      delay(3000);                      
      digitalWrite(bomba_agua, LOW);  
    }
    Serial.println("I'm awake, but I'm going into deep sleep mode for 30 seconds");
    ESP.deepSleep(3600e6); 
}
void waitForWifi() {
  Serial.print("Connecting to WiFi.");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" Done");
  Serial.println("ESP8266 Weather Sensor");
  Serial.printf("Connected to %s\n", WIFI_SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  pinMode(bomba_agua, OUTPUT);
  startTime = millis();
  sleepTicker.once_ms(12000, &medida);
  Serial.begin(115200);
  Serial.println("*****************************************************");
  Serial.println("\n***************************--------INCIO--------*************************");
  Serial.println("********** Program Start : Connect ESP8266 to AskSensors over HTTP");
  Serial.println("Wait for WiFi... ");
  Serial.print("********** connecting to WIFI : ");
  Serial.println(wifi_ssid);

  if (WiFi.SSID() != WIFI_SSID) {
  WiFi.begin(wifi_ssid, wifi_password);
  WiFi.persistent(true);
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);
  //while (WiFi.status() != WL_CONNECTED) {
   // delay(500);
   // Serial.print(".");
  //}

  } else {
    Serial.println("Using saved wifi info...");
  }
   soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  porcentaje=map(soilMoistureValue,AirValue,WaterValue,0,100);
 
}


void loop() {
    // wait for WiFi connection
    waitForWifi();
  if (WiFi.status() == WL_CONNECTED){

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        
        // Create a URL for the request
        String url = "";
        url += host;
        url += "/write/";
        url += apiKeyIn;
        url += "?module1=";
        url += porcentaje;
        
        Serial.print("********** requesting URL: ");
        Serial.println(url);
        http.begin(url); //HTTP
        
        Serial.println("> Request sent to ASKSENSORS");

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();

        Serial.println("********** End ");
        Serial.println("*****************************************************");
    }
    medida();
}
