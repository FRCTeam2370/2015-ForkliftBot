/*
 * DriveComponent.cpp
 *
 *  Created on: Jan 12, 2015
 *      Author: Liam R. Bury
 */

#include "DriveComponent.h"

DriveComponent::DriveComponent() :
	m_robotDrive(PWM_WHEEL_FRONT_LEFT, PWM_WHEEL_REAR_LEFT, PWM_WHEEL_FRONT_RIGHT, PWM_WHEEL_REAR_RIGHT),
	m_joystick(JOYSTICK_ID),
	m_encoder(8, 9),
	m_spinAmount(0),
	m_magnitude(0),
	m_direction(0)
{
	m_encoder.Reset();
}

DriveComponent::~DriveComponent()
{

}

void DriveComponent::Update()
{
	m_spinAmount = -m_joystick.GetRawAxis(JOYSTICK_TWIST);
	m_magnitude = m_joystick.GetMagnitude();
	m_direction = -m_joystick.GetDirectionDegrees() - 90;

	// set magnitude deadband to 0.1
	if (m_magnitude < DEADBAND_SPEED)
		m_magnitude = 0.0f;

	// clamp magnitude
	if (m_magnitude > 1.0f)
		m_magnitude = 1.0f;

	m_magnitude *= m_magnitude;

	// set rotation deadband to 0.1
	if (m_spinAmount < DEADBAND_SPIN && m_spinAmount > -DEADBAND_SPIN)
		m_spinAmount = 0.0f;

	// Drive dammit!!
	m_robotDrive.MecanumDrive_Polar(m_magnitude, m_direction, m_spinAmount);

	// Debug encoder
	printf("RAW Encoder: %f.2\n", (float)m_encoder.GetRaw());
}

void DriveComponent::EnableSafety()
{
	m_robotDrive.SetSafetyEnabled(true);
}

void DriveComponent::DisableSafety()
{
	m_robotDrive.SetSafetyEnabled(false);
}
