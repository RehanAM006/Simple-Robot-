// Push Button
#define pushPin  3
int push_button_state = 0;

// Sonar Sensor
#define echo 4
#define trig 5
int distance; // Declare distance globally

// RGB
#define led_red 6
#define led_blue 11

// Motor Driver
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

void setup() {
  Serial.begin(9600);

  // Sonar Sensor
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  // Motor Driver
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // RGB
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);

  // Push Button
  pinMode(pushPin, INPUT_PULLUP);
}

void loop() {
  push_button_state = digitalRead(pushPin);

  // Call function
  distance = calculateDistance();
  lights_control();
  follow();
  stepBack();

  // Print values
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  delay(500);
}

int calculateDistance() {
  long duration;

  // Clear trig_pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Send waves
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Receive echo & calculate distance
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

// To follow hand (uni-direction)
void follow() {
  if (push_button_state == LOW && distance <= 5) {
    forward();
  } else {
    stop();
  }
}

// To move away from hand (uni-direction)
void stepBack() {
  if (distance < 5 && push_button_state == HIGH) {
    reverse();
  } else {
    stop();
  }
}

// To control LEDs on eyes (RED when evading)
void lights_control() {
  if (distance < 5) {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, LOW);
  } else {
    digitalWrite(led_red, LOW);
    digitalWrite(led_blue, HIGH);
  }
}

// To move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
}

// To stop
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}

// To reverse
void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
}
