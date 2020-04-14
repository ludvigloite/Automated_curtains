# Automated_curtains

This is a project I made in 2018. 

I used two Arduinos, two RF24-chips, a servo motor and a bunch of electronics to radiocontrol the curtains at my dorm. Range between the controller and the curtains were over 30 meters.

[Trans_uno](Trans_uno.ino) is the file loaded to the transmitting Arduino Uno. This Arduino receives signals from a joystick, and transmitt orders to the other Arduino. The transmission between the arduinos are handled by two RF24-chips

[Receiver_micro](Receiver_micro.ino) is the file loaded to the receiving Arduino Micro. This Arduino receives signal from the controller and output the corresponding signals to the motor.

## Potential improvements
1. Implement sånn at den åpner helt opp ved et knappetrykk "åpne" eller "lukke"
2. Sett på sånn at den åpnes kl 8 hver dag
3. Ha solsensor sånn at den åpnes når det kommer sol
4. Koble sammen med en app på telefonen. Evt Google Home eller Apple Home elns?
