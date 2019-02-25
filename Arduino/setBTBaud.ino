
// all the code needed for changing the Baud Rate of your Bluetooth HC-06 module, if you know the baud rate and AT+BAUDX commands
void setup() {
  
  Serial.begin(115200); //this Baud rate (byte frequency) needs to be set as to match the set Baud rate that the Bluetooth module currently, and just previously, operates on. 
  //For a new HC-06 module, the default Baud-Rate is 9600
}

void loop() {
  //Serial.print("AT+BAUD4"); //communicate with the bluetooth module via Strings, set to 9600, for more information see for example https://www.instructables.com/id/AT-command-mode-of-HC-05-Bluetooth-module/
  

}

//AT+BAUDX sets baud rate corresponding to X in 1-9 below
//1 set to 1200bps
//2 set to 2400bps 
//3 set to 4800bps 
//4 set to 9600bps (Default) 
//5 set to 19200bps 
//6 set to 38400bps 
//7 set to 57600bps 
//8 set to 115200bps
