#include "WPILib.h"
#include "DriveComponent.h"
#include "LiftComponent.h"
#include "GrabberComponent.h"
#include "SmartDashboard/SmartDashboard.h"

class Robot: public SampleRobot
{
	//DriveComponent m_driveComponent;
	LiftComponent m_liftComponent;
	//GrabberComponent m_grabberComponent;

public:
	Robot() :
		//m_driveComponent(),
		m_liftComponent()
		//m_grabberComponent()
	{

	}

	void Autonomous()
	{
		//m_driveComponent.DisableSafety();
		m_liftComponent.Reset();

		while (IsAutonomous() && IsEnabled())
		{


			Wait(0.005);
		}
	}

	void OperatorControl()
	{
		//m_driveComponent.EnableSafety();
		m_liftComponent.Reset();

		while (IsOperatorControl() && IsEnabled())
		{
			//m_driveComponent.Update();
			m_liftComponent.Update();
			//m_grabberComponent.Update();

			Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(Robot);
