#include<WiFi.h>
#include<HTTPClient.h>
#include <DHT11.h>

const char* ssid = "Desktop";
const char* password = "11223344";
const char* servername = "https://script.google.com/macros/s/AKfycbzH_--TH8CZLJCNremvIJCQPzIQAvr-JhOrrpRXTN0RtDleCf0O7kJwzCCzPI4nExYs/exec";
DHT11 dht11(2);;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(ssid,password);
Serial.print("Connecting...");
while (WiFi.status() != WL_CONNECTED){
  Serial.println(".");
}
Serial.println("Connected!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED){
HTTPClient http;
http.begin(servername);
http.addHeader("Content-Type","application/json" );

float temp = dht11.readTemperature();
float humid = dht11.readHumidity();
float moistur = analogRead(4);
float moist = map(moistur, 0, 1023, 0, 100);

String Json_data = "{\"temperature\":" + String (temp, 1) + " \"humidity\":" + String(humid,1) + "\"moisture\":" + String(moist,1) + "}";
int http_response = http.POST(Json_data);
Serial.println(http_response);
http.end();
}
else{
  Serial.println("WiFi disconnected");
}
delay(60000);
}
