# IoT

## Installation Guide
### Raspberry Pi Imager</br>
https://www.raspberrypi.org/downloads/</br>
</br>
### Download Putty</br>
https://putty.org/</br>
</br>
### Update your pi</br>
`sudo apt-get update`</br>
`sudo apt-get upgrade`</br>
</br>
### Connecting to wifi on Raspberry Pi when headless</br>
https://www.raspberrypi.org/documentation/configuration/wireless/headless.md</br>
`sudo raspi-config`</br>
`sudo reboot -h now`</br>
</br>
### Install Mosquitto MQTT </br>
`sudo apt install -y mosquitto mosquitto-clients`</br>
###### Run Mosquitto MQTT at boot:</br>
`sudo systemctl enable mosquitto.service`</br>
###### Check Mosquitto is installed:</br>
`mosquitto -v`</br>
</br>
### Install node-red: </br>
`bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)`</br>
###### Run node-red at boot:</br>
`sudo systemctl enable nodered.service`</br>
</br>
### Install SQLite:</br>
`sudo apt-get install sqlite3`</br>
</br>
## Sqlite3 commands
`sqlite3 data.db`</br>
###### This will create a database in the file data.db. We should now be in a sqlite shell, so type:</br>
`CREATE TABLE climate (reading_time datetime, temperature float, humidity float);`</br>
</br>
###### Now we’ve created a table called climate, we can add to that table. Let’s test it by adding a random date, time, humidity and temperature:</br>
`INSERT INTO climate (reading_time, temperature, humidity) values (“2011-06-21 12:34:56”, 20, 77);`</br>
</br>
###### You can view the contents of the table,</br>
`SELECT * FROM climate;`</br>
</br>
###### And you can clear the table,</br>
`DELETE FROM climate;`</br>
