#!/bin/bash

sysinfo=$()
cpu=$(nproc)
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
free_memory=$(free -m | awk '/Mem/ {print $2}')
used_memory=$(free -m | awk '/Mem/ {print $3}')
p_memory=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2100}')
free_disk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
usage_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
p_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft100}')
cpu_load=$(mpstat | awk 'NR == 4 {printf("%.2f%%"), 100 - $13}')
last_reboting=$(who -b | awk '{print( $3 " " $4)}')
lvm_status=$(if [ $check_lvm -eq 0 ]; then echo no; else echo yes; fi)
C_TCP=$(ss -ta | grep ESTAB | wc -l)
users=$(who | awk '{print $1}' | sort | uniq | wc -l)
network=$(hostname -I)
mac_adress=$(ip link | awk '$1 == "link/ether" {print $2}')
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "

    #Architecture:${uname -a}
    #CPU:$cpu
    #vCPU:$vcpu
    #Memory Usage:$used_memory/${free_memory}MB ($p_memory%)
    #Disk Usage:$usage_disk/${free_disk}Gb ($p_disk%)
    #CPU load:$cpu_load
    #Last boot$last_reboting
    #LVM use:$lvm_status
    #Connections TCP:$C_TCP ESTABLISHED
    #User log:$users
    #Network:IP $network ($mac_adress)
    #Sudo:$sudo cmd"
    cd /etc/ssh/
    ls