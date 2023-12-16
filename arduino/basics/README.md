# Arduino and Python / Matlab
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to communicate with an Arduino from Python / Matlab. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Get the environment ready
Before we can really interact with the Arduino board, we need to make the environment ready first:

Download and install the Arduino IDE.
Connect the Arduino via USB cable to the computer.
Open the Arduino IDE.
Open the Blink example. Files -> Examples -> 01. Basics -> Blink
Check the setting: Tools-> Board and  Tools->Port
Get the board information as a test: Tools -> Get Board Info
Upload the sketch (means source code)


The Arduino led should blink now.

If you use Python for controlling the Arduino, make sure that the serial package is installed:

pip install pyserial
WARNING: If you open a communication channel with Python / Matlab then a reset signal is created that resets the Arduino. Thus only open the communication once and keep it open as long as you require a connection to the Arduino.

In the case that you are a VS code user, you want to add the Microsoft Arduino extension to VS code for editing the Arduino ino files in style and not like a caveperson with the Arduino IDE:



 

Controlling the LED 
We want to control the LED on the Arduino board via an external software.

Note: I see it as a good style to make sure that we communicate in a fashion that reduces misunderstandings. Thus I will start any control sequence with the integer value 60 (the < symbol in ASCII) and end it with the integer value 62 (the > symbol in ASCII). The source code is prepared to handle up to 32x 8 bit integer values as payload. However we will only evaluate the value at index 0 in the switch case construct.

The Arduino sketch
int rc;
boolean recvInProgress = false;

int startMarker = 60; // <
int endMarker = 62; // >

int numChars = 32;
int receivedChars[32];

int index = 0;
int Used = 0;

boolean newData = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {

  if ((Serial.available() > 0) && (newData == false)) {

    rc = Serial.read();

    if ((recvInProgress == true) && (rc == endMarker)){
      recvInProgress = false;
      newData = true;
    }
    else if(recvInProgress == true) {
      receivedChars[Used] = rc;
      Used++;
      if (Used >= numChars) {
        Used = numChars - 1;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
      Used = 0;
    }
  }

  if (newData == true){
    for (index = 0; index < Used; index++) {
      
      switch (index) {
        case 0:
          if (int(receivedChars[index]) == 1){
            digitalWrite(LED_BUILTIN, HIGH);
          }
          else{
            digitalWrite(LED_BUILTIN, LOW);
          }
          break;
        default:
          break;
      }
    }
    
    newData = false;
  }
  
}
Python
import numpy as np
import time
import serial

time_in_sec_until_change: float = 0.5

ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)


start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'
led_value_off: np.ndarray = np.array((start_marker, 0, stop_marker), dtype=np.uint8)
led_value_on: np.ndarray = np.array((start_marker, 1, stop_marker), dtype=np.uint8)

for t in range(0, 100):
    print("On")
    ser.write(led_value_on)
    print("Wait")
    time.sleep(time_in_sec_until_change)

    print("Off")
    ser.write(led_value_off)
    print("Wait")
    time.sleep(time_in_sec_until_change)

print("Done")
Matlab
time_in_sec_until_change = 0.5;

ser = serialport('COM3', 115200); 
% need to wait until the arduino is ready...
% I tested with 1sec and it was not enough
pause(2); 

start_marker = uint8(60);  % '<'
stop_marker = uint8(62);  % '>'

led_value_off = [start_marker, uint8(0), stop_marker];
led_value_on = [start_marker, uint8(1), stop_marker];

for i = [1:1:100]
    fprintf("On\n")
    write(ser,led_value_on,"uint8")
    fprintf("Wait\n")
    pause(time_in_sec_until_change)

    fprintf("Off\n")
    write(ser,led_value_off,"uint8")
    fprintf("Wait\n")
    pause(time_in_sec_until_change)
end
fprintf("Done\n")

clear ser 
 

Pulsing the LED for a defined time
The Arduino sketch
int rc;
boolean recvInProgress = false;

int startMarker = 60; // <
int endMarker = 62; // >

int numChars = 32;
int receivedChars[32];

int index = 0;
int Used = 0;

boolean newData = false;

