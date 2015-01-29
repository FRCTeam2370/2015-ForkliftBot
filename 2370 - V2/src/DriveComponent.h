/*
 * DriveComponent.h
 *
 *  Created on: Jan 12, 2015
 *      Author: Liam R. Bury
 */

#include "WPILib.h"

#ifndef SRC_DRIVECOMPONENT_H_
#define SRC_DRIVECOMPONENT_H_

#define RADIANS_TO_DEGREES 57.2957795130823f

#define PWM_WHEEL_FRONT_RIGHT 1
#define PWM_WHEEL_FRONT_LEFT 0
#define PWM_WHEEL_REAR_RIGHT 3
#define PWM_WHEEL_REAR_LEFT 4
#define JOYSTICK_ID 0
#define JOYSTICK_TWIST 2
#define DEADBAND_SPEED 0.1f
#define DEADBAND_SPIN 0.1f

class DriveComponent
{
public:
	DriveComponent();
	virtual ~DriveComponent();

	void Reset();
	void Update();
	void DisableSafety();
	void EnableSafety();

private:
	RobotDrive m_robotDrive;
	Joystick m_joystick;
	Encoder m_encoder;

	float m_spinAmount;
	float m_magnitude;
	float m_direction;
};

#endif /* SRC_DRIVECOMPONENT_H_ */
