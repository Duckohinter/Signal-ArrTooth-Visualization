

  const int sensorPins[] = {A0};  
  volatile unsigned int val[sizeof(sensorPins)/sizeof(int)]; // the analog value read from the sensors, which are then mapped, sent as two bytes, then read as two bytes
  String messageToApp; //this is the message 

  int T = 1200; //delay in ms between data transmissions which gives time for the app to plot data. T can be lowered if more sensors are plugged in since it takes about 0.1 ms to analogRead(pin) 
  int i;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //baud of BT module
  
  for ( i = 0; i < sizeof(sensorPins)/ sizeof(int); i++){ // sensors
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

    for (i = 0; i < sizeof(sensorPins)/sizeof(int); i++){ //get data
      val[i] = analogRead(sensorPins[i]);   
    }

    
    //valToStr();  //prep data for sending as text
    sendTextMessage(); //send <messageToApp>
    delayMicroseconds(T); //pause for app to catch up
}

void sendTextMessage(){
  Serial.print('<'); // used to set appart different values
  Serial.print(String(val[0]));  
  Serial.print('\n'); //easier to remove, and does not need joining
}

void valToStr(){
  messageToApp = String(val[0]);
  
  for (i = 1; i < sizeof(val)/2; i++){
    messageToApp = String(messageToApp + "," + String(val[i]));  //csv row format so that the text can easily be turned into a list in the app  
  }
}




