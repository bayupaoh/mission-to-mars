const int smokeA0 = A5;
const int buzzer = 13;
int dataAsap;
//Threshold
int sensorThres = 100;

void setup() {
    // put your setup code here, to run once:
    pinMode(smokeA0, INPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    int analogSensor = analogRead (smokeA0);
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);

    if (analogSensor > sensorThres) {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(500);
    } else {
        digitalWrite(buzzer, LOW);
        delay(500);
    }
}