unsigned long my_timeout = 5000; // in ms
unsigned long my_timer = my_timeout; // counter
unsigned long last_time_check = 0;
unsigned long this_time_check = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {

  if (my_timer >= my_timeout){
    digitalWrite(LED_BUILTIN, LOW);
   }
  else{
    this_time_check = millis();
    my_timer = my_timer + this_time_check - last_time_check;
    last_time_check = this_time_check;
  }

  if ((Serial.available() > 0) && (newData == false)) {

    rc = Serial.read();

    if ((recvInProgress == true) && (rc == endMarker)){
      recvInProgress = false;
      newData = true;
    }
    else if(recvInProgress == true) {
      receivedChars[Used] = rc;
      Used++;
      if (Used >= numChars) {
        Used = numChars - 1;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
      Used = 0;
    }
  }

  if (newData == true){
    for (index = 0; index < Used; index++) {
      
      switch (index) {
        case 0:
          if (int(receivedChars[index]) == 1){
            digitalWrite(LED_BUILTIN, HIGH);
            my_timer = 0;
            last_time_check = millis();
          }
          break;
        default:
          break;
      }
    }
    
    newData = false;
  }
  
}

Python
import numpy as np
import time
import serial

ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)


start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'
led_value_on: np.ndarray = np.array((start_marker, 1, stop_marker), dtype=np.uint8)

print("On")
ser.write(led_value_on)
Matlab
ser = serialport('COM3', 115200); 
% need to wait until the arduino is ready...
% I tested with 1sec and it was not enough
pause(2); 

start_marker = uint8(60);  % '<'
stop_marker = uint8(62);  % '>'

led_value_on = [start_marker, uint8(1), stop_marker];

fprintf("On\n")
write(ser,led_value_on,"uint8")

clear ser 
 

PWM control of a pin
Warning: On an Arduino Uno LED_BUILTIN is 13. But pins that support PWM on an Uno are 3, 5, 6, 9, 10, 11 and NOT 13. 

With a output value of 64:



With a output value of 128:



With a output value of 192:



The Arduino sketch
int rc;
boolean recvInProgress = false;

int startMarker = 60; // <
int endMarker = 62; // >

int numChars = 32;
int receivedChars[32];

int index = 0;
int Used = 0;

int min_length_of_payload = 1;

boolean newData = false;

int output_pin = 11;

void setup() {
  Serial.begin(115200);
  pinMode(output_pin, OUTPUT);
  
}

void loop() {

  if ((Serial.available() > 0) && (newData == false)) {

    rc = Serial.read();

    if ((recvInProgress == true) && (rc == endMarker)  && (Used == min_length_of_payload) ){
      recvInProgress = false;
      newData = true;
    }
    else if ((recvInProgress == true) && (rc != endMarker)  && (Used == min_length_of_payload) ){
      recvInProgress = false;
      newData = false;
      Used = 0;
    }
    else if(recvInProgress == true) {
      receivedChars[Used] = rc;
      Used++;
    }
    else if (rc == startMarker) {
      recvInProgress = true;
      Used = 0;
    }
  }

  if (newData == true){
    for (index = 0; index < Used; index++) {
      
      switch (index) {
        case 0:
          // the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int.
          analogWrite(output_pin, int(receivedChars[index]));
          break;
        default:
          break;
      }
    }
    
    newData = false;
  }
  
}
Python
import numpy as np
import time
import serial


ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)


start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'
led_brightness = 128  # 0,...,255 integer values allowed

led_control: np.ndarray = np.array(
    (start_marker, led_brightness, stop_marker), dtype=np.uint8
)
print("Send...")
ser.write(led_control)
Matlab
ser = serialport('COM3', 115200); 
% need to wait until the arduino is ready...
% I tested with 1sec and it was not enough
pause(2); 

start_marker = uint8(60);  % '<'
stop_marker = uint8(62);  % '>'

led_brightness = 128; % 0,...,255 integer values allowed

led_control = [start_marker, uint8(led_brightness),stop_marker];

fprintf('Send...')
write(ser,led_control,"uint8")

clear ser 
Sending the internal clock 
The Arduino sketch
int start_marker = 60; // <
int end_marker = 62; // >

unsigned long mytime;

void setup() {
  Serial.begin(115200);
}

void loop() {

  mytime = millis();
  Serial.write(start_marker);

  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));

  Serial.write(end_marker);
  delay(1000);
  
}
Python
import time
import serial

read_max_values = 6
read_number_of_values = 100

ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)


start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'

