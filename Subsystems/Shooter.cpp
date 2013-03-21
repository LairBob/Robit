#include "../Robot.h"
#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/BackgroundShoot.h"
Shooter::Shooter() : Subsystem("Shooter") {
	shooterSpeed = 0.0;
	targetShooterSpeed = 0.0;
	inDelayMode = false;
	inSpeedMode = false;
	timeToSwitchToSpeedMode = 0.0;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	mainMotor = RobotMap::shooterMainMotor;
	feedMotor = RobotMap::shooterFeedMotor;
	flipper = RobotMap::shooterFlipper;
	frisbeeDirection = RobotMap::shooterFrisbeeDirection;
	deploy = RobotMap::shooterDeploy;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Shooter::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new BackgroundShoot());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Shooter::DeployShooter() {
	deploy->Set(DoubleSolenoid::kReverse);
}
void Shooter::RetractShooter() {
	deploy->Set(DoubleSolenoid::kForward);
}
void Shooter::ToggleDeploy() {
	DoubleSolenoid::Value setting = (deploy->Get() == DoubleSolenoid::kForward) ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward;
	deploy->Set(setting);
}
void Shooter::StartShooting() {
	inDelayMode = false;
	inSpeedMode = false;
	if (shooterSpeed > 1000) {
		timeToSwitchToSpeedMode = Timer::GetPPCTimestamp();
		switchToSpeedMode();
	}
	else {
		timeToSwitchToSpeedMode = Timer::GetPPCTimestamp() + 1.25;
		// Temporarily set the motor to Voltage mode with a ramp to avoid
		// current faulting the shooting motor. Once the motor starts moving
		// it can be switched into speed mode.
		mainMotor->ChangeControlMode(CANJaguar::kVoltage);
		mainMotor->SetVoltageRampRate(5.0);
		mainMotor->EnableControl();
	}
}
void Shooter::switchToSpeedMode()
{
    mainMotor->ChangeControlMode(CANJaguar::kSpeed);
    mainMotor->SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
    mainMotor->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
    mainMotor->ConfigEncoderCodesPerRev(360);
    mainMotor->SetPID(0.6, 0.03, 0.05);
    mainMotor->EnableControl();
    inDelayMode = true;
    timeToSwitchToSpeedMode = Timer::GetPPCTimestamp() + 4.0;
    targetShooterSpeed = SmartDashboard::GetNumber("ShooterSpeed");
    mainMotor->Set(targetShooterSpeed);
}
void Shooter::ContinueShooting() {
	if (inDelayMode) {
		targetShooterSpeed = SmartDashboard::GetNumber("ShooterSpeed");
		mainMotor->Set(targetShooterSpeed);
		if (Timer::GetPPCTimestamp() >= timeToSwitchToSpeedMode) {
			inDelayMode = false;
			inSpeedMode = true;
		}
		else if (!inSpeedMode) {
			if (shooterSpeed >= targetShooterSpeed * 0.95) {
				inSpeedMode = true;
				timeToSwitchToSpeedMode = Timer::GetPPCTimestamp() + 1.0;
			}
		}
	}
	else if (inSpeedMode) {
		targetShooterSpeed = SmartDashboard::GetNumber("ShooterSpeed");
		mainMotor->Set(targetShooterSpeed);
		if (shooterSpeed >= targetShooterSpeed * 0.95) {
			// Once the main shooter gets up to 95% of target speed, start
			// feeding the frisbees.
			double feederSpeed = SmartDashboard::GetNumber("FeederSpeed");
			feedMotor->Set(-feederSpeed);
			flipper->Set(Relay::kReverse);
		}
	}
	else if (Timer::GetPPCTimestamp() >= timeToSwitchToSpeedMode) {
		switchToSpeedMode();
	}
	else {
		mainMotor->Set(8.0);
	}
}
void Shooter::StopShooting() {
	mainMotor->Set(0);
	feedMotor->Set(0);
	flipper->Set(Relay::kOff);
}
void Shooter::Snapshot() {
	if (Robot::diag) {
		MotorSnapshot(mainMotor);
		MotorSnapshot(feedMotor);
		if (inSpeedMode) {
			Robot::diag->BufferPrintf("s,%.0f\n", shooterSpeed);
		}
	}
}
void Shooter::MotorSnapshot(CANJaguar* motor) {
	if (Robot::diag) {
		int motorNumber = motor->m_deviceNumber;
		int status = motor->m_lastReceiveStatus;
		float busVoltage = motor->GetBusVoltage();
		float outputCurrent = motor->GetOutputCurrent();
		Robot::diag->BufferPrintf("m,%d,%d,%.2f,%.2f\n", motorNumber, status, busVoltage, outputCurrent);
	}
}
