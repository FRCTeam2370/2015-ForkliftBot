/*
 * LiftComponent.cpp
 *
 *  Created on: Jan 12, 2015
 *      Author: Liam R. Bury
 */

#include "LiftComponent.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Encoder.h"

LiftComponent::LiftComponent() :
	m_liftMotor(9),						// Lift motor is in pwm 9
	m_liftEncoder(8, 9),				// Lift encoder is DI 8 & 9
	m_joystick(0),
	//m_liftPID(100.0, 0.0, 0.0, &m_liftEncoder, &m_liftMotor),
	m_topLimitSwitch(7),
	m_bottomLimitSwitch(6)
{
	m_liftEncoder.StartLiveWindowMode();
	m_liftEncoder.Reset();
	//m_liftPID.SetSetpoint(-10000);
	//m_liftPID.SetAbsoluteTolerance(10);
	//m_liftPID.SetContinuous(false);
}

LiftComponent::~LiftComponent()
{

}

void LiftComponent::Update()
{
	// Set the lift motor to one of 3 states: up, down, or stopped
	if (m_joystick.GetRawButton(5))
	{
		// Raise life
		if (m_topLimitSwitch.Get() == 0) { // Check limit switch
			m_liftMotor.SetSpeed(-1.0f);
		} else {
			m_liftMotor.SetSpeed(0.0f); // If limit is hit, maintain position
		}
	}
	else if (m_joystick.GetRawButton(3))
	{
		// Lower lift
		if (m_bottomLimitSwitch.Get() == 0) { // Check limit switch
			m_liftMotor.SetSpeed(1.0f);
		} else {
			m_liftMotor.SetSpeed(0.0f); // If limit is hit, maintain position
		}
	}
	else
	{
		// Stop
		m_liftMotor.SetSpeed(0.0f);
	}


	// If the bottom limit switch is hit, reset the encoder to 0
	// to recalibrate it
	if(m_bottomLimitSwitch.Get() != 0) {
		m_liftEncoder.Reset();
	}

	// Send some stuff to the dashboard
	SmartDashboard::PutBoolean("Top Limit Switch", m_topLimitSwitch.Get());
	SmartDashboard::PutBoolean("Bottom Limit Switch", m_bottomLimitSwitch.Get());
	SmartDashboard::PutNumber("Elevator Position", m_liftEncoder.GetRaw());
}

void LiftComponent::Reset()
{
	m_liftEncoder.Reset();
}
