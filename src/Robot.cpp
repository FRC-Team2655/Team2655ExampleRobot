/**
 * Robot.cpp
 * See Robot.h
 *
 * @author Marcus Behel
 * @version 1.0 10-8-2018
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#include <OI.hpp>
#include <Robot.hpp>
#include <RobotMap.hpp>
#include <iostream>

using namespace team2655;

void Robot::RobotInit() {
	// Create all objects in RobotMap and OI
	RobotMap::initHardware();
	OI::initControls();

	// Configure each slave to follow the master for the same side
	RobotMap::leftSlave1->Follow(*RobotMap::leftMaster);
	RobotMap::leftSlave2->Follow(*RobotMap::leftMaster);
	RobotMap::rightSlave1->Follow(*RobotMap::rightMaster);
	RobotMap::rightSlave2->Follow(*RobotMap::rightMaster);

	// Flip forwards and backwards
	RobotMap::leftMaster->SetInverted(true);
	RobotMap::leftSlave1->SetInverted(true);
	RobotMap::leftSlave2->SetInverted(true);
	RobotMap::rightMaster->SetInverted(true);
	RobotMap::rightSlave1->SetInverted(true);
	RobotMap::rightSlave2->SetInverted(true);
}

void Robot::AutonomousInit() {
	// Coasting in auto can cause distances/angles to be off so use brake mode
	RobotMap::leftMaster->SetNeutralMode(NeutralMode::Brake);
	RobotMap::leftSlave1->SetNeutralMode(NeutralMode::Brake);
	RobotMap::leftSlave2->SetNeutralMode(NeutralMode::Brake);
	RobotMap::rightMaster->SetNeutralMode(NeutralMode::Brake);
	RobotMap::rightSlave1->SetNeutralMode(NeutralMode::Brake);
	RobotMap::rightSlave2->SetNeutralMode(NeutralMode::Brake);

	// Load a script at the start of auto
	// Note: Script names are case sensitive and must be a full file name (including the extension)
	if(!autoManager.loadScript("Test.csv")){
		// If the auto manager fails to load the script, manually insert a fallback
		// This is likely due to a missing script, wrong directory, or occasionally incorrect permissions for the script

		// Make sure there are no commands that could have been loaded (should not be possible, but...)
		autoManager.clearCommands();
		// Insert a script
		autoManager.addCommands({"DRIVE", "ROTATE"}, {{"-1", "1"}, {"-1", "0.5"}});
	}
}

void Robot::AutonomousPeriodic() {
	// Have the auto manager process the current command
	if(!autoManager.process()){
		// When this returns false it has reached the end of the script
		RobotMap::robotDrive->ArcadeDrive(0, 0, false); // Make sure this is updated frequently (avoids warnings)
	}
}

void Robot::TeleopInit() {
	// Driving is more natural with coast mode
	RobotMap::leftMaster->SetNeutralMode(NeutralMode::Coast);
	RobotMap::leftSlave1->SetNeutralMode(NeutralMode::Coast);
	RobotMap::leftSlave2->SetNeutralMode(NeutralMode::Coast);
	RobotMap::rightMaster->SetNeutralMode(NeutralMode::Coast);
	RobotMap::rightSlave1->SetNeutralMode(NeutralMode::Coast);
	RobotMap::rightSlave2->SetNeutralMode(NeutralMode::Coast);
}

void Robot::TeleopPeriodic() {
	// Get the values from the AxisConfigurations stored in OI
	double speed = jshelper::getAxisValue(OI::driveAxisConfig, OI::js0->GetRawAxis(1));
	double rotation = -0.5 * jshelper::getAxisValue(OI::rotateAxisConfig, OI::js0->GetRawAxis(2));
	RobotMap::robotDrive->ArcadeDrive(speed, rotation, false);
}

START_ROBOT_CLASS(Robot)
