 #include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>       
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
  
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  
#include <EEPROM.h>
//#define FIREBASE_HOST "ionkid-abd2f.firebaseio.com"
//#define FIREBASE_AUTH "12Bs4sG60U96pN0VqAYxIRzKmo55omcTIUPejNZF"
// set the LCD number of columns and rows
  


 
//Function Decalration

 
//Establishing Local server at port 80 whenever required
 ESP8266WebServer server(80);
 

String st;
String content;
bool testWifi(void);
void launchWeb(void);
void setupAP(void);
void setup() { 
  Serial.begin(9600);
   Serial.println();
  Serial.println("Disconnecting previously connected WiFi");
  WiFi.disconnect();
  EEPROM.begin(512); //Initialasing EEPROM
  delay(10);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println();
  Serial.println();
  Serial.println("Startup");
 
  //---------------------------------------- Read EEPROM for SSID and pass
  Serial.println("Reading EEPROM ssid");
 
  String esid;
  for (int i = 0; i < 32; ++i)
  {
    esid += char(EEPROM.read(i));
  }
  Serial.println();
  Serial.print("SSID: ");
  Serial.println(esid);

  
  Serial.println("Reading EEPROM pass");
  String epass = "";
  for (int i = 32; i < 64; ++i)
  {
    epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass);

Serial.println("Reading EEPROM userID");
  String eUserID = "";
  for (int i = 64; i < 96; ++i)
  {
    eUserID += char(EEPROM.read(i));
  }
  Serial.print("USER_ID: ");
  Serial.println(eUserID);

Serial.println("Reading EEPROM deviceID");
  String eDeviceID = "";
  for (int i = 96; i <128; ++i)
  {
    eDeviceID += char(EEPROM.read(i));
  }
  Serial.print("DEVICE_ID: ");
  Serial.println(eDeviceID);
 
  WiFi.begin(esid.c_str(), epass.c_str());
  if (testWifi())
  {
    Serial.println("Succesfully Connected!!!");
     Serial.println(WiFi.localIP());
    
 
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  if(WiFi.isConnected()){
     
   Serial.println("STATUS:200");
    }else{
    Serial.print("STATUS:404");
    }
    
    //  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    return;
  }
  else
  {
    Serial.println("Turning the HotSpot On");
    launchWeb();
    setupAP();// Setup HotSpot
  }
 
  Serial.println();
  Serial.println("Waiting.");
  
  while ((WiFi.status() != WL_CONNECTED))
  {
    Serial.print(".");
    delay(100);
    server.handleClient();
  }
  
}
  
  
/*
int increment=0;
int n = 0;
int isChecked;
String isActivated;
String user;*/
void loop() {
  /*
  if( isChecked==0){
   user= Firebase.getString("Arduino/ActivateCode/User");
isActivated= Firebase.getString("Arduino/ActivateCode/Activate");
 isChecked=1;
    }
    noise_sensor();
  irValue = particleSensor.getIR();
 if( isActivated=="1"){
 heart_rate();
 } else{
   
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("STATUS:404");
 }
increment++;*/
}


 