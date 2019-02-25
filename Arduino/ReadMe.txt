The arduino code (.ino format) that was created in the development of this project. 
Intended to be used with a bluetooth module (set Baud rate with supplied setBTBaud code). 

The resulting code that can be used with the app is transmitTextDataViaBT version 2 and version 3. 

This code performs analogRead(pin: A0) and creates a message in suitable form for transmission. 
The arduino communicates via digital channels to the bluetooth module, 
with online transmission of these data messages to a running app with bluetooth connection. 
Depending on version, the analog sampling varies which yields different temporal resolutions. 
TransmitTextDataViaBt version 3 quickly reads and 
transmits 1000 data points (no delay except a for-loop) and then waits (3*1000 ms) before repeating in loop(). 
This delay() is necessary for the app to process and visualize the data. 
On the other hand, TransmitTextDataViaBt version 2 does analogRead() once, 
sends this single value, and waits 1200 microseconds for allowing the app to “catch up“ (might vary depending on smartphone) 
so the temporal resolution is lowered, but the data points are more equally distanced in time. 
