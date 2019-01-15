/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithController.h"

#include "Robot.h"


DriveWithController::DriveWithController() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subDriveTrain);
}

// Called just before this Command runs the first time
void DriveWithController::Initialize() {
  // Maybe add the Robot::m_subDriveTrain.Configure(); here to initialize, because the
  // Command will always be scheduled never end unless we do below in the End()
  // Robot::m_subDriveTrain.Drive(0,0);  Currently Robot::m_subDriveTrain.Configure();
  // is run in the RobotInit()
  
} 

// Called repeatedly when this Command is scheduled to run
void DriveWithController::Execute() 
{
  
  if(Robot::m_oi.driverController->GetRawAxis(AXIS_R_TRIG) > 0)
  {
    double velocity = Robot::m_oi.driverController->GetRawAxis(AXIS_R_TRIG)*3000;

    Robot::m_subDriveTrain.Drive(Robot::m_oi.driverController->GetRawAxis(AXIS_R_TRIG),Robot::m_oi.driverController->GetRawAxis(AXIS_LX));
  }
  else
  {
    
    Robot::m_subDriveTrain.Drive((-1*(Robot::m_oi.driverController->GetRawAxis(AXIS_L_TRIG))),Robot::m_oi.driverController->GetRawAxis(AXIS_LX));
  }
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithController::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithController::End() {
  //Robot::m_subDriveTrain.Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithController::Interrupted() {}