for i in range(0, read_number_of_values):
    # I will assume that we get one block of 6 bytes
    # I want to keep this example simple...
    s = ser.read(read_max_values)
    returned_value: int = 0
    if len(s) == 6:
        if s[0] == start_marker:
            if s[5] == stop_marker:
                returned_value += s[4]
                returned_value = returned_value << 8
                returned_value += s[3]
                returned_value = returned_value << 8
                returned_value += s[2]
                returned_value = returned_value << 8
                returned_value += s[1]
                print(f"Arduino-clock in ms: {returned_value}")
Matlab
ser = serialport('COM3', 115200); 
% need to wait until the arduino is ready...
% I tested with 1sec and it was not enough
pause(2); 

start_marker = uint8(60);  % '<'
stop_marker = uint8(62);  % '>'

read_max_values = 6;
read_number_of_values = 100;

for i = [1:1:read_number_of_values],
    % I will assume that we get one block of 6 bytes
    % I want to keep this example simple...
    s = read(ser,read_max_values,"uint8");
    returned_value = 0;
    if length(s) == 6,
        if s(1) == start_marker,
            if s(6) == stop_marker,
                returned_value = returned_value + s(5);
                returned_value = bitshift(returned_value,8);
                returned_value = returned_value + s(4);
                returned_value = bitshift(returned_value,8);
                returned_value = returned_value + s(3);
                returned_value = bitshift(returned_value,8);
                returned_value = returned_value + s(2);
                fprintf(['Arduino-clock in ms: ' num2str(returned_value) '\n']);
            end
        end
    end
end
clear ser 
Sending the time on a rising interrupt 
Via attachInterrupt() we attach a function to an interrupt which is triggered when a low -> high transition on a defined pin ocures. Not every pin is capable of doing so. I will use pin 2 on the Uno. Please check attachInterrupt() for list of pins.

The software side is the same as in the previous example. 

The Arduino sketch
int start_marker = 60; // <
int end_marker = 62; // >

volatile unsigned long mytime;
int interruptPin = 2;

void setup() {
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(interruptPin), send_time, RISING );
}
void send_time(){
  mytime = millis();
  Serial.write(start_marker);

  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));

  Serial.write(end_marker);
  }
void loop() {

  
}
 

Reading digital values on a rising interrupt
The Arduino sketch
int start_marker = 60; // <
int end_marker = 62; // >

volatile unsigned long mytime;
int interruptPin = 2;
int analogPin = A0;
volatile unsigned int digital_value = 0;

void setup() {
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(interruptPin), send_time, RISING );
}
void send_time(){
  mytime = millis();
  digital_value = digitalRead(analogPin);
  Serial.write(start_marker);

  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));

  Serial.write(byte(digital_value));

  Serial.write(end_marker);
  }
void loop() {

  
}
Python
import numpy as np
import time
import serial

read_max_values = 7
read_number_of_values = 100

ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)

start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'

buffer: np.ndarray = np.array([])

counter_samples = 0
while True:

    s = ser.read(read_max_values)
    returned_value_time: int = 0
    returned_value_bool: int = 0

    # Find the start_marker and remove everything before that
    buffer_length: int = buffer.size
    if buffer_length > 0:
        for i in range(0, buffer_length):
            if buffer[0] == start_marker:
                break
            else:
                buffer = buffer[1:]

    if buffer.shape[0] == 0:
        buffer = np.frombuffer(s, dtype=np.uint8)
    else:
        buffer = np.concatenate([buffer, np.frombuffer(s, dtype=np.uint8)], axis=0)

    if buffer.size >= 7:
        if buffer[0] == start_marker:
            if buffer[6] == stop_marker:
                returned_value_time += buffer[4]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[3]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[2]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[1]

                returned_value_bool = buffer[5]

                if buffer.size == 7:
                    buffer = np.array([])
                else:
                    buffer = buffer[7:]
                counter_samples += 1
                print(
                    f"Arduino-clock in ms: {returned_value_time} with value {returned_value_bool}"
                )
    if counter_samples == read_number_of_values:
        break
Reading analog values on a rising interrupt
The Arduino sketch
int start_marker = 60; // <
int end_marker = 62; // >

volatile unsigned long mytime;
int interruptPin = 2;
int analogPin = A0;
volatile unsigned int adc_value = 0;

