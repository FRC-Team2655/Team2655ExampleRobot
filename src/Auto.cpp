/**
 * Autonomous.cpp
 * See Autonomous.h
 *
 * @author Marcus Behel
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#include <Auto.hpp>
#include <algorithm>

#include "RobotMap.hpp"

//////////////////////////////////////////////////////////////
/// DriveAutoCommand
//////////////////////////////////////////////////////////////

void DriveAutoCommand::start(std::vector<std::string> args){
	// Call the parent function
	AutoCommand::start(args);

	// First arg should be direction (1 or -1)
	// Second arg should be time in seconds. Use the builtin timeout.
	this->setTimeout(1000 * stod(args[1]));
}

void DriveAutoCommand::process(){
	// Call the parent function
	AutoCommand::process();
	// Drive the robot
	RobotMap::robotDrive->ArcadeDrive(stoi(this->arguments[0]) * 0.5, 0, false);
}

void DriveAutoCommand::complete(){
	// Call the parent function
	AutoCommand::complete();
	// Stop driving
	RobotMap::robotDrive->ArcadeDrive(0, 0, false);
}

//////////////////////////////////////////////////////////////
/// RotateAutoCommand
//////////////////////////////////////////////////////////////

void RotateAutoCommand::start(std::vector<std::string> args){
	// Call the parent function
	AutoCommand::start(args);

	// First arg should be direction (1 or -1)
	// Second arg should be time in seconds. Use builtin timeout.
	this->setTimeout(1000 * stod(args[1]));
}

void RotateAutoCommand::process(){
	// Call the parent function
	AutoCommand::process();
	// Rotate in a certain direction
	RobotMap::robotDrive->ArcadeDrive(0, stoi(this->arguments[0]) * 0.5, false); // First arg is either -1 or 1
}

void RotateAutoCommand::complete(){
	// Call the parent function
	AutoCommand::complete();
	// Stop driving
	RobotMap::robotDrive->ArcadeDrive(0, 0, false);
}

//////////////////////////////////////////////////////////////
/// DelayAutoCommand
//////////////////////////////////////////////////////////////

void DelayAutoCommand::start(std::vector<std::string> args){
	// Call the parent function
	AutoCommand::start(args);

	// First arg should be time in seconds. Use builtin timeout
	this->setTimeout(1000 * stod(args[0]));
}

void DelayAutoCommand::process(){
	// Call the parent function
	AutoCommand::process();
	// Don't need to do anything for the delay function

	// Make sure this is updated frequently (this just avoids warning messages) it is not required for this command to work.
	RobotMap::robotDrive->ArcadeDrive(0, 0, false);
}

void DelayAutoCommand::complete(){
	// Call the parent function
	AutoCommand::complete();
	// Nothing to stop for this command
}

//////////////////////////////////////////////////////////////
/// ExampleAutoManager
//////////////////////////////////////////////////////////////

std::string ExampleAutoManager::getScriptDir(){
	return "/auto-scripts"; // A path on the RoboRIO's file system. Can be accessed via SFTP
}

std::unique_ptr<team2655::AutoCommand> ExampleAutoManager::getCommand(std::string commandName){
	// This will return a unique_ptr to a new AutoCommand based on the command name.
	// Which specific implementation of AutoCommand is determined based on the commandName.
	// This is how command names (strings) are mapped to the actual commands (AutoCommands)

	// Convert commandName to upper case so all comparisons are case insensitive
	std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::toupper);

	// Now upper case so all comparisons should also be upper case
	if(commandName == "DRIVE"){
		return std::unique_ptr<team2655::AutoCommand>(new DriveAutoCommand());
	}else if(commandName == "ROTATE"){
		return std::unique_ptr<team2655::AutoCommand>(new RotateAutoCommand());
	}else if(commandName == "DELAY"){
		return std::unique_ptr<team2655::AutoCommand>(new DelayAutoCommand());
	}else{
		return std::unique_ptr<team2655::AutoCommand>(nullptr); // For any unknown command
	}
}
