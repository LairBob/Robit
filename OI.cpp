// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonShoot.h"
#include "Commands/AutonShootBackupOccupyFrisbees.h"
#include "Commands/AutonShootGatherAllShoot.h"
#include "Commands/AutonShootGatherShoot.h"
#include "Commands/AutonShootGatherShootGatherShoot.h"
#include "Commands/AutonShootOnly.h"
#include "Commands/Climb.h"
#include "Commands/DecreaseAutonDelay.h"
#include "Commands/DecreaseShooterRPM.h"
#include "Commands/DeployEverything.h"
#include "Commands/DeployGather.h"
#include "Commands/DeployShooter.h"
#include "Commands/DoNothing.h"
#include "Commands/DriveForward.h"
#include "Commands/EmptyCommand.h"
#include "Commands/Idleshooter.h"
#include "Commands/IncreaseAutoDelay.h"
#include "Commands/IncreaseShooterRPM.h"
#include "Commands/MoveAutonLeft.h"
#include "Commands/MoveAutonRight.h"
#include "Commands/MoveCamera.h"
#include "Commands/ResetDrivetrainMotors.h"
#include "Commands/RetractGather.h"
#include "Commands/RetractShooter.h"
#include "Commands/RunFeeder.h"
#include "Commands/RunGather.h"
#include "Commands/SetShooterPreset1.h"
#include "Commands/SetShooterPreset2.h"
#include "Commands/ShiftToHigh.h"
#include "Commands/ShiftToLow.h"
#include "Commands/Shoot.h"
#include "Commands/StopGather.h"
#include "Commands/TelOpDrive.h"
#include "Commands/ToggleGatherDeploy.h"
#include "Commands/ToggleShift.h"
#include "Commands/ToggleShooterDeploy.h"
#include "Commands/TurnRobotToFace.h"
#include "Commands/TurnWhileDriving.h"
#include "Commands/ZeroCamera.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
// This is just a dummy UI to test the robot.
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	techController = new Joystick(2);
	
	button11 = new JoystickButton(techController, 11);
	button11->WhenPressed(new IncreaseShooterRPM());
	button10 = new JoystickButton(techController, 10);
	button10->WhenPressed(new DecreaseShooterRPM());
	button9 = new JoystickButton(techController, 9);
	button9->WhenPressed(new SetShooterPreset2());
	button8 = new JoystickButton(techController, 8);
	button8->WhenPressed(new SetShooterPreset1());
	button7 = new JoystickButton(techController, 7);
	button7->WhenPressed(new DecreaseAutonDelay());
	button6 = new JoystickButton(techController, 6);
	button6->WhenPressed(new IncreaseAutoDelay());
	button5 = new JoystickButton(techController, 5);
	button5->WhenPressed(new MoveAutonRight());
	button4 = new JoystickButton(techController, 4);
	button4->WhenPressed(new MoveAutonLeft());
	trigger = new JoystickButton(techController, 1);
	trigger->WhileHeld(new MoveCamera());
	driveStick = new Joystick(1);
	
	buttonLeft = new JoystickButton(driveStick, 5);
	buttonLeft->WhileHeld(new RunGather());
	buttonL3 = new JoystickButton(driveStick, 9);
	buttonL3->WhileHeld(new ShiftToLow());
	buttonY = new JoystickButton(driveStick, 4);
	buttonY->WhenPressed(new ToggleShooterDeploy());
	buttonX = new JoystickButton(driveStick, 3);
	buttonX->WhenPressed(new ToggleGatherDeploy());
	buttonStart = new JoystickButton(driveStick, 8);
	buttonStart->WhileHeld(new Climb());
	buttonBack = new JoystickButton(driveStick, 7);
	buttonBack->WhileHeld(new RunFeeder());
	shooterbutton = new JoystickButton(driveStick, 6);
	shooterbutton->WhileHeld(new Shoot());
	buttonB = new JoystickButton(driveStick, 2);
	buttonB->WhenPressed(new EmptyCommand());
	buttonA = new JoystickButton(driveStick, 1);
	buttonA->WhenPressed(new EmptyCommand());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("TelOpDrive", new TelOpDrive());
	SmartDashboard::PutData("DriveForward", new DriveForward());
	SmartDashboard::PutData("TurnRobotToFace", new TurnRobotToFace());
	SmartDashboard::PutData("TurnWhileDriving", new TurnWhileDriving());
	SmartDashboard::PutData("ToggleShift", new ToggleShift());
	SmartDashboard::PutData("ShiftToLow", new ShiftToLow());
	SmartDashboard::PutData("ShiftToHigh", new ShiftToHigh());
	SmartDashboard::PutData("ResetDrivetrainMotors", new ResetDrivetrainMotors());
	SmartDashboard::PutData("RunFeeder", new RunFeeder());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("Idleshooter", new Idleshooter());
	SmartDashboard::PutData("DeployShooter", new DeployShooter());
	SmartDashboard::PutData("RetractShooter", new RetractShooter());
	SmartDashboard::PutData("ToggleShooterDeploy", new ToggleShooterDeploy());
	SmartDashboard::PutData("RetractGather", new RetractGather());
	SmartDashboard::PutData("DeployGather", new DeployGather());
	SmartDashboard::PutData("ToggleGatherDeploy", new ToggleGatherDeploy());
	SmartDashboard::PutData("AutonShoot", new AutonShoot());
	SmartDashboard::PutData("RunGather", new RunGather());
	SmartDashboard::PutData("StopGather", new StopGather());
	SmartDashboard::PutData("DeployEverything", new DeployEverything());
	SmartDashboard::PutData("AutonShootOnly", new AutonShootOnly());
	SmartDashboard::PutData("AutonShootGatherShoot", new AutonShootGatherShoot());
	SmartDashboard::PutData("AutonShootGatherAllShoot", new AutonShootGatherAllShoot());
	SmartDashboard::PutData("AutonShootGatherShootGatherShoot", new AutonShootGatherShootGatherShoot());
	SmartDashboard::PutData("AutonShootBackupOccupyFrisbees", new AutonShootBackupOccupyFrisbees());
	SmartDashboard::PutData("DoNothing", new DoNothing());
	SmartDashboard::PutData("Climb", new Climb());
	SmartDashboard::PutData("MoveAutonLeft", new MoveAutonLeft());
	SmartDashboard::PutData("MoveAutonRight", new MoveAutonRight());
	SmartDashboard::PutData("IncreaseAutoDelay", new IncreaseAutoDelay());
	SmartDashboard::PutData("DecreaseAutonDelay", new DecreaseAutonDelay());
	SmartDashboard::PutData("SetShooterPreset1", new SetShooterPreset1());
	SmartDashboard::PutData("SetShooterPreset2", new SetShooterPreset2());
	SmartDashboard::PutData("IncreaseShooterRPM", new IncreaseShooterRPM());
	SmartDashboard::PutData("DecreaseShooterRPM", new DecreaseShooterRPM());
	SmartDashboard::PutData("EmptyCommand", new EmptyCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutNumber("Fwd Speed", 0.5);
	SmartDashboard::PutNumber("ShooterSpeed", 2250.0);
	SmartDashboard::PutNumber("RobotTravelDistance", 24.0);
	SmartDashboard::PutNumber("AutonShootDuration", 4.0);
	SmartDashboard::PutNumber("FeederSpeed", 0.5);
	SmartDashboard::PutNumber("LeftRightAdjust", 0.03);
	SmartDashboard::PutNumber("Stick Twist", 0.0);
	SmartDashboard::PutNumber("Stick Y", 0.0);
	SmartDashboard::PutNumber("P", 0.6);
	SmartDashboard::PutNumber("I", 0.03);
	SmartDashboard::PutNumber("D", 0.05);
	SmartDashboard::PutNumber("jaguarRPM", 3322.0);
	SmartDashboard::PutNumber("Delay", 0.0);
	SmartDashboard::PutNumber("GatherSpeed", 0.7);
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getTechController() {
	return techController;
}
Joystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
