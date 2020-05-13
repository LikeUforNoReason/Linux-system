# 6240-FinalProject
[Description]
Intrusion Detection System with Snort

[Usage]
- View or modify rules
  
  sudo vi /usr/local/etc/snort/rules/local.rules
  
- Load rules
  
  sudo snort -c /usr/local/etc/snort/snort.lua -R /usr/local/etc/snort/rules/local.rules
  
- Start listening
  
  sudo snort -i <interface name> -A alert_fast -s 65535 -k none

- Send Snort a SIGHUP signal to initiate a reload
  
  sudo kill -SIGHUP <snort pid>

- Check ovs configuration
  
  sudo ovs-vsctl show

- Create ovs bridge
  
  sudo ovs-vsctl add-br br0

- Add Ethernet port to bridge
  
  add-port br0 enp0s3 -- set interface enp0s3 ofport_request=1

- Add a system service to run Ryu
  
  ryu-manager ryu.app.simple_switch_13 /home/ovs/flowmanager/flowmaanger.py
 
[Dependency]
- VirtualBox 6.1.0
- ubuntu 16.04 and above
- Snort 2.9.9.x and above
- Open vSwitch 2.9.5
- Ryu 4.15

