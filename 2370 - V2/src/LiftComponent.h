/*
 * LiftComponent.h
 *
 *  Created on: Jan 12, 2015
 *      Author: Liam R. Bury
 */

#include "WPILib.h"

#define TICKS_PER_REVOLUTION 3600

#ifndef SRC_LIFTCOMPONENT_H_
#define SRC_LIFTCOMPONENT_H_

class LiftComponent
{
public:
	LiftComponent();
	virtual ~LiftComponent();

	void Update();
	void Reset();

private:
	TalonSRX m_liftMotor;
	Encoder m_liftEncoder;
	Joystick m_joystick;
	//PIDController m_liftPID;
	DigitalInput m_topLimitSwitch;
	DigitalInput m_bottomLimitSwitch;
};

#endif /* SRC_LIFTCOMPONENT_H_ */
