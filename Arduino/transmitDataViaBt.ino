

  const int sensorPins[] = {A0};
   
  unsigned int val[1]; // the analog value read from the sensors, which are then mapped, sent as two bytes, then read as two bytes
  unsigned int border = 4 + 1024; // or 2^2 + 2^2*2^8 if looking at the bytes. since all other sent numbers are in the range [0, 1023] this int can be found 
  int ledPin = 5; // id for the led pin used for control
  int T = 15; //time in ms between data transmissions
  // to generate a smooth sine signal
  bool appReady = false;
  
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //for transmission
  
  for (int i = 0; i < sizeof(sensorPins)/ sizeof(int); i++){ // sensors
    pinMode(sensorPins[i], INPUT);
  }

  pinMode(ledPin, OUTPUT); // control LED
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.write(4);
  Serial,write(5);
  Serial.write(6); 

   for (int i = 0; i < sizeof(val); i++){
      val[i] = analogRead(sensorPins[i]); 
      write2Bytes(val[i]); 
   }
   actOnValues(); //alters the data and performs some action based on it  
   
    delay(T); //delay between data sends so as not to miss any data    
  }
  else{
    if (Serial.available() > 0 ){
      if ( Serial.read() == 1){
        appReady = true;
      }
    }
  }
}


void actOnValues(){ //lights an LED
  analogWrite(ledPin, map(val[1], 0, 1023, 0, 255)); // from potentiometer angle to byte for the led, first value up the the seperator  
}

void write2Bytes(unsigned int bb){
  Serial.write(highByte(bb));
  Serial.write(lowByte(bb));
}




