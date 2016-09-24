# heartsync
Double heart monitor tests whether two people's heartbeats come into sync. Build on Arduino.

Heartsync reads analog data from two pulse sensors and outputs it to vibration motors embedded in wristbands to create the sensation of feeling someone else's pulse. It checks to see if the measured heart rates are within a threshold. If the heart rates match within that threshold, the box lights up with 20 LEDS embedded in the top. 

The code for the user interaction part of the heartsync is simple. The pulse sensor comes with code for reading the raw values and detecting heartbeat and heart rate. I just had to understand what it was doing and duplicate the necessary variables to add a second sensor that would be controlled by the same interrupt service routine as the first one to maintain accurate readings. When a heartbeat is detected my code triggers a pulse of the vibration motor. Each loop checks the two heart rates and the triggers the LED display if they match within a threshold -  after testing various values and watching the sensor data to see how stable a resting heart rate is, I chose a threshold of 2.

From a user experience perspective, the emphasis is on the sensation of feeling someone else's heartbeat. The device is open to interpretation. Users could try any number of things to bring their heartbeats into sync or cause then to diverge. In a second iteration, I would update the light display to give information on how the heart rates are changing relative to each other – whether they are getting closer to being in sync or moving in opposite directions - rather than just showing when they match. 

![heartsync prototype](https://github.com/studiocjp/heartsync/blob/master/heartsync-prototype.jpg)

