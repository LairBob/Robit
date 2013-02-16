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
#include "Commands/DeployEverything.h"
#include "Commands/DeployGather.h"
#include "Commands/DeployShooter.h"
#include "Commands/DriveForward.h"
#include "Commands/Idleshooter.h"
#include "Commands/RetractGather.h"
#include "Commands/RetractShooter.h"
#include "Commands/RunGather.h"
#include "Commands/ShiftToHigh.h"
#include "Commands/ShiftToLow.h"
#include "Commands/Shoot.h"
#include "Commands/StopGather.h"
#include "Commands/TelOpDrive.h"
#include "Commands/TurnRobotToFace.h"
#include "Commands/TurnWhileDriving.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
// This is just a dummy UI to test the robot.
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveStick = new Joystick(1);
	
	buttonY = new JoystickButton(driveStick, 4);
	buttonY->WhenPressed(new DeployShooter());
	shooterbutton = new JoystickButton(driveStick, 5);
	shooterbutton->WhileHeld(new Shoot());
	buttonB = new JoystickButton(driveStick, 2);
	buttonB->WhenPressed(new ShiftToHigh());
	buttonA = new JoystickButton(driveStick, 1);
	buttonA->WhenPressed(new ShiftToLow());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("TelOpDrive", new TelOpDrive());
	SmartDashboard::PutData("DriveForward", new DriveForward());
	SmartDashboard::PutData("TurnRobotToFace", new TurnRobotToFace());
	SmartDashboard::PutData("TurnWhileDriving", new TurnWhileDriving());
	SmartDashboard::PutData("ShiftToLow", new ShiftToLow());
	SmartDashboard::PutData("ShiftToHigh", new ShiftToHigh());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("Idleshooter", new Idleshooter());
	SmartDashboard::PutData("DeployShooter", new DeployShooter());
	SmartDashboard::PutData("RetractShooter", new RetractShooter());
	SmartDashboard::PutData("DeployGather", new DeployGather());
	SmartDashboard::PutData("RetractGather", new RetractGather());
	SmartDashboard::PutData("AutonShoot", new AutonShoot());
	SmartDashboard::PutData("RunGather", new RunGather());
	SmartDashboard::PutData("StopGather", new StopGather());
	SmartDashboard::PutData("DeployEverything", new DeployEverything());
	SmartDashboard::PutData("AutonShootOnly", new AutonShootOnly());
	SmartDashboard::PutData("AutonShootGatherShoot", new AutonShootGatherShoot());
	SmartDashboard::PutData("AutonShootGatherAllShoot", new AutonShootGatherAllShoot());
	SmartDashboard::PutData("AutonShootGatherShootGatherShoot", new AutonShootGatherShootGatherShoot());
	SmartDashboard::PutData("AutonShootBackupOccupyFrisbees", new AutonShootBackupOccupyFrisbees());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutNumber("Fwd Speed", 0.25);
	SmartDashboard::PutNumber("ShooterSpeed", 1000);
	SmartDashboard::PutNumber("RobotTravelDistance", 3);

}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
