#include<ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"            
#include "html.h"
const int DHTPIN = 4;      
const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);
float nhietdo;
float doam;
const String tenwifi="ToanManh";
const String mkwifi="11223344";
ESP8266WebServer server(80); //webserver chay mac dinh tren post 80
void ketnoi() {
 
  server.send(200, "text/html", webpage);
}
void docdulieunhietdo(){
  nhietdo = dht.readTemperature(); 
  String snhietdo=String(nhietdo);
  server.send(200, "text/plain", snhietdo);
}
void docdulieudoam(){
  nhietdo = dht.readHumidity();
  String sdoam =String(nhietdo);
  server.send(200, "text/plain", sdoam);
}
void setup() {
  Serial.begin(115200);
  pinMode(DHTPIN,INPUT);
  dht.begin();
  WiFi.begin(tenwifi, mkwifi);           // Kết nối vào mạng WiFi
  Serial.print("Ket noi toi ");
  Serial.print(tenwifi);
  // Chờ kết nối WiFi được thiết lập
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\n");
  Serial.println("ket noi hoan tat");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());       // Gởi địa chỉ IP đến máy tinh
  server.on("/", ketnoi);           // Gọi hàm main khi nhận được truy vấn GET cho URI = "/"
  server.on("/docnhietdo", docdulieunhietdo);
  server.on("/docdoam", docdulieudoam);
  server.begin();
}

void loop() {
    server.handleClient();
}



