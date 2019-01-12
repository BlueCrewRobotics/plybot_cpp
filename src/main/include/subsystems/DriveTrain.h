#pragma once

#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "OI.h"

class driveTrain {
    frc::DifferentialDrive * drive_train;
    public:
        driveTrain(){
            this->drive_train = new frc::DifferentialDrive(*this->leftDriveMotor, *this->rightDriveMotor);
        }
        void setSpeed(double speed);
        void setRotation(double Rotation);
        void drive();


    private:
        double xSpeed;
        double zRotation; 
        WPI_TalonSRX * leftDriveMotor = new WPI_TalonSRX(motorLeftAddr);
        WPI_TalonSRX * rightDriveMotor = new WPI_TalonSRX(motorRightAddr);
        WPI_VictorSPX * leftFollowMotor = new WPI_VictorSPX(followLeftAddr);
        WPI_VictorSPX * rightFollowMotor = new WPI_VictorSPX(followRightAddr);
};