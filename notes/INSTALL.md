# Software Installation

Start of `bookworm/sid` (use xfce):

https://cdimage.debian.org/cdimage/unofficial/non-free/cd-including-firmware/

- Remove cdrom from sources: sudo nano /etc/sources.list
- `sudo apt install ethtool`

Check driver alignment:

- `lspci`
- `sudo ethtool -i enp2s0`

## Install Rods' custom kernel

6.1 exists in my NAS

- install headers
- install kernel
- `sudo apt install grub-customizer`
- `sudo apt install r8168-dkms`

# Mesa 7i97


## Network interface:

`sudo vim /etc/network/interfaces`

```
auto enp2s0
iface enp2s0 inet static
address 10.10.10.1 or 192.168.1.1
```
Restart network: `sudo systemctl restart networking`


`mesaflash --device 7i97 --addr 10.10.10.10 --readhmid`

# ??? sudo ethtool -C eth0 rx-usecs 0

# LinuxCNC


`sudo apt install linuxcnc-uspace linuxcnc-uspace-dev mesaflash`


Let it run for a while. While it is running,
in another window, check the network latency by reviewing the TMAX settings on your card

`halcmd show param hm2*tmax*`

```
Parameters:
Owner   Type  Dir         Value  Name
     7  s32   RW              0  hm2_7i97.0.read-request.tmax
     7  bit   RO          FALSE  hm2_7i97.0.read-request.tmax-increased
     7  s32   RW         704022  hm2_7i97.0.read.tmax
     7  bit   RO          FALSE  hm2_7i97.0.read.tmax-increased
     7  s32   RW          42126  hm2_7i97.0.write.tmax
     7  bit   RO          FALSE  hm2_7i97.0.write.tmax-increased
```


# Notes

[Enable outputs](https://forum.linuxcnc.org/27-driver-boards/46253-mesa-7i97-analog-out-issue#246257)



