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

# 7i84

```bash
loadrt hm2_eth board_ip="10.10.10.10" config=" num_encoders=6 num_pwmgens=6 num_stepgens=0 sserial_port_0=00000000" 
```
