void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Read values from Ultrasonic sensor

/* Check which sensor was read first, if person came in increase
no. of person in the room decrease by one if went out */
if (usInTravelTime < usOutTravelTime){
  // someone has left the room
  numPer -= 1;
}
else if (usInTravelTime > usOutTravelTime){
  // someone has entered the room
  numPer += 1;
}

//If no. of person in the room equals zero turn off lights
if (numPer == 0){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}else if (numPer > 0){
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}