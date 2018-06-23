const int TRIG_PIN = 12;// pin triger sensor ultrasonic di koneksikan ke pin 12 pada arduino
const int ECHO_PIN = 11;// pin echo sensor ultrasonic di koneksikan ke pin 11 pada arduino
const int buzzerPin= 13;

void setup() {
   Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(buzzerPin, OUTPUT);//
}

void loop(){
    long duration, distanceCm;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distanceCm = duration / 58.8;

    Serial.println(distanceCm);
    if (distanceCm < 5) {
        digitalWrite(buzzerPin, HIGH);  
        delay(100);
        digitalWrite(buzzerPin, LOW);
    }
    delay(500);
}

