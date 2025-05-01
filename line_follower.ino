#define TRIG_PIN 12
#define ECHO_PIN 13

// Motor PWM pins
#define Rpwm_pin 5   // Right motors (Group B)
#define Lpwm_pin 6   // Left motors (Group A)

// Motor direction pins
#define IN1 2   // Left motor direction 
#define IN2 4   // Right motor direction 

// IR Sensor pins
#define LEFT_IR 11
#define MIDDLE_IR 7
#define RIGHT_IR 8  

// Speed settings
int M1_Speed = 100;    // Forward speed for right motors
int M2_Speed = 100;    // Forward speed for left motors
int LeftSpeed = 100;   // Turning speed
int RightSpeed = 100;  // Turning speed
int obstacleThreshold = 25;  // Unused, kept for future expansion

void setup() {
  Serial.begin(9600);
  pinMode(INffff1, OUTPUT);  // Note: This is a typo; should be IN1
  pinMode(IN2, OUTPUT);
  pinMode(Rpwm_pin, OUTPUT);
  pinMode(Lpwm_pin, OUTPUT);
  pinMode(LEFT_IR, INPUT);
  pinMode(MIDDLE_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  tracking();
}

void tracking() {
  int LS = digitalRead(LEFT_IR);
  int MS = digitalRead(MIDDLE_IR);
  int RS = digitalRead(RIGHT_IR);
  
  // Debug output
  Serial.print("LS: "); Serial.print(LS);
  Serial.print(" MS: "); Serial.print(MS);
  Serial.print(" RS: "); Serial.println(RS);
  
  if (RS == 1 && MS == 0 && LS == 1) {
    forward();
  }
  else if (RS == 1 && LS == 0) {
    left();
  }
  else if (RS == 0 && LS == 1) {
    right();
  }
  else if (RS == 0 && MS == 0 && LS == 0) {
    Stop();
  }
  else {
    Stop();
  }
}

// Movement Functions
void forward() {
  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, HIGH);  // Right motor forward
  analogWrite(Rpwm_pin, M1_Speed);
  analogWrite(Lpwm_pin, M2_Speed);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(Rpwm_pin, M1_Speed);
  analogWrite(Lpwm_pin, M2_Speed);
}

void Stop() {
  analogWrite(Rpwm_pin, 0);
  analogWrite(Lpwm_pin, 0);
}

void right() {
  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);   // Right motor backward
  analogWrite(Rpwm_pin, LeftSpeed);
  analogWrite(Lpwm_pin, RightSpeed);
}

void left() {
  digitalWrite(IN1, LOW);   // Left motor backward
  digitalWrite(IN2, HIGH);  // Right motor forward
  analogWrite(Rpwm_pin, LeftSpeed);
  analogWrite(Lpwm_pin, RightSpeed);
}