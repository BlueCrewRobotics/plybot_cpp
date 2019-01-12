#include "subsystems/DriveTrain.h"


frc::Joystick * controller;
void driveTrain::setSpeed(double speed){
    this->xSpeed = speed;
}

void driveTrain::setRotation(double rotation){
    this->zRotation = rotation;
}

void driveTrain::drive(){
    drive_train->ArcadeDrive(this->xSpeed, this->zRotation, false); 
}