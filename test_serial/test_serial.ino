
#define rx          17                            //define what pin rx is going to be
#define tx          16                           //define what pin tx is going to be

HardwareSerial portMUX(1);

void setup() {                                        //set up the hardware
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  portMUX.begin(9600, SERIAL_8N1, rx, tx);
}

//added changes in this line of code
void loop() {                                         //here we go...

  String temp = "";
  char sensorstring_array[30];                        //we make a char array

  while (Serial.available())
    portMUX.write(Serial.read());
  delay(1000);
  while (portMUX.available())
  {
    temp += (char)portMUX.read();
  }
  Serial.print("Val: ");
  Serial.println(temp);
}
