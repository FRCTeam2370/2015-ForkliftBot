// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/CalibrateElevator.h"
#include "Commands/ElevatorFloor.h"
#include "Commands/ElevatorTopOf1.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	customOIPanel-1 = new Joystick(0);
	
	oI-Elevator-TopOf1 = new JoystickButton(customOIPanel-1, 1);
	oI-Elevator-TopOf1->WhenPressed(new ElevatorTopOf1());
	oI-ElevatorFloor = new JoystickButton(customOIPanel-1, 1);
	oI-ElevatorFloor->WhenPressed(new ElevatorFloor());
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("ElevatorFloor", new ElevatorFloor());

	SmartDashboard::PutData("ElevatorTopOf1", new ElevatorTopOf1());

	SmartDashboard::PutData("CalibrateElevator", new CalibrateElevator());

        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getCustomOIPanel-1() {
	return customOIPanel-1;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS