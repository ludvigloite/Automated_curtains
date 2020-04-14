# Automated_curtains

This is a project I made in 2018. 

![](images/Automated_curtain.gif)

I used two Arduinos, two RF24-chips, a servo motor and a bunch of electronics to radiocontrol the curtains at my dorm. Range between the controller and the curtains were over 30 meters.

[Trans_uno](Trans_uno.ino) is the file loaded to the transmitting Arduino Uno. This Arduino receives signals from a joystick, and transmitt orders to the other Arduino. The transmission between the arduinos are handled by two RF24-chips

[Receiver_micro](Receiver_micro.ino) is the file loaded to the receiving Arduino Micro. This Arduino receives signal from the controller and output the corresponding signals to the motor.

## Potential improvements
1. Implement so that the transmitter receives signals from only an **open button** and a **close button**.
   - We need to either record how many degrees it takes to open/close the curtain fully, or better, use a sensor. 
2. Implement a mode where you can make the curtains open at for example 8 AM and close at 10 PM.
3. Implement a sensor that detects when the sun is rising, and opening the curtains at this point.
4. Connect the curtains to an app. Another possibility is to connect to Apple Home, Google Home or other. 
