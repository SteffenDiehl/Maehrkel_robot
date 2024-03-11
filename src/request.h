#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <HTTPClient.h>
#include <Wire.h>

const char* ssid = "JustDiehlWithIt";   //"JustDiehlWithIt";
const char* password = "DiehlWithIt09"; //"DiehlWithIt09";

//Fritzbox
IPAddress staticIP (192, 168, 178, 27); // Die gewünschte IP-Adresse //IP-Smartphone 192, 168, 43, 68 // IP-Fritzbox 192, 168, 178, 27
IPAddress gateway(192, 168, 178, 1);    // Das Gateway
//Smartphone
IPAddress staticIP (192, 168, 43, 69); // Die gewünschte IP-Adresse //IP-Smartphone 192, 168, 43, 68 // IP-Fritzbox 192, 168, 178, 27
IPAddress gateway(192, 168, 43, 1);    // Das Gateway

IPAddress subnet(255, 255, 255, 0);   // Die Subnetzmaske
IPAddress dns(8, 8, 8, 8);

String str_Status = "";

//Fritzbox

String Host_IP = "192.168.178.26";

const char* serverDate = "http://192.168.178.26/Date";

const char* serverTime = "http://192.168.178.26/Time";

const char* serverStatus = "http://192.168.178.26/Status";

const char* serverHumidity = "http://192.168.178.26/Humidity";

const char* serverTemperature = "http://192.168.178.26/Temperature";

const char* serverSend_emergency = "http://192.168.178.26/emergency";

const char* serverSend_no_emergency = "http://192.168.178.26/no-emergency";

//Smartphone

// String Host_IP = "192.168.43.68";

// const char* serverDate = "http://192.168.43.68/Date";

// const char* serverTime = "http://192.168.43.68/Time";

// const char* serverStatus = "http://192.168.43.68/Status";

// const char* serverHumidity = "http://192.168.43.68/Humidity";

// const char* serverTemperature = "http://192.168.43.68/Temperature";

// const char* serverSend_emergency = "http://192.168.43.68/emergency";

// const char* serverSend_no_emergency = "http://192.168.43.68/no-emergency";

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

void send_data(bool emergency) {
  if(WiFi.status()== WL_CONNECTED){ 
    if (emergency)
    {
      httpGETRequest(serverSend_emergency);
    }
    else{
      httpGETRequest(serverSend_no_emergency);
    }
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}