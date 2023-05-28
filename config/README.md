# Configuration for MAHO MH500W CNC

https://linuxcnc.org/docs/html/man/man9/pid.9.html
https://linuxcnc.org/docs/devel/html/motion/pid-theory.html

# Limits

LJ12A3-4-Z/EX - Output Type: NPN NO (Normal Open)

```
Axis    Desc        Cable       Exten.      Name        MESA 7i97
----------------------------------------------------------------------
        Vcc         Brown       Brown       lim-x-pwr   24V
Χ       Signal      Black       White       lim-x-out   TB4-pin4-IN2
        Ground      Blue        Green       lim-x-com   TB4-pin6-COMMON-2,3

        Vcc         Brown       Brown       lim-y-pwr   24V
Y       Signal      Black       White       lim-y-out   TB4-pin5-IN3
        Ground      Blue        Green       lim-y-com   TB4-pin6-COMMON-2,3

        Vcc         Brown       Brown       lim-z-pwr   24V 
Z       Signal      Black       White       lim-z-out   TB4-pin7-IN4
        Ground      Blue        Green       lim-z-com   TB4-pin9-COMMON-4,5
```

- Connect common2,4 and common4,5 to PSU GND
- Connect 24V

# sserial

```bash
loadrt hm2_eth board_ip="10.10.10.10" config=" num_encoders=6 num_pwmgens=6 num_stepgens=0 sserial_port_0=00000000" 
```

each x is mode for that channel of the sserial.port


modes are explained for different cards in the manual for specific cards.
example 7i76e
"2xxxxxxx" turns on the analog inputs.
"1xxxxxxx" turns tha analog inputs into mpg inputs

to enable each channel. just put "00000000" and it will auto detect what card is commected.
to determine the correct.mode of operation that is not default to the apllication. read the f manual

if your card has 2 saerial ports. or if your adding a card that adds sserial.ports. 
you may need the string num_sserial=0-9

added to the load hm2_eth config string.
and then
sserial_port_0-3="xxxxxxxx"
7i97 uses muxed ports vs having a 7i84 build in to the end on the boart occupiyin channel 1 of sserial port 0

if the 7i97 isnt new stock(last 6monthjs) it needs  a firmware.update. as the orignal baych was released with some.bung shit in the firmware