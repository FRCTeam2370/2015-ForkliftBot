#include "WPILib.h"
#include "Elevator.h"

class Robot: public SampleRobot
{
	Joystick m_joystick;
	//Elevator m_elevator;

public:
	Robot() :
		m_joystick(0)
		//m_elevator()
	{

	}

	void Autonomous()
	{

	}

	void OperatorControl()
	{
		//m_elevator.Init();

		while (IsOperatorControl() && IsEnabled())
		{
			//m_elevator.Update();

			Wait(0.05);
		}
	}
};

START_ROBOT_CLASS(Robot);
