#include "DriveForward.h"
#include <math.h>

DriveForward::DriveForward(double d, double s) {
	defaultDistance = d;
	distance = 0.0;
	defaultSpeed = fabs(s)*(distance < 0.0 ? -1 : 1);
	speed = 0.0;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void DriveForward::Initialize() {
	distance = defaultDistance == 0 ? SmartDashboard::GetNumber("RobotTravelDistance") : defaultDistance;
	speed = defaultSpeed == 0.0 ? fabs(SmartDashboard::GetNumber("Fwd Speed"))*(distance < 0.0 ? -1 : 1) : defaultSpeed;	
	keepGoingUntilTime = distance/(Robot::MAX_MAX_SPEED*speed);
	
	double timeout = distance/(Robot::MIN_MAX_SPEED*speed);	//time = distance /speed	
	if (timeout > 15.0) timeout = 15.0;						//autonomous is only 15 seconds
	SetTimeout(timeout);
}
void DriveForward::Execute() {
		Robot::drivetrain->drive->Drive(speed, -0.5*Robot::AngleFacing());	//FIXME replace with PID
}
bool DriveForward::IsFinished() {
	return (Timer::GetPPCTimestamp()>= keepGoingUntilTime && 
			Robot::DistanceTraveled() >= distance) || IsTimedOut();
}
void DriveForward::End() {
	Robot::drivetrain->drive->Drive(0.0, 0.0);
}
void DriveForward::Interrupted() {
	End();
}
