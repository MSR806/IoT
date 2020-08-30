# IoT

## Installation Guide on Raspberry Pi
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
</br>
Run Mosquitto MQTT at boot:</br>
`sudo systemctl enable mosquitto.service`</br>
</br>
Check Mosquitto is installed:</br>
`mosquitto -v`</br>
</br>
### Install node-red: </br>
`bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)`</br>
</br>
Run node-red at boot:</br>
`sudo systemctl enable nodered.service`</br>
</br>
### Install SQLite:</br>
`sudo apt-get install sqlite3`</br>
</br>
## Sqlite3 commands
`sqlite3 data.db`</br>
</br>
This will create a database in the file data.db. We should now be in a sqlite shell, so type:</br>
`CREATE TABLE climate (reading_time datetime, temperature float, humidity float);`</br>
</br>
Now we’ve created a table called climate, we can add to that table. Let’s test it by adding a random date, time, humidity and temperature:</br>
`INSERT INTO climate (reading_time, temperature, humidity) values (“2011-06-21 12:34:56”, 20, 77);`</br>
</br>
You can view the contents of the table,</br>
`SELECT * FROM climate;`</br>
</br>
And you can clear the table,</br>
`DELETE FROM climate;`</br>
</br>
## Node Red Installation guide on Windows</br>

### 1. Install Node.js</br>
Download the latest 12.x LTS version of Node.js from the official Node.js home page. It will offer you the best version for your system.</br>
</br>
Run the downloaded MSI file. Installing Node.js requires local administrator rights; if you are not a local administrator, you will be prompted for an administrator password on install. Accept the defaults when installing. After installation completes, close any open command prompts and re-open to ensure new environment variables are picked up.</br>
</br>
Once installed, open a command prompt and run the following command to ensure Node.js and npm are installed correctly.</br>

Using Powershell: `node --version`; `npm --version`</br>
</br>
Using cmd: `node --version && npm --version`</br>
</br>
You should receive back output that looks similar to:</br>
</br>
`v12.15.0`</br>
`6.14.5`</br>
### 2. Install Node-RED</br>
Installing Node-RED as a global module adds the command node-red to your system path. Execute the following at the command prompt:</br>
</br>
`npm install -g --unsafe-perm node-red`</br>
### 3. Run Node-RED</br>
Once installed, you are ready to run Node-RED.</br>
