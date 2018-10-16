/**
 * OI.cpp
 * See OI.h
 *
 * @author Marcus Behel
 *
 * Copyright (c) 2018 FRC Team 2655 - The Flying Platypi
 * See LICENSE file for details
 */

#include <OI.hpp>

Joystick* OI::js0 = nullptr;

// This is a cubic function config. See docs for details
jshelper::AxisConfig OI::driveAxisConfig = team2655::jshelper::createAxisConfig(0.1, 0.5, 0);

// This is a deadband only config. See docs for details
jshelper::AxisConfig OI::rotateAxisConfig = team2655::jshelper::createAxisConfig(0.1);

void OI::initControls(){
	js0 = new Joystick(0);
}

void OI::destroyControls(){
	delete js0;
}
