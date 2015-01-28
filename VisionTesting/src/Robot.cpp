#include "WPILib.h"

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
	Talon m_talon;
	Encoder m_encoder;
	PIDController m_pidController;

public:
	Robot() :
		m_talon(0),
		m_encoder(0, 1),
		m_pidController(0.1f, 0.1f, 0.1f, &m_encoder, &m_talon, 0.05f)
	{
		m_encoder.SetPIDSourceParameter(PIDSource::PIDSourceParameter::kDistance);
	}

	void Autonomous()
	{

	}

	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			printf("Encoder: %f.2\n", (float)m_encoder.GetDistance());

			Wait(0.1);
		}
	}
};

START_ROBOT_CLASS(Robot);
