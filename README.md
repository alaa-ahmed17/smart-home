#simple smart-home
System asks user to enter the password using KEYPAD and print each entry in keypad and checks this entry with correct password(15987).

in case of wrong password -->

    -LCD will print 'wrong password'
    
    -red led will light up to indicate the wrong password 
    
    -buzzer will make warning sound for small time (1000ms)
    
and then ask again to enter the password.

in case of corret password -->

    -it can enter to the system ,LCD will print 'loading'
    
    -yellow led will light up to indicate the correct password  
    
    -the motor will work in the left direction (acts as open a door) for small time
    
    -then will work in opsite direction (acts as close a door) for small time then will stop.
    
    -temperature and LDR sensor will work (LM35).
    
    -temperature sensor sense the temperature in the Home and Display the temperature on the LCD 
    
    -LDR sensor will sense the light intensity in home LEDS will light up according the level of darkness in home by the help of ADC peripheral.