void setup() {
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(interruptPin), send_time, RISING );
}
void send_time(){
  mytime = millis();
  adc_value = analogRead(analogPin);
  Serial.write(start_marker);

  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));
  mytime = mytime >> 8;
  Serial.write(byte(mytime));

  Serial.write(byte(adc_value));
  adc_value = adc_value >> 8;
  Serial.write(byte(adc_value));

  Serial.write(end_marker);
  }
void loop() {

  
}
Python
import numpy as np
import time
import serial

read_max_values = 8
read_number_of_values = 100

ser = serial.Serial("COM3", 115200)
# need to wait until the arduino is ready...
# I tested with 1sec and it was not enough
time.sleep(2)

start_marker: int = 60  # '<'
stop_marker: int = 62  # '>'

buffer: np.ndarray = np.array([])

counter_samples = 0
while True:

    s = ser.read(read_max_values)
    returned_value_time: int = 0
    returned_value_adc: int = 0

    # Find the start_marker and remove everything before that
    buffer_length: int = buffer.size
    if buffer_length > 0:
        for i in range(0, buffer_length):
            if buffer[0] == start_marker:
                break
            else:
                buffer = buffer[1:]

    if buffer.shape[0] == 0:
        buffer = np.frombuffer(s, dtype=np.uint8)
    else:
        buffer = np.concatenate([buffer, np.frombuffer(s, dtype=np.uint8)], axis=0)

    if buffer.size >= 8:
        if buffer[0] == start_marker:
            if buffer[7] == stop_marker:
                returned_value_time += buffer[4]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[3]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[2]
                returned_value_time = returned_value_time << 8
                returned_value_time += buffer[1]

                returned_value_adc += buffer[6]
                returned_value_adc = returned_value_adc << 8
                returned_value_adc += buffer[5]

                if buffer.size == 8:
                    buffer = np.array([])
                else:
                    buffer = buffer[8:]
                counter_samples += 1
                print(
                    f"Arduino-clock in ms: {returned_value_time} with value {returned_value_adc}"
                )
    if counter_samples == read_number_of_values:
        break
 

## [Language Reference](https://www.arduino.cc/reference/en/)

### Variabel types

