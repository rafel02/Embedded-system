/*
 OM

  Description - Voltage is measure. Adc is use for measuring voltage.
                Voltage is controlled through ADC.

  HW - 1) Pin A0 is for ADC. It is 10 bit ADC.

  Voltage divider combination -
    Input voltage is 5V. 
          R1               R2          Theortical value    Multi Measure value
                                        ( Volt at R2 )
    1)   1k              22o ohm        0.9                               OK
    2) 1 MOhm,          750 KOhm        2.1 V               1.7 V         OK
    3) 1 k              1k+100Ohm      2.6 v                             OK
    4) 8 Ohm              22 ohn         3.6                3.5           ok
    5) 220 ohm            6 kohm        4.8 v                             OK

    x2) R1 = 750 ohm, R2 = 6 KOhm     4.4 v
    
    4) 220 ohm            100 ohm    1.5 v
    x5) 320 ohm            100 ohm    1.1 v

 Reference - Analog Input example
 https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;   // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
float AnlogVal[10];
float sum =0;

int i = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  //pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  for ( i =0; i< 3; i++)
  {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    // turn the ledPin on
    //digitalWrite(ledPin, HIGH);
    // stop the program for <sensorValue> milliseconds:
    //delay(sensorValue);


    //Serial.print("digital value = ");
    //Serial.println(sensorValue);        //print digital value on serial monitor
    
    //convert digital value to analog voltage
    AnlogVal[i] = (sensorValue * 5.00)/1023.00;
    //Serial.print("  analog voltage = ");
    //Serial.println(AnlogVal[i]);
    
  
    delay(1000);
  }

  for ( i=0 ; i< 3; i++)
  {
    sum = AnlogVal[i] + sum;
  }

  sum = sum/3;
  //Serial.println ( "Voltage at R2 resi =");
  //Serial.println(sum);

  if ( sum < 0.5 )
  {
    Serial.println( "No stick detected");
  }
  if ( sum > 0.5 && sum <= 1)
  {
    Serial.println( "Stick varient is 1");
  }
  if ( sum > 1 && sum <= 2)
  {
    Serial.println( "Stick varient is 2");
  }
  else if ( sum > 2 && sum <= 3)
  {
    Serial.println( "Stick varient is 3");
  }
  else if ( sum > 3 && sum <= 4)
  {
    Serial.println( "Stick varient is 4");
  }
  else if ( sum > 4 && sum < 5)
  {
    Serial.println( "Stick varient is 5");
  }

  sum = 0;
  delay(2000);
}
