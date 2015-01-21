/*
 * Elevator.cpp
 *
 *  Created on: Jan 20, 2015
 *      Author: Liam R. Bury
 */

#include "Elevator.h"

Elevator::Elevator() :
	m_motor(0),
	m_encoder(0, 1),
	m_pidController(0.1f, 0.1f, 0.1f, &m_encoder, &m_motor, 0.05f),
	m_setPoint(0)
{

}

void Elevator::Update()
{
	printf("Encoder: %d, SetPoint: %d\n",
		m_encoder.GetRaw(), m_setPoint);
}

void Elevator::Init()
{
	m_encoder.Reset();
	m_setPoint = 0;

	m_pidController.SetSetpoint(m_setPoint);
}
