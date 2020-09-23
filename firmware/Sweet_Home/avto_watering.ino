
void avto_watering(){
  
    
 time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
 
  int testDay =p_tm->tm_mday;
  int testMon =p_tm->tm_mon+1;
  int testYear=+p_tm->tm_year + 1900; 
    int testHour=p_tm->tm_hour;
  int testMin=p_tm->tm_min;
  int testSec=p_tm->tm_sec;
 
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval>330){
    Serial.println("Water Level: High"); 
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/soilMoisture","high");
      Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","No");
      delay(hour/2);
     }
    else if (resval>300 && resval<=330){ 
        Serial.println("Water Level: Medium");
        Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/soilMoisture","medium");
        Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","No");
        delay(hour/12);
       
            digitalWrite(PIN_RELAY, HIGH);  // Включаем реле - посылаем низкий уровень сигнала
            Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","Yes");
             Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/status","Watering is started");
             
    delay(5000);
  
      digitalWrite(PIN_RELAY, LOW);
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/status","Watering is stop");
      Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","No");
          Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/lastDateWatering",(String)testDay+"/"+testMon+"/"+testYear+"____"+testHour+":"+testMin+":"+testSec);
          
      delay(hour/4);
        }
        else if (resval<=100){ 
    Serial.println("Water Level: Empty");
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/ststus","Sensor didn't work corect");
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","No");
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/soilMoisture","ERROR");
    
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/lastDateWatering",(String)testDay+"/"+testMon+"/"+testYear+"____"+testHour+":"+testMin+":"+testSec);
    }else{
       Serial.println("Water Level: Low");
       Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/soilMoisture","low");
       Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","Yes");
       Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/status","Watering is started");
      digitalWrite(PIN_RELAY, HIGH); // Включаем реле - посылаем низкий уровень сигнала
    delay(5000);
    digitalWrite(PIN_RELAY, LOW);
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/status","Watering is stop");
     Firebase.setString("users/"+stringTwo+"/device/"+deviceId+"/isActivated","No");
  
  }
  delay(1000); 
}
