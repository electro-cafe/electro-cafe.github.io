//4.5.4
//je partitionne mon code pour plus de lisibilité

#include <TimerStepMotor.cpp> //je sais pas si ça va marcher
#include <TimerLed.cpp> //je sais pas si ça va marcher

main {

int motorSpeedMinute = 100;   //ça devrait nous donner une révolution complete en 60s.
int motorSpeedHour = motorSpeedMinute* 60;
int motorSpeedDay = motorSpeedHour * 24;

  Stepper MinuteMotor(2048, ){ //ajouter les 4 pins
    this->setSpeed(motorSpeedMinute);
  }

  Stepper hourMotor(2048, ){ //ajouter les 4 pins
    this->setSpeed(motorSpeedHour);
  }

  Stepper dayMotor(2048, ){ //ajouter les 4 pins
    this->setSpeed(motorSpeedDay);
  }

}


//to do: ajouter la fonction de tourner rapidement (4s / revolution) clockwise sur le switch bouton up pour chaque moteur. counter clockwise pour position basse.