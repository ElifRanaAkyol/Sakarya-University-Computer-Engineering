int rolePin   = 5;
int nemSensor = A0;
int suSensor  = A4;

int sinirDeger = 200;
int suSinir    = 100;

void setup() {
  Serial.begin(9600);

  pinMode(rolePin, OUTPUT);
  digitalWrite(rolePin, LOW);
}

void loop() {
  
    int nem = analogRead(nemSensor);
    int tersnem = 1023 - nem;
    int su  = analogRead(suSensor);

    Serial.print("NEM:");
    Serial.print(tersnem);
    Serial.print(";SU:");
    Serial.println(su);

    // if (su < suSinir) {
    //   digitalWrite(rolePin, HIGH);
    // }

    if (tersnem <= sinirDeger) {
      digitalWrite(rolePin, LOW);
    } else {
      digitalWrite(rolePin, HIGH);
    }
  
}
