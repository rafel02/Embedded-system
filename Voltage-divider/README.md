# Voltage-divider
Measure voltage in voltage divider network


Voltage divider network is to measure voltage across a resistor in a circuit. This is use for circuit analysis.
The load is a resistor. A know resistor is add in series with load. Voltage consumption across load is find.

Formula -  Vout = Vin * R2 / ( R1 + R2 )

# About project

Hardware - Arudino mega mini 2560
MCU - Atmega 2560
IDE - Arudino 2.3.4

Arudio have 5 ADC pin. ADC input voltage is 0 - 5V. ADC resolutionis 10 bit. Digital value range 
is from 0 to 2^10 (1023).  Resoultion is Vmax/ AdcRang. Digital input is Vin / Resolution .

** Digital value covert to voltage **

Formula for voltage calculation -

ADC value is digital value for input voltage. This value is to change to voltage. Formula for 
change input value to voltage is Aout = digital value * (Vref/2^n – 1).

Example -

Digital value = 512 and ADC is 10-bit with 5V Vref. But, we want to know that for what analog voltage it is giving respective digital value. Then,

Aout = 512 * (5 V / 1023)  = 2.5 V
