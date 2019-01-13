#include "subsystems/DriveTrain.h"


frc::Joystick * controller;
void driveTrain::setSpeed(double speed){
    this->xSpeed = speed;
}

void driveTrain::setRotation(double rotation){
    this->zRotation = rotation;
}

void driveTrain::drive(){
    // first the variables newSpeed and newRotation must be calculated 
    // then put into the ArcadeDrive function -- we did something similar 
    // in the Kylo code. 
    drive_train->ArcadeDrive(this->xSpeed, this->zRotation, false); 
}