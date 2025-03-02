Driver program with 8051 microcontroller

I2C is inter integrated circuit. It is made by NXP semicondutor. Communication with I2C is bidirectional. Two line is use for communication. Lines are SDA ( Serial data line ) and SCL ( Serial clock line ). These line are pulled up by resistor. In this protocol there is a master and a slave. Operating voltage is 3.3 V and 5 V.

In this project I interface a EEPROM with microcontroller.
EEPROM is a programable memory. It can be erase. It store
data even after power supply is stop. EEPROM is a slave 
device. There can be multiple slave device. The micro-
controller is the master.

Microcontroller control the communication. Mcu control clock.
Slave device have address. Different slave have different
address. Other I2C peripherals are LCD, memory card, keyboard.

Following function are involve in I2C protocol.

1. Start
2. Stop
3. Read byte
4. Write byte

** Write Mode **

1. Send the START command from the Master.
2. Send Device (EEPROM) Address with write-command.
3. Send Register address in Device (EEPROM), Where we have to access.
4. Send the Data to the Device (EEPROM).
5. If you want to send more than one byte, keep sending that byte.
6. Finally, Send the STOP command. 

** Read Mode **

1. Send the START command from the Master.
2. Send Device (EEPROM) Address with write-command.
3. Send Register address in Device (EEPROM), Where we have to access.
4. Send again START command or Repeated START command.
5. Send Device address with Reading mode.
6. Read the data from Device (EEPROM).
7. Finally, Send the STOP command.

** START Command **

1. Initially, SDA and SCL are High.
2. SDA first goes to Zero.
3. Then SCL goes to Zero.

** STOP Command **

1. Initially, SDA and SCL are High.
2. SDA first goes to Zero.
3. Then SCL goes to Zero.

Reference 
[1] https://www.elprocus.com/i2c-interface-to-eeprom-with-8051-microcontroller/#:~:text=This%20article%20helps%20you%20to%20understand%20how%20to,sample%20source%20code%20in%20C%20for%20I2C%20interface.
[2] https://embeddedflakes.com/8051-i2c-communication-guide/