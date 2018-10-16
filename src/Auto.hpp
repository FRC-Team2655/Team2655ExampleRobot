/**
 * Autonomous.h
 *
 * Defines the custom AutoManager and all the AutoCommands
 *
 * @author Marcus Behel
 * @version 1.0 10-8-2018
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#include <memory>
#include <vector>
#include <string>
#include "team2655/autonomous.hpp"

#pragma once

/*
 * Create each auto command.
 * In this example we will have 3
 *     Drive
 *     Rotate
 *     Wait
 *
 *     Each command overrides 3 methods: start, process, and complete
 *     The start method is called by the auto manager when the command first starts executing. The args given
 *       to the start function are stored in the AutoCommand's arguments member variable.
 *     The process function is called by the AutoManager while the command is running. This is where periodic
 *       tasks should be executed for a command. This will be called as frequently as the AutoManager's process
 *       function is called.
 *     The complete function is called when the command has been completed or is being killed by the AutoManager.
 *       Normally commands will run their own complete method from their process method when the command has
 *       accomplished its task, however calling killAuto from the AutoManager will also run the command's complete
 *       function. This function should stop any in-progress tasks from the command.
 *
 *     *** IT IS IMPORTANT TO CALL THE BASE METHOD FOR EACH OVERRIDEN FUNCTION IN EACH AUTO COMMAND OTHERWISE
 *         NONE OF THE BUILTIN BEHAVIORS (INCLUDING TIMEOUTS) WILL WORK ***
 *
 * Each command will be mapped to a string by the getCommand function of the custom AutoManager
 */

class DriveAutoCommand : public team2655::AutoCommand{
	void start(std::vector<std::string> args) override;
	void process() override;
	void complete() override;
};

class RotateAutoCommand : public team2655::AutoCommand{
	void start(std::vector<std::string> args) override;
	void process() override;
	void complete() override;
};

class DelayAutoCommand : public team2655::AutoCommand{
	void start(std::vector<std::string> args) override;
	void process() override;
	void complete() override;
};

/**
 * This is our custom auto manager. It overrides the two pure virtual functions
 * 		getCommand - creates a unique_ptr to a new custom AutoCommand based on
 * 		             a string (this is how strings are mapped to commands)
 *      getScriptDir - returns the path (as a string) to the directory where csv scripts are stored
 */
class ExampleAutoManager : public team2655::AutoManager{
protected:
	std::string getScriptDir() override;
	std::unique_ptr<team2655::AutoCommand> getCommand(std::string commandName) override;
};
