/**
 * RobotMap.cpp
 * See RobotMap.h
 *
 * @author Marcus Behel
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#include <RobotMap.hpp>

// Give all the static objects a value. NOTE: These must be initialized after RobotInit is called
//      or CAN communication will not work properly
WPI_TalonSRX *RobotMap::leftMaster = nullptr;
WPI_TalonSRX *RobotMap::leftSlave1 = nullptr;
WPI_TalonSRX *RobotMap::leftSlave2 = nullptr;
WPI_TalonSRX *RobotMap::rightMaster = nullptr;
WPI_TalonSRX *RobotMap::rightSlave1 = nullptr;
WPI_TalonSRX *RobotMap::rightSlave2 = nullptr;

DifferentialDrive *RobotMap::robotDrive = nullptr;

void RobotMap::initHardware(){
	leftMaster = new WPI_TalonSRX(1);
	leftSlave1 = new WPI_TalonSRX(2);
	leftSlave2 = new WPI_TalonSRX(3);
	rightMaster = new WPI_TalonSRX(4);
	rightSlave1 = new WPI_TalonSRX(5);
	rightSlave2 = new WPI_TalonSRX(6);

	// Differential drive handles tank style drive systems. Give it the left and right masters.
	robotDrive = new DifferentialDrive(*RobotMap::leftMaster, *RobotMap::rightMaster);
}

void RobotMap::destroyHardware(){
	delete leftMaster;
	delete leftSlave1;
	delete leftSlave2;
	delete rightMaster;
	delete rightSlave1;
	delete rightSlave2;
	delete robotDrive;
}
