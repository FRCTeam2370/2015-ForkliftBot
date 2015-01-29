#include "WPILib.h"
#include "Joystick.h"



/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick;
	Talon ElevatorMotor;
	Encoder ElevatorEncoder;
	DigitalInput TopLimitSwitch;
	DigitalInput BottomLimitSwitch;
	PIDController ElevatorPID;

public:
	Robot() :
			myRobot(0, 1),	// these must be initialized in the same order
			stick(0),		// as they are declared above.
			ElevatorMotor(9),
			ElevatorEncoder(8,9),
			TopLimitSwitch(7),
			BottomLimitSwitch(6),
			ElevatorPID(1.0, 0.0, 0.0, &ElevatorEncoder, &ElevatorMotor)
	{
		myRobot.SetExpiration(0.1);

	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		ElevatorEncoder.StartLiveWindowMode();
		ElevatorEncoder.Reset();
		ElevatorPID.SetSetpoint(-10000);
		ElevatorPID.SetAbsoluteTolerance(10);

		bool32 PIDEnabled = false;


		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{


			if ( stick.GetRawButton(1))
			{
			}
			else if (stick.GetRawButton(2))
			{
				// Manual Encoder Reset
				ElevatorEncoder.Reset();
			}
			else if (stick.GetRawButton(3))
			{
				// Elevator down
				if (BottomLimitSwitch.Get() == 0) {
					ElevatorMotor.SetSpeed(1.0f);
				} else {
					ElevatorMotor.SetSpeed(0.0f);
				}
			}
			else if (stick.GetRawButton(4))
			{
				PIDEnabled = false;
			}
			else if (stick.GetRawButton(5))
			{
				// Elevator up
				if (TopLimitSwitch.Get() == 0) {
					ElevatorMotor.SetSpeed(-1.0f);
				} else {
					ElevatorMotor.SetSpeed(0.0f);
				}
			}
			else if (stick.GetRawButton(6))
			{
				PIDEnabled = true;
			}
			else if (stick.GetRawButton(7))
			{
			}
			else if (stick.GetRawButton(8))
			{
			}
			else if (stick.GetRawButton(9))
			{
			}
			else if (stick.GetRawButton(10))
			{
			}
			else if (stick.GetRawButton(11))
			{
			}
			else if (stick.GetRawButton(12))
			{
			}
			else
			{
				ElevatorMotor.SetSpeed(0.0);
				ElevatorPID.Disable();
			}



			if(PIDEnabled == true)
			{
				ElevatorPID.Enable();
			}
			else
			{
				ElevatorPID.Disable();
			}



			// Send some stuff to the dashboard
			SmartDashboard::PutBoolean("Top Limit Switch", TopLimitSwitch.Get());
			SmartDashboard::PutBoolean("Bottom Limit Switch", BottomLimitSwitch.Get());
			SmartDashboard::PutNumber("Elevator Position", ElevatorEncoder.GetRaw()/4);
			SmartDashboard::PutBoolean("PID Control Enabled ", PIDEnabled);

			myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);
