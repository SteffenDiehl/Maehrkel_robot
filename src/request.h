#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <HTTPClient.h>
#include <Wire.h>

const char* ssid = "JustDiehlWithIt";   //"JustDiehlWithIt";
const char* password = "DiehlWithIt09"; //"DiehlWithIt09";

IPAddress staticIP (192, 168, 178, 27); // Die gewünschte IP-Adresse //IP-Smartphone 192, 168, 43, 68 // IP-Fritzbox 192, 168, 178, 27
IPAddress gateway(192, 168, 178, 1);    // Das Gateway
IPAddress subnet(255, 255, 255, 0);   // Die Subnetzmaske
IPAddress dns(8, 8, 8, 8);

String Host_IP = "192.168.178.26";  //"192.168.178.26";

String Date = "";
const char* serverDate = "http://192.168.178.26/Date";

String Time = "";
const char* serverTime = "http://192.168.178.26/Time";

String str_Status = "";
int sStatus = 2;
const char* serverStatus = "http://192.168.178.26/Status";

String str_Humidity = "";
float Humidity = 0;
const char* serverHumidity = "http://192.168.178.26/Humidity";

String str_Temperature = "";
float Temperature = 0;
const char* serverTemperature = "http://192.168.178.26/Temperature";

int *web_status = nullptr;

String httpGETRequest(const char* server_request) {
  WiFiClient client;
  HTTPClient http; // Use HTTPClient instead of HttpClient
    
  // Your Domain name with URL path or IP address with path
  http.begin(server_request); // You don't need to pass the client here
  
  // Send HTTP GET request
  int httpResponseCode = http.GET();
  
  String payload = ""; // Initialize payload as an empty string
  
  if (httpResponseCode == HTTP_CODE_OK) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else if (server_request == serverStatus)
  {
    payload = "2";
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    payload = "Error"; // You can set payload to some default value on error
  }
  // Free resources
  http.end();

  return payload;
}

void setup_wifi() {
  // Initialize SPIFFS
  #ifdef ESP32
    if(!SPIFFS.begin(true)){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
    }
  #else
    if(!SPIFFS.begin()){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
    }
  #endif

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }
  WiFi.config(staticIP, gateway, subnet, dns);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
void get_data(String* cDate, String* cTime, int* cStatus) {
  if(WiFi.status()== WL_CONNECTED ){ 
    Date = httpGETRequest(serverDate);
    Time = httpGETRequest(serverTime);
    str_Status = httpGETRequest(serverStatus);
    sStatus = atoi(str_Status.c_str());
    Serial.println("Time: " + Time + " - Date: " + Date);
    *cDate = Date;
    *cTime = Time;
    *cStatus = sStatus;

    // save the last HTTP GET Request
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}
