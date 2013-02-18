// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shoot.h"
Shoot::Shoot() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Shoot::Initialize() {
	SetTimeout(2.0);
}
// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	double speed = 	SmartDashboard::GetNumber("ShooterSpeed");
	Robot::shooter->mainMotor->Set(speed);
	if (IsTimedOut()) {
		double speed = SmartDashboard::GetNumber("FeederSpeed");
		Robot::shooter->feedMotor->Set(speed);
		Robot::shooter->flipper->Set(Relay::kReverse);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	// This command is connected to a WhileHeld button. When the button
	// is released, the command is cancelled and the default subsystem
	// command activates.
	return false;
}
// Called once after isFinished returns true
void Shoot::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
}
