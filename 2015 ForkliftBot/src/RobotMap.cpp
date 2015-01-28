// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveLeftFront = NULL;
SpeedController* RobotMap::driveLeftRear = NULL;
SpeedController* RobotMap::driveRightFront = NULL;
SpeedController* RobotMap::driveRightRear = NULL;
RobotDrive* RobotMap::driveRobotDrive41 = NULL;
DoubleSolenoid* RobotMap::grabberGrabberPnuematicCylinder = NULL;
Encoder* RobotMap::elevatorLifterEncoder = NULL;
SpeedController* RobotMap::elevatorLifterMotor = NULL;
DigitalInput* RobotMap::elevatorUpperLimitSwitch = NULL;
DigitalInput* RobotMap::elevatorLowerLimitSwitch = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveLeftFront = new Talon(1);
	lw->AddActuator("Drive", "Left Front", (Talon*) driveLeftFront);
	
	driveLeftRear = new Talon(2);
	lw->AddActuator("Drive", "Left Rear", (Talon*) driveLeftRear);
	
	driveRightFront = new Talon(3);
	lw->AddActuator("Drive", "Right Front", (Talon*) driveRightFront);
	
	driveRightRear = new Talon(4);
	lw->AddActuator("Drive", "Right Rear", (Talon*) driveRightRear);
	
	driveRobotDrive41 = new RobotDrive(driveLeftFront, driveLeftRear,
              driveRightFront, driveRightRear);
	
	driveRobotDrive41->SetSafetyEnabled(true);
        driveRobotDrive41->SetExpiration(0.1);
        driveRobotDrive41->SetSensitivity(0.5);
        driveRobotDrive41->SetMaxOutput(1.0);

	grabberGrabberPnuematicCylinder = new DoubleSolenoid(0, 0, 1);      
	lw->AddActuator("Grabber", "Grabber Pnuematic Cylinder", grabberGrabberPnuematicCylinder);
	
	elevatorLifterEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Elevator", "Lifter Encoder", elevatorLifterEncoder);
	elevatorLifterEncoder->SetDistancePerPulse(1.0);
        elevatorLifterEncoder->SetPIDSourceParameter(Encoder::kDistance);
	elevatorLifterMotor = new Talon(0);
	lw->AddActuator("Elevator", "LifterMotor", (Talon*) elevatorLifterMotor);
	
	elevatorUpperLimitSwitch = new DigitalInput(2);
	lw->AddSensor("Elevator", "Upper Limit Switch", elevatorUpperLimitSwitch);
	
	elevatorLowerLimitSwitch = new DigitalInput(3);
	lw->AddSensor("Elevator", "Lower Limit Switch", elevatorLowerLimitSwitch);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
