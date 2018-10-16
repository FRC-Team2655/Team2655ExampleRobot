/**
 * OI.h
 * Static class that handles user input
 *
 * @author Marcus Behel
 * @version 1.0 10-8-2018
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#pragma once

#include "team2655/joystick.hpp"

#include <Joystick.h>

using namespace frc;
using namespace team2655;

class OI{
public:
	static Joystick *js0;

	// Create a configuration for the drive and rotate axes
	static jshelper::AxisConfig driveAxisConfig;
	static jshelper::AxisConfig rotateAxisConfig;

	// Initialize objects for each Joystick or controller. Should be called in RobotInit after RobotMap::initHardware
	static void initControls();

	// Delete all the pointers in this class to avoid memory leaks. call from robot's destructor
	static void destroyControls();
};
