# Automated_curtains

This is a project I made in 2018. 

I used two Arduinos, two RF24-chips, a servo motor and a bunch of electronics to radiocontrol the curtains at my dorm. Range between the controller and the curtains were over 30 meters.

![](Trans_uno.ino) is the file loaded to the transmitting Arduino Uno. This Arduino receives signals from a joystick, and transmitt orders to the other Arduino. The transmission between the arduinos are handled by two RF24-chips

![](Receiver_micro.ino) is the file loaded to the receiving Arduino Micro. This Arduino receives signal from the controller and output the corresponding signals to the motor.
