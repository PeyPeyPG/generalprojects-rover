#include <Servo.h>

// Various Settings
#define serialDataRate 9600

// Servo Pins
#define servoPinTurret 3 // A
#define servoPinLowerArm 5 // B
#define servoPinUpperArm 6 // C
#define servoPinArmRotation 9 // D
#define servoPinWrist 10 // E
#define servoPinWristRotation 11 // F

// Servos
Servo turret;
Servo lowerArm;
Servo upperArm;
Servo armRotation;
Servo wrist;
Servo wristRotation;


void setup() {
  // Attach the Servos
  turret.attach(servoPinTurret);
  lowerArm.attach(servoPinLowerArm);
  upperArm.attach(servoPinUpperArm);
  armRotation.attach(servoPinArmRotation);
  wrist.attach(servoPinWrist);
  wristRotation.attach(servoPinWristRotation);

  // Open the Serial Port
  Serial.begin(serialDataRate);
}

void loop() {
  // Check for Serial Data in Buffer
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');

    processCommand(command);
  }
}

void processCommand(String cmd) {
  Serial.println("RECEVIED " + cmd);
  
  float f = 6.738629;

  char id = cmd.charAt(0);
  int x = cmd.substring(1).toInt();
  Serial.println("x: " + x);
  Serial.println((long)(float)3.14591);

  Serial.print("Theta: ");
  Serial.println(setArmPosition(30));
  Serial.println(0.057);
}

double setArmPosition(int x) {
      double theta = asin((9.81 * x)/ pow(10, 2));
      turret.write(theta);
      return theta;
  }

 
