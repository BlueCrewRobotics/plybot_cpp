/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/WPILib.h>

#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_X 2
#define BUTTON_Y 3
#define BUTTON_L_BUMP 4
#define BUTTON_R_BUMP 5
#define BUTTON_SELECT 6
#define BUTTON_START 7
#define BUTTON_L3 8
#define BUTTON_R3 9

#define AXIS_LX 0
#define AXIS_LY 1
#define AXIS_L_TRIG 2
#define AXIS_R_TRIG 3
#define AXIS_RX 4
#define AXIS_RY 5


class OI {
 public:
  frc::Joystick * driverController;
  frc::Joystick * auxController;
  OI();
};
