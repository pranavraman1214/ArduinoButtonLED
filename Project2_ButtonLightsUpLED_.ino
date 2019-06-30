int switchPin = 8; 
int ledPin = 13; 
int brightnessPin = 11; 
boolean lastButton = LOW; 
boolean currentButton; 
boolean ledOn = false; 
int ledLevel = 0; 
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT); 
  pinMode(ledPin, OUTPUT);

}
boolean debounce (boolean last) {
    boolean current = digitalRead(switchPin); 
    if (last != current) {
      delay(5);
      current = digitalRead(switchPin); 
    }
    return current; 
}

void loop() {
  // put your main code here, to run repeatedly:
  // The Code underneath is for holding the button and the light stays on: 
  /**if (digitalRead(switchPin) == HIGH) {
    digitalWrite(ledPin,HIGH);  
  } else {
    digitalWrite(ledPin,LOW); 
  }*/
 /* // The code below makes the button a switch for the led 
  currentButton = debounce(lastButton); 
  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;    
  } 
  lastButton = currentButton; 
  digitalWrite(ledPin, ledOn);*/
  // The code below makes the button alter brightness of the led 
  currentButton = debounce(lastButton); 
  if (lastButton == LOW && currentButton == HIGH) {
    ledLevel += 51; 
  } 
  lastButton = currentButton; 
  if (ledLevel >= 255) {
    ledLevel = 0;   
  }
  analogWrite(brightnessPin,ledLevel);
}
