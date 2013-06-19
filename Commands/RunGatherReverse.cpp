#include "RunGatherReverse.h"
RunGatherReverse::RunGatherReverse() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::gatherer);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void RunGatherReverse::Initialize() {
}
void RunGatherReverse::Execute() {
	double speed = -SmartDashboard::GetNumber("GatherSpeed");
	if (Robot::gatherer->motor) {
		Robot::gatherer->motor->Set(speed);
	}
}
bool RunGatherReverse::IsFinished() {
	return false;
}
void RunGatherReverse::End() {
	if (Robot::gatherer->motor) {
		Robot::gatherer->motor->Set(0.0);
	}
}
void RunGatherReverse::Interrupted() {
	End();
}
