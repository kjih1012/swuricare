#include <WiFi.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

//POST Data Set//
String jsondata = "";

StaticJsonBuffer<200> jsosBuffer;
JsonObject& root = jsonBuffer.createObject();
root["finedustvalue"] = finedust;

root.printTo(jsondata);
Serial.println(jsondata);



char ssid[] = "AndroidHotspot6971";      //  연결하실 와이파이 SSID
char pass[] = "00001111";   // 네트워크 보안키
int status = WL_IDLE_STATUS;

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 5000L;

String rcvbuf;
boolean getIsConnected = false;

IPAddress hostIP(172, 30, 1, 30);
int SERVER_PORT = 8000;

WiFiClient client;

void setup() {
  Serial.begin(9600); 

  if (WiFi.status() == WL_NO_SHIELD) { // 현재 아두이노에 연결된 실드를 확인
    Serial.println("WiFi shield not present"); 
    while (true);  // 와이파이 실드가 아닐 경우 계속 대기
  }  else{
    Serial.println("wifi shield is load...");
  }

  Serial.print(F("Firmware version: "));
  Serial.println(WiFI.firmwareVersion());

  // 와이파이에 연결 시도
  if ( status != WL_CONNECTED) { //연결될 때까지 반복
    Serial.print("Couldn't get a wifi connection");
    while(true);
  } 
  else {

  server.begin();

  printWifiStatus();  // 연결 성공시 연결된 네트워크 정보를 출력
}

void loop() {
  // put your main code here, to run repeatedly:

}
