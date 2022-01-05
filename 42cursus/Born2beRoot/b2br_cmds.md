## Mandatory part

checking the disks
```
lsblk
```
change user to root
```
su -
```
installing sudo
```
apt-get install sudo
apt-get install vim -y
```

choose vim.tiny
```
update-alternatives --config editor
```
setting ssh
```
cp /etc/ssh/sshd_config /etc/ssh/sshd_config.backup
vim /etc/ssh/sshd_config
```
- `#Port 22` to `Port 4242`
- `#PermitRootLogin prohibit-password` to `PermitRootLogin no`

```
/usr/sbin/sshd -t && echo $?
```

granting root to the user
```
usermod -aG root sserwyn
```
```
cp /etc/sudoers /etc/sudoers.backup
```
```
visudo
```
- add `sserwyn	ALL=(ALL:ALL) ALL`

```
visudo -c
```
```
reboot
```
port `4242` forwarding in VirtualBox

in PowerShell
```
ssh sserwyn@localhost -p 4242
```
```
su -
groups sserwyn
groups root
```

```
visudo
```
- add `Defaults	passwd_tries=3` _Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password._
- add `Defaults	badpass_message="WHO ARE YOU?"` _A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo._
```
visudo -c
```

_Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the `/var/log/sudo/` folder_
```
mkdir /var/log/sudo
touch /var/log/sudo/sudo.log
```
```
visudo
```
- add `Defaults	log_input`
- add `Defaults	log_output`
- add `Defaults	logfile="/var/log/sudo/sudo.log"`
- add `Defaults	iolog_dir="/var/log/sudo"`
```
visudo -c
```

_The TTY mode has to be enabled for security reasons._
```
cp /etc/systemd/logind.conf /etc/systemd/logind.conf.backup
```
```
vim /etc/systemd/logind.conf
```
- `#NAutoVTs=6` to `NAutoVTs=8`
- `#ReserveVT=6` to `ReserveVT=8`
```
visudo
```
- add `Defaults	requiretty` _TTY mode_
```
visudo -c
```

_For security reasons too, the paths that can be used by sudo must be restricted. Example: `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`_
```
visudo
```
- `Defaults	secure_path=<...>` to `Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"`
```
visudo -c
```

```
addgroup user42
usermod -aG user42 sserwyn
usermod -aG sudo sserwyn
gpasswd -d sserwyn root
gpasswd -d sserwyn cdrom
gpasswd -d sserwyn floppy
gpasswd -d sserwyn audio
gpasswd -d sserwyn dip
gpasswd -d sserwyn video
gpasswd -d sserwyn plugdev
gpasswd -d sserwyn netdev
gpasswd -d sserwyn bluetooth
groups sserwyn
```

password policy
```
cp /etc/login.defs /etc/login.defs.backup
```
```
vim /etc/login.defs
```
- `PASS_MAX_DAYS	99999` to `PASS_MAX_DAYS 30` _Your password has to expire every 30 days._
- `PASS_MIN_DAYS	0` to `PASS_MAX_DAYS 2` _The minimum number of days allowed before the modification of a password will be set to 2._
- `PASS_WARN_AGE	7` _The user has to receive a warning message 7 days before their password expires._

```
apt-get install libpam-pwquality -y
cp /etc/pam.d/common-password /etc/pam.d/common-password.backup
```
```
vim /etc/pam.d/common-password
```
- add `password	requisite			pam_pwquality.so retry=3 maxrepeat=3 minlen=10 dcredit=-1 ucredit=-1 usercheck=1 enforce_for_root`
- add `password	requisite			pam_pwquality.so retry=3 maxrepeat=3 minlen=10 dcredit=-1 ucredit=-1 usercheck=1 difok=7`


_You have to configure your operating system with the UFW firewall and thus leave only
port 4242 open. Your firewall must be active when you launch your virtual machine._
```
apt-get install ufw -y
ufw status
ufw enable
ufw status
sudo ufw default deny incoming
sudo ufw default allow outgoing
ufw allow 4242
```

script
```
apt-get install net-tools sysstat -y
cd ~
echo '#!/bin/bash' > monitoring.sh
chmod +x monitoring.sh
```
```
sudo crontab -u root -e
```
- add `@reboot /usr/bin/sh /home/sserwyn/monitoring.sh`
- add `*/10 * * * *	/usr/bin/sh /home/sserwyn/monitoring.sh`

--------------------------------------------------------------------
## Bonus part
```
apt-get install lighttpd -y
systemctl stop lighttpd.service
systemctl start lighttpd.service
systemctl enable lighttpd.service
```
```
apt-get install mariadb-server mariadb-client -y
systemctl stop mysql.service
systemctl start mysql.service
systemctl enable mysql.service
```
```
mysql_secure_installation
systemctl restart mysql.service
```
```
apt install php php-cgi php-mysql -y
lighty-enable-mod fastcgi
lighty-enable-mod fastcgi-php
service lighttpd force-reload
```
```
apt-get install wget
wget https://ru.wordpress.org/latest-ru_RU.tar.gz
cp latest-ru_RU.tar.gz /var/www/html/
cd /var/www/html/
tar -xvzf latest-ru_RU.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
find /var/www/html/wordpress -type d -exec chmod 750 {} \;
find /var/www/html/wordpress -type f -exec chmod 640 {} \;
```
```
mariadb
```
- `CREATE DATABASE wordpress;`
- `CREATE USER sserwyn@localhost IDENTIFIED BY 'aboba';`
- `GRANT ALL ON wordpress.* TO sserwyn@localhost;`
- `FLUSH PRIVILEGES;`
- `\q`
```
mariadb -u sserwyn -p
```
- `SHOW DATABASES;`
- `\q`

ports `80` and `8080` forwarding in VirtualBox
`localhost/wordpress` in browser
- DB Name: `wordpress`
- User Name: `sserwyn`
- Password: `aboba`
- DB Server: `localhost`
- Table prefix: `wp_`


auto sending server info to telegram channel
```
sudo apt install curl -y
touch ~/monitoring_to_tg.sh
sudo chmod +x ~/monitoring_to_tg.sh
```
```
sudo crontab -u root -e
```
- add `* * * * *	/usr/bin/sh /home/sserwyn/monitoring_to_tg.sh`
