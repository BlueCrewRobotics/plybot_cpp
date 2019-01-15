/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubDriveTrain.h"
#include "commands/DriveWithController.h"

#include "RobotMap.h"

SubDriveTrain::SubDriveTrain() : frc::Subsystem("SubDriveTrain") {}

void SubDriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveWithController());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

/*
  Configure the Talons and Victors for the drive
*/
void SubDriveTrain::Configure() {
  
  // Setup followers
	leftFollowMotor->Follow(*leftDriveMotor);
  rightFollowMotor->Follow(*rightDriveMotor);

  // Setup encoder
  leftDriveMotor->ConfigSelectedFeedbackSensor(QuadEncoder);
  leftDriveMotor->SetSensorPhase(false);
  rightDriveMotor->ConfigSelectedFeedbackSensor(QuadEncoder);
  rightDriveMotor->SetSensorPhase(true);
  
  // Set current limit continuous, peak, and peak duration can only be set on TalonSRX
  leftDriveMotor->ConfigContinuousCurrentLimit(30,0.5);
  leftDriveMotor->ConfigPeakCurrentLimit(150,0);
  leftDriveMotor->ConfigPeakCurrentDuration(50,0);

  rightDriveMotor->ConfigContinuousCurrentLimit(30,0.5);
  rightDriveMotor->ConfigPeakCurrentLimit(150,0);
  rightDriveMotor->ConfigPeakCurrentDuration(50,0);
  
  // Need to setup velocity PID controls
  leftDriveMotor->ConfigNominalOutputForward(0,30);
  leftDriveMotor->ConfigNominalOutputReverse(0,30);
  leftDriveMotor->ConfigPeakOutputForward(1,30);
  leftDriveMotor->ConfigPeakOutputReverse(-1,30);

  rightDriveMotor->ConfigNominalOutputForward(0,30);
  rightDriveMotor->ConfigNominalOutputReverse(0,30);
  rightDriveMotor->ConfigPeakOutputForward(1,30);
  rightDriveMotor->ConfigPeakOutputReverse(-1,30);

  leftDriveMotor->Config_kF(0,0.1097,30);
  leftDriveMotor->Config_kP(0,0.22,30);
  leftDriveMotor->Config_kI(0,0.0,30);
  leftDriveMotor->Config_kD(0,0.0,30);

  rightDriveMotor->Config_kF(0,0.1097,30);
  rightDriveMotor->Config_kP(0,0.22,30);
  rightDriveMotor->Config_kI(0,0.0,30);
  rightDriveMotor->Config_kD(0,0.0,30);


  
}

// Drive
void SubDriveTrain::Drive(double speed, double rotation) {
  // Drive 
  
  driveTrain->ArcadeDrive(speed,rotation, false);
}