||
|---|
|[array](https://www.arduino.cc/reference/en/language/variables/data-types/array/)|
|[bool](https://www.arduino.cc/reference/en/language/variables/data-types/bool/)|
|[boolean](https://www.arduino.cc/reference/en/language/variables/data-types/boolean/)|
|[byte](https://www.arduino.cc/reference/en/language/variables/data-types/byte/)|
|[char](https://www.arduino.cc/reference/en/language/variables/data-types/char/)|
|[double](https://www.arduino.cc/reference/en/language/variables/data-types/double/)|
|[float](https://www.arduino.cc/reference/en/language/variables/data-types/float/)|
|[int](https://www.arduino.cc/reference/en/language/variables/data-types/int/)|
|[long](https://www.arduino.cc/reference/en/language/variables/data-types/long/)|
|[short](https://www.arduino.cc/reference/en/language/variables/data-types/short/)|
|[size_t](https://www.arduino.cc/reference/en/language/variables/data-types/size_t/)|
|[string](https://www.arduino.cc/reference/en/language/variables/data-types/string/)|
|[String()](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/)|
|[unsigned char](https://www.arduino.cc/reference/en/language/variables/data-types/unsignedchar/)|
|[unsigned int](https://www.arduino.cc/reference/en/language/variables/data-types/unsignedint/)|
|[unsigned long](https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/)|
|[word](https://www.arduino.cc/reference/en/language/variables/data-types/void/)|
|[void](https://www.arduino.cc/reference/en/language/variables/data-types/word/)|


### Type casts

||
|---|
|[(unsigned int)](https://www.arduino.cc/reference/en/language/variables/conversion/unsignedintcast/)
|[(unsigned long)](https://www.arduino.cc/reference/en/language/variables/conversion/unsignedlongcast/)
|[byte()](https://www.arduino.cc/reference/en/language/variables/conversion/bytecast/)
|[char()](https://www.arduino.cc/reference/en/language/variables/conversion/charcast/)
|[float()](https://www.arduino.cc/reference/en/language/variables/conversion/floatcast/)
|[int()](https://www.arduino.cc/reference/en/language/variables/conversion/intcast/)
|[long()](https://www.arduino.cc/reference/en/language/variables/conversion/longcast/)
|[word()](https://www.arduino.cc/reference/en/language/variables/conversion/wordcast/)

### "math" functions**

|||
|---|---|
|[abs()](https://www.arduino.cc/reference/en/language/functions/math/abs/)| Calculates the absolute value of a number. | 
|[constrain()  ](https://www.arduino.cc/reference/en/language/functions/math/constrain/)| Constrains a number to be within a range. | 
|[map() ](https://www.arduino.cc/reference/en/language/functions/math/map/)| Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between, etc. | 
|[max() ](https://www.arduino.cc/reference/en/language/functions/math/max/)| Calculates the maximum of two numbers. | 
|[min() ](https://www.arduino.cc/reference/en/language/functions/math/min/)| Calculates the minimum of two numbers. | 
|[pow() ](https://www.arduino.cc/reference/en/language/functions/math/pow/)|  Calculates the value of a number raised to a power. pow() can be used to raise a number to a fractional power. This is useful for generating exponential mapping of values or curves.| 
|[sq() ](https://www.arduino.cc/reference/en/language/functions/math/sq/)| Calculates the square of a number: the number multiplied by itself. | 
|[sqrt() ](https://www.arduino.cc/reference/en/language/functions/math/sqrt/)| Calculates the square root of a number. | 
|[cos() ](https://www.arduino.cc/reference/en/language/functions/trigonometry/cos/)| Calculates the cosine of an angle (in radians). The result will be between -1 and 1. | 
|[sin() ](https://www.arduino.cc/reference/en/language/functions/trigonometry/sin/)| Calculates the sine of an angle (in radians). The result will be between -1 and 1. | 
|[tan() ](https://www.arduino.cc/reference/en/language/functions/trigonometry/tan/)| Calculates the tangent of an angle (in radians). The result will be between negative infinity and infinity. | 
|[random() ](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)| The random function generates pseudo-random numbers. | 
|[randomSeed() ](https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/)| randomSeed() initializes the pseudo-random number generator, causing it to start at an arbitrary point in its random sequence. This sequence, while very long, and random, is always the same. | 
|[highByte() ](https://www.arduino.cc/reference/en/language/functions/bits-and-bytes/highbyte/)| Extracts the high-order (leftmost) byte of a word (or the second lowest byte of a larger data type). | 
|[lowByte()](https://www.arduino.cc/reference/en/language/functions/bits-and-bytes/lowbyte/)| Extracts the low-order (rightmost) byte of a variable (e.g. a word). | 

### Control structures:

||
|---|
|[for ](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)|
|[do...while ](https://www.arduino.cc/reference/en/language/structure/control-structure/dowhile/)|
|[while](https://www.arduino.cc/reference/en/language/structure/control-structure/while/)|
|[break ](https://www.arduino.cc/reference/en/language/structure/control-structure/break/)|
|[continue ](https://www.arduino.cc/reference/en/language/structure/control-structure/continue/)|
|[if ](https://www.arduino.cc/reference/en/language/structure/control-structure/if/)|
|[else ](https://www.arduino.cc/reference/en/language/structure/control-structure/else/)|
|[switch...case ](https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/)|
|[return ](https://www.arduino.cc/reference/en/language/structure/control-structure/return/)|
|[goto ](https://www.arduino.cc/reference/en/language/structure/control-structure/goto/)|

Bit manipulation, the usual logic operation and less interesting other stuff I will not list here. Go to the language reference.

### Structure

|||
|---|---|
|[setup() ](https://www.arduino.cc/reference/en/language/structure/sketch/setup/)| "The setup() function is called when a sketch starts. Use it to initialize variables, pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board."|
|[loop() ](https://www.arduino.cc/reference/en/language/structure/sketch/loop/)| "After creating a [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function, which initializes and sets the initial values, the loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. "|

### [Digital Pins](https://docs.arduino.cc/learn/microcontrollers/digital-pins)

|||
|---|---|
|[pinMode() ](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/)| "Configures the specified pin to behave either as an input or an output."|
|[digitalRead()](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)| "Reads the value from a specified digital pin, either HIGH or LOW."|
|[digitalWrite() ](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)| "Write a HIGH or a LOW value to a digital pin."|

### Analog Pins

|||
|---|---|
|[analogRead() ](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)| "Reads the value from the specified analog pin. Arduino boards contain a multichannel, 10-bit analog to digital converter. This means that it will map input voltages between 0 and the operating voltage(5V or 3.3V) into integer values between 0 and 1023."|
|[analogWrite() ](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)| "Writes an analog value ([PWM wave](https://docs.arduino.cc/learn/microcontrollers/analog-output)) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds. After a call to analogWrite(), the pin will generate a steady rectangular wave of the specified duty cycle until the next call to analogWrite() (or a call to digitalRead() or digitalWrite()) on the same pin."|

### Time

|||
|---|---|
|[millis() ](https://www.arduino.cc/reference/en/language/functions/time/millis/)| "Returns the number of milliseconds passed since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 50 days."|
|[micros() ](https://www.arduino.cc/reference/en/language/functions/time/micros/)| "Returns the number of microseconds since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 70 minutes."|
|[delay() ](https://www.arduino.cc/reference/en/language/functions/time/delay/)| "Pauses the program for the amount of time (in milliseconds) specified as parameter."|
|[delayMicroseconds() ](https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/)| "Pauses the program for the amount of time (in microseconds) specified by the parameter.  [...] Currently, the largest value that will produce an accurate delay is 16383; larger values can produce an extremely short delay."|

### Map

|||
|---|---|
|[map() ](https://www.arduino.cc/reference/en/language/functions/math/map/)| "Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between"|

### [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

|||
|---|---|
|[Serial.begin() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/)| "Sets the data rate in bits per second (baud) for serial data transmission." **WARNING: What ever you use as a data rate, make sure that the data rate is set to the same value everywhere!**|
|[if(Serial) ](https://www.arduino.cc/reference/en/language/functions/communication/serial/ifserial/)| "Indicates if the specified Serial port is ready. On the boards with native USB, if (Serial) (or if(SerialUSB) on the Due) indicates whether or not the USB CDC serial connection is open. For all other boards, and the non-USB CDC ports, this will always return true."|

#### Read

|||
|---|---|
|[Serial.available() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/)| "Get the number of bytes (characters) available for reading from the serial port. This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes)."|
|[Serial.read() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)| "Reads incoming serial data." Note: Reads ONE byte into a int variable.|
|[Serial.readBytes() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/readbytes/)| "Serial.readBytes() reads characters from the serial port into a buffer. The function terminates if the determined length has been read, or it times out (see [Serial.setTimeout())](https://www.arduino.cc/reference/en/language/functions/communication/serial/settimeout/)."|
|[Serial.setTimeout() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/settimeout/)| "Serial.setTimeout() sets the maximum milliseconds to wait for serial data. It defaults to 1000 milliseconds."|
|[Serial.peek() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/peek/)| "Returns the next byte (character) of incoming serial data without removing it from the internal serial buffer. That is, successive calls to peek() will return the same character, as will the next call to read()."|

#### Write

|||
|---|---|
|[Serial.availableForWrite() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/availableforwrite/)| "Get the number of bytes (characters) available for writing in the serial buffer without blocking the write operation."|
|[Serial.write() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/write/)| "Writes binary data to the serial port. This data is sent as a byte or series of bytes; to send the characters representing the digits of a number use the [print()](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/) function instead."|
|[Serial.print() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/)| "Prints data to the serial port as human-readable ASCII text. "|
|[Serial.println() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/println/)| "Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n'). This command takes the same forms as [Serial.print()](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/)."|
|[Serial.flush() ](https://www.arduino.cc/reference/en/language/functions/communication/serial/flush/)| "Waits for the transmission of outgoing serial data to complete. (Prior to Arduino 1.0, this instead removed any buffered incoming serial data.)"|

### Interrupts 

|||
|---|---|
|[attachInterrupt() ](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)| Connect a function to one of the interrupt pins|
|[detachInterrupt() ](https://www.arduino.cc/reference/en/language/functions/external-interrupts/detachinterrupt/)| "Turns off the given interrupt."|
|[interrupts() ](https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/)|  "Re-enables interrupts (after they’ve been disabled by [noInterrupts()](https://www.arduino.cc/reference/en/language/functions/interrupts/nointerrupts/). "|
|[noInterrupts() ](https://www.arduino.cc/reference/en/language/functions/interrupts/nointerrupts/)| "Disables interrupts (you can re-enable them with [interrupts()](https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/))."|

 
