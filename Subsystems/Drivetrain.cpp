// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/TelOpDrive.h"
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotorA = RobotMap::drivetrainLeftMotorA;
	leftMotorB = RobotMap::drivetrainLeftMotorB;
	rightMotorA = RobotMap::drivetrainRightMotorA;
	rightMotorB = RobotMap::drivetrainRightMotorB;
	drive = RobotMap::drivetrainDrive;
	shiftGear = RobotMap::drivetrainShiftGear;
	leftEncoder = RobotMap::drivetrainLeftEncoder;
	rightEncoder = RobotMap::drivetrainRightEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new TelOpDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::ShiftIntoLowGear() {
	shiftGear->Set(DoubleSolenoid::kForward);
}
void Drivetrain::ShiftIntoHighGear() {
	shiftGear->Set(DoubleSolenoid::kReverse);
}
void Drivetrain::ToggleShiftGears() {
	DoubleSolenoid::Value newGear = (shiftGear->Get() == DoubleSolenoid::kForward) ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward;
	shiftGear->Set(newGear);
}
void Drivetrain::Snapshot(){
	Robot::diag->MotorSnapShot(2,leftMotorA->GetBusVoltage(),leftMotorA->GetOutputCurrent());
	Robot::diag->MotorSnapShot(3,leftMotorB->GetBusVoltage(),leftMotorB->GetOutputCurrent());
	Robot::diag->MotorSnapShot(4,rightMotorA->GetBusVoltage(),rightMotorA->GetOutputCurrent());
	Robot::diag->MotorSnapShot(5,rightMotorB->GetBusVoltage(),rightMotorB->GetOutputCurrent());
}
