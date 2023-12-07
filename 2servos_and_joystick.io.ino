#include <Servo.h>
#include <ezButton.h>

#define SW_PIN   4  // Arduino pin connected to SW  pin

int joystickXPin = A0;
int joystickYPin = A1;  //om man vill också styra y axeln, dvs ha 2 servos

Servo myservo;
Servo yservo;
ezButton button(SW_PIN);

int bValue = 0; // To store value of the button


void setup() {
  // put your setup code here, to run once:
  myservo.attach(11);
  yservo.attach(12);
  Serial.begin(9600);
   button.setDebounceTime(50); // set debounce time to 50 milliseconds
  pinMode(8, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  button.loop(); // MUST call the loop() function first
  bValue = button.getState();
  int joystickXValue = analogRead(joystickXPin);
  int joystickYValue = analogRead(joystickYPin);
  int servoAngle = map(joystickXValue, 0, 1023, 0, 158);
  int yservoAngle = map(joystickYValue, 0, 1023, 0, 180);

   if (button.isPressed()) {
    Serial.println("The button is pressed");
    digitalWrite(8, HIGH);
    // TODO do something here

  }

  if (button.isReleased()) {
    Serial.println("The button is released");
    
    // TODO do something here
    digitalWrite(8, LOW);
  }


  Serial.println("x: " + String(servoAngle) + "   y: " + String{ yservoAngle });
  delay(200);


  yservo.write(yservoAngle);


  myservo.write(servoAngle);
}
