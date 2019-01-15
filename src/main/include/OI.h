/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/WPILib.h>
#include "RobotMap.h"

class OI {
 public:
  OI();
   
  frc::Joystick* driverController = new frc::Joystick(DRIVER_CONTROLLER);
  frc::Joystick* auxController = new frc::Joystick(AUX_CONTROLLER);

  
  frc::JoystickButton* driverController_button_a = new frc::JoystickButton(driverController, BUTTON_A);

};
