
int T = 2;
int i;
String str = " 120,  32, 999, 520";// 
byte delim = 0;
unsigned int val[] = {13, 15, 17, 111, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
float f = 100;

void setup() {

  // put your setup code here, to run once:

//AT+BAUD5
  Serial.begin(115200); //baud of BT module  
}

void loop(){

    for (float s = 0; s < f; s++){
        val[0] = (unsigned int) f*sqrt(s);
        val[1] = (unsigned int) 300+150*sin(s*2*3.14/f);
        val[2] = (unsigned int) (pow(2.7, s/f)*f);
        val[3] = (unsigned int) s;
        valToStr();
        textMessage();
        delay(T);  
    }

}

void textMessage(){
  Serial.print('<');
  for (i = 0; i < str.length(); i++){
      Serial.print(str.charAt(i));  
  }
  Serial.print('>');
  Serial.write(delim);
}

void valToStr(){
  str = String(val[0]);
  for (i = 1; i < sizeof(val)/2; i++){
    str = String(str + "," + String(val[i]));  
  }
}



