/**
 * Robot.h
 * An example showing how to use the team2655 autonomous helper code
 * NOTE: This example relies on CTRE's phoenix libraries as it uses Talon SRX motor controllers
 *       http://www.ctr-electronics.com/hro.html#product_tabs_technical_resources
 *
 * @author Marcus Behel
 * @version 1.0 10-8-2018
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#pragma once

#include <IterativeRobot.h>
#include "Auto.hpp"

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
private:
	ExampleAutoManager autoManager;
};
