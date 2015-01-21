/*
 * Elevator.h
 *
 *  Created on: Jan 20, 2015
 *      Author: Liam R. Bury
 */

#include "WPILib.h"

#ifndef SRC_ELEVATOR_H_
#define SRC_ELEVATOR_H_

class Elevator
{
	Talon m_motor;
	Encoder m_encoder;
	PIDController m_pidController;
	uint32_t m_setPoint;

public:
	Elevator();
	void Update();
	void Init();
};

#endif /* SRC_ELEVATOR_H_ */
