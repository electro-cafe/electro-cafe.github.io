//this is only valid for a 4 pin motor

class Stepper {
  public:
  //constructor
  Stepper(int numberOfSteps, int motorPin1,int motorPin2,int motorPin3,int motorPin4);

  //speed setter method:
  void setSpeed(long motorSpeed);

  //mover method:
  void step(int numberOfSteps);

  private:
  void runStepMotor(int thisStep);

  int direction;            // Direction of rotation
  unsigned long stepDelay; // delay between steps, in us, based on speed
  int numberOfSteps;        // total number of steps this motor can take
  int stepNumber;          // which step the motor is on

  // motor pin numbers:
  int motor_pin_1;
  int motor_pin_2;
  int motor_pin_3;
  int motor_pin_4;
  
  unsigned long lastStepTime; // timestamp in us of when the last step was taken

};