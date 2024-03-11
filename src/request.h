#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <HTTPClient.h>
#include <Wire.h>

const char* ssid = "JustDiehlWithIt";   //"JustDiehlWithIt";
const char* password = "DiehlWithIt09"; //"DiehlWithIt09";

IPAddress staticIP (192, 168, 43, 56); // Die gewünschte IP-Adresse //IP-Smartphone 192, 168, 43, 68 // IP-Fritzbox 192, 168, 178, 27
IPAddress gateway(192, 168, 43, 1);    // Das Gateway
IPAddress subnet(255, 255, 255, 0);   // Die Subnetzmaske
IPAddress dns(8, 8, 8, 8);

//Fritzbox
// String Host_IP = "192.168.178.26";  //"192.168.178.26";

// //String Date = "";
// const char* serverDate = "http://192.168.178.26/Date";

// //String Time = "";
// const char* serverTime = "http://192.168.178.26/Time";

// String str_Status = "";
// //int sStatus = 2;
// const char* serverStatus = "http://192.168.178.26/Status";

// //String str_Humidity = "";
// const char* serverHumidity = "http://192.168.178.26/Humidity";

// //String str_Temperature = "";
// const char* serverTemperature = "http://192.168.178.26/Temperature";

// const char* serverSend_emergency = "http://192.168.178.26/emergency";

// const char* serverSend_no_emergency = "http://192.168.178.26/no-emergency";

// const char* serverSend_start = "http://192.168.178.26/start";

// const char* serverSend_stop = "http://192.168.178.26/stop";

//Smartphone
String Host_IP = "192.168.43.55";  //"192.168.178.26";

//String Date = "";
const char* serverDate = "http://192.168.43.55/Date";

//String Time = "";
const char* serverTime = "http://192.168.43.55/Time";

String str_Status = "";
//int sStatus = 2;
const char* serverStatus = "http://192.168.43.55/Status";

//String str_Humidity = "";
const char* serverHumidity = "http://192.168.43.55/Humidity";

//String str_Temperature = "";
const char* serverTemperature = "http://192.168.43.55/Temperature";

const char* serverSend_emergency = "http://192.168.43.55/emergency";

const char* serverSend_no_emergency = "http://192.168.43.55/no-emergency";

const char* serverSend_start = "http://192.168.43.55/start";

const char* serverSend_stop = "http://192.168.43.55/stop";

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

void get_data(String *cDate, String *cTime, int *cStatus, String *cHumidity, String *cTemperature) {
  if(WiFi.status()== WL_CONNECTED){ 
    *cDate = httpGETRequest(serverDate);
    *cTime = httpGETRequest(serverTime);
    str_Status = httpGETRequest(serverStatus);
    *cStatus = atoi(str_Status.c_str());
    *cHumidity = httpGETRequest(serverHumidity);
    *cTemperature = httpGETRequest(serverTemperature);
    //Serial.println("Time: " + *cTime + " - Date: " + *cDate);
    // save the last HTTP GET Request
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}

void send_emergency(bool emergency) {
  if(WiFi.status()== WL_CONNECTED){ 
    if (emergency)
    {
      httpGETRequest(serverSend_no_emergency);
    }
    else{
      httpGETRequest(serverSend_emergency);
    }
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}

void send_start() {
  if(WiFi.status()== WL_CONNECTED){ 
      httpGETRequest(serverSend_start);
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}

void send_stop() {
  if(WiFi.status()== WL_CONNECTED){ 
      httpGETRequest(serverSend_stop);
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}