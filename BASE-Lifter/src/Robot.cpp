#include "WPILib.h"

/**
 * This sample program shows how to control a motor using a joystick. In the operator
 * control part of the program, the joystick is read and the value is written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as range from
 * -1 to 1 making it easy to work together. The program also delays a short time in the loop
 * to allow other threads to run. This is generally a good idea, especially since the joystick
 * values are only transmitted from the Driver Station once every 20ms.
 */
class Robot : public SampleRobot {

	CANTalon lifterA_motor;
	CANTalon lifterB_motor;
	DigitalInput TopLimitSwitch;
	DigitalInput BottomLimitSwitch;
	Encoder LifterEncoder;

	Joystick stick;

	// The motor to control with the Joystick.
	// This uses a Talon speed controller; use the Victor or Jaguar classes for
	//   other speed controllers.


	// update every 0.005 seconds/5 milliseconds.
	double kUpdatePeriod = 0.005;

public:
	Robot() :
		 // Initialize Joystick on port 0.
			lifterA_motor(10), // Initialize the Talon on channel 0.
			lifterB_motor(11), // Initialize the Talon on channel 0.
			TopLimitSwitch(9),
			BottomLimitSwitch(8),
			LifterEncoder(6,7),
			stick(0)
	{

	}

	/**
	 * Runs the motor from the output of a Joystick.
	 */
	void OperatorControl() {

		LifterEncoder.StartLiveWindowMode();
		LifterEncoder.Reset();



		while (IsOperatorControl() && IsEnabled()) {
			// Set the motor controller's output.
			// This takes a number from -1 (100% speed in reverse) to +1 (100% speed forwards).
			// lifterA_motor.Set(joy.GetY());
			// lifterB_motor.Set(joy.GetY());


			if ( stick.GetRawButton(1))
			{
			}
			else if (stick.GetRawButton(2))
			{
			}
			else if (stick.GetRawButton(3))
			{
				// Elevator down
				if (BottomLimitSwitch.Get() == 0) {
					lifterA_motor.Set(0.5);
					lifterB_motor.Set(0.5);
				} else {
					lifterA_motor.Set(0);
					lifterB_motor.Set(0);
				}
			}
			else if (stick.GetRawButton(4))
			{
			}
			else if (stick.GetRawButton(5))
			{
				// Elevator up
				if (TopLimitSwitch.Get() == 0) {
					lifterA_motor.Set(-0.5);
					lifterB_motor.Set(-0.5);
				} else {
					lifterA_motor.Set(0);
					lifterB_motor.Set(0);
				}
			}
			else if (stick.GetRawButton(6))
			{
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
				lifterA_motor.Set(0.0);
				lifterB_motor.Set(0.0);
			}


			if(BottomLimitSwitch.Get()==true)
			{
				LifterEncoder.Reset();
			}

			// Send some stuff to the dashboard
			SmartDashboard::PutBoolean("Top Limit Switch", TopLimitSwitch.Get());
			SmartDashboard::PutBoolean("Bottom Limit Switch", BottomLimitSwitch.Get());
			SmartDashboard::PutNumber("Encoder Position",LifterEncoder.GetRaw());

			Wait(kUpdatePeriod); // Wait 5ms for the next update.
		}
	}
};

START_ROBOT_CLASS(Robot);
