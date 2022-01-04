#!/bin/bash

source /home/sserwyn/.bashrc
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games

SECRETS_FILE_NAME="/home/sserwyn/tg_secrets.txt"
BOT_SECRET=$(cat ${SECRETS_FILE_NAME} | grep "TG_BOT_SECRET" | awk '{print $2}')
CHANNEL_ID=$(cat ${SECRETS_FILE_NAME} | grep "TG_BOT_CHANNEL_ID" | awk '{print $2}')


Architecture="#Architecture: $(uname -s) $(hostname) $(uname -rvmo)"
CPU_physical="#CPU physical: $(nproc --all)"
vCPU="#vCPU: $(cat /proc/cpuinfo | grep processor | wc -l)"

mu=$(free -m | grep Mem)
mu_used=$(echo ${mu} | awk '{print $3}')
mu_free=$(echo ${mu} | awk '{print $2}')
mu_p=$(python3 -c "print(round($mu_used / $mu_free * 100, 2))")
Memory_Usage="#Memory Usage: ${mu_used}/${mu_free}MB (${mu_p}%)"

du_sum_gb=$(df -Bg | grep '^/dev/mapper' | awk '{c += $2} END {print c}')
du_sum_mb=$(df -Bm | grep '^/dev/mapper' | awk '{c += $3} END {print c}')
du_p=$(python3 -c "print(round($du_sum_mb / ($du_sum_gb * 1024) * 100, 2))")
Disk_Usage="#Disk Usage: ${du_sum_mb}MB/${du_sum_gb}Gb (${du_p}%)"

CPU_load="#CPU load: $(mpstat | awk '{printf "%.2f%%\n", 100-$12}' | tail -n 1)"
Last_boot="#Last boot: $(who -b | cut -c42-)"

lvm_count=$(lsblk | grep "lvm" | wc -l)
lvm_is="no"
if [ $lvm_count != 0 ]; then
	lvm_is="yes";
fi
LVM_use="#LVM use: ${lvm_is}"

Connections_TCP="#Connections TCP: $(netstat -s | grep "Forwarding:" | awk '{print $2}') ESTABLISHED"
User_log="#User log: $(who | wc -l)"

ntw_ip=$(hostname -I | awk '{print $1}')
ntw_mac=$(ip link show | grep "link/ether" | awk '{print $2}')
Network="#Network: IP ${ntw_ip} (${ntw_mac})"



RESULT_MSG="	${Architecture}
	${CPU_physical}
	${vCPU}
	${Memory_Usage}
	${Disk_Usage}
	${CPU_load}
	${Last_boot}
	${LVM_use}
	${Connections_TCP}
	${User_log}
	${Network}
	"

curl --data "chat_id=${CHANNEL_ID}&text=<pre>${RESULT_MSG}</pre>&disable_notification=true&parse_mode=HTML" https://api.telegram.org/bot${BOT_SECRET}/sendMessage
echo 
