/**
 * RobotMap.h
 * Contains the RobotMap class which has static member objects for all hardware devices on
 * the robot. This allows these devices to be accessed from multiple classes (such as auto commands)
 *
 * @author Marcus Behel
 * @version 1.0 10-8-2018
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#pragma once

#include <Drive/DifferentialDrive.h>
#include <Joystick.h>
#include <ctre/Phoenix.h>

using namespace frc;

class RobotMap{
public:
	// Motor controllers and Drive controller (Note: 3 motors on each side of drivetrain, slaves follow the master for each side)
	static WPI_TalonSRX *leftMaster, *leftSlave1, *leftSlave2, *rightMaster, *rightSlave1, *rightSlave2;
	static DifferentialDrive *robotDrive;

	// This method sets up all devices defined in this class. This should be called from RobotInit.
	static void initHardware();

	// Delete all the pointers in this class to avoid memory leaks. Call from robot's destructor
	static void destroyHardware();
};
