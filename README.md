# IoT

##Installation Guide
-- Raspberry Pi Imager
https://www.raspberrypi.org/downloads/

-- Download Putty
https://putty.org/

update your pi
`sudo apt-get update`
`sudo apt-get upgrade`

-- Connecting to wifi on Raspberry Pi when headless
https://www.raspberrypi.org/documentation/configuration/wireless/headless.md
`sudo raspi-config`
`sudo reboot -h now`

-- Install Mosquitto MQTT: 
`sudo apt install -y mosquitto mosquitto-clients`
-- Run Mosquitto MQTT at boot:
`sudo systemctl enable mosquitto.service`
-- Check Mosquitto is installed:
`mosquitto -v`

-- install node-red: 
`bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)`
-- Run node-red at boot:
`sudo systemctl enable nodered.service`

-- Install SQLite:
`sudo apt-get install sqlite3`

##Sqlite3 commands
`sqlite3 data.db`
This will create a database in the file data.db. We should now be in a sqlite shell, so type:
`CREATE TABLE climate (reading_time datetime, temperature float, humidity float);`

Now we’ve created a table called climate, we can add to that table. Let’s test it by adding a random date, time, humidity and temperature:
`INSERT INTO climate (reading_time, temperature, humidity) values (“2011-06-21 12:34:56”, 20, 77);`

You can view the contents of the table,
`SELECT * FROM climate;`
And you can clear the table,

`DELETE FROM climate;`
