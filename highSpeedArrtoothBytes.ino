int T = 4;
int i;
unsigned int d;
bool appKnowsSensorTypes;
byte sensorTypes = 3;
byte appSignal;

void setup() {

  // put your setup code here, to run once:

//AT+BAUD5
  Serial.begin(57600); //baud of BT module  
}

void loop() {
  if (Serial.available() > 0){
        Serial.write(sensorTypes);
        appKnowsSensorTypes = true;
  }
  
  if (appKnowsSensorTypes){

      Serial.write(4); //sends a id that reads as either 1024+2 or 2048+3
      Serial.write(5);
      Serial.write(6);
  
    for (i = 0; i < sensorTypes; i++){
      d = i;
      write2Bytes(d);
    } 
  }
        delay(T);
}

void write2Bytes(unsigned int bb){
  Serial.write(highByte(bb));
  Serial.write(lowByte(bb));
}
