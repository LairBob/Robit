// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "SmartDashboard/SendableChooser.h"
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* techController;
	JoystickButton* button11;
	JoystickButton* button10;
	JoystickButton* button9;
	JoystickButton* button8;
	JoystickButton* button7;
	JoystickButton* button6;
	JoystickButton* button5;
	JoystickButton* button4;
	JoystickButton* trigger;
	Joystick* driveStick;
	JoystickButton* buttonL3;
	JoystickButton* buttonY;
	JoystickButton* buttonX;
	JoystickButton* buttonStart;
	JoystickButton* buttonBack;
	JoystickButton* shooterbutton;
	JoystickButton* buttonB;
	JoystickButton* buttonA;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();
 
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	Joystick* getDriveStick();
	Joystick* getTechController();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};
#endif
