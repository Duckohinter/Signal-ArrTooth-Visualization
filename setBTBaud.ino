void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //this Baud rate (byte frequency) needs to be set as to match the set Baud rate that the Bluetooth module currently, and just previously, operates on. 
}

void loop() {
  //Serial.print("AT+BAUD4"); //communicate with the bluetooth module, set to 9600, for more information see for example https://www.instructables.com/id/AT-command-mode-of-HC-05-Bluetooth-module/

}
