/*
SDA 5
SCK 18
MOSI 23
MISO 19
RST 22
*/


#include <WiFi.h> //#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>

const char *ssid = "MSR-Rout";
const char *password = "msujithr2020";

//-------------------------MQTT Setup Start----------------------------------
#include <PubSubClient.h>
const char *mqttServer = "192.168.1.6";
const int mqttPort = 1883;
const char *mqttUser = "mqtt2020";
const char *mqttPassword = "mqtt2020";
const char *mqttClientName = "accesscard";

WiFiClient Accesscard;
PubSubClient client(Accesscard);

//MQTT Topics
#define mqttuid "home/uid"
//---------------------------MQTT Setup End-------------------------------------

#define SS_PIN 5   //SDA
#define RST_PIN 22 // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
byte readCard[4];

void setup()
{

  Serial.begin(115200);

  connectWifi(); //connect to wifi

  // Initialize serial communications with the PC
  while (!Serial)
    ;                                // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();                       // Init SPI bus
  mfrc522.PCD_Init();                // Init MFRC522
  delay(4);                          // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  client.setServer(mqttServer, mqttPort);
}

void loop(){
  if (!client.connected())
  {
    reconnect();
  }

  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Select one of the cards
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.println(F("Scanned PICC's UID:"));
  String uid = "";
  for (uint8_t i = 0; i < 4; i++)
  { //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
    uid += String(readCard[i], HEX);
  }
  client.publish(mqttuid, String(uid).c_str(), true);
}

//------------------------wifi connect function----------------------------
void connectWifi()
{
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);

  WiFi.begin(ssid, password);

  //wait untill wifi is connected

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // wifi is connected

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//-------------------------------------------------------------------------

void reconnect()
{
  // Loop until we're reconnected

  int counter = 0;
  while (!client.connected())
  {
    if (counter == 5)
    {
      ESP.restart();
    }
    counter += 1;
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect

    if (client.connect(mqttClientName, mqttUser, mqttPassword))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
