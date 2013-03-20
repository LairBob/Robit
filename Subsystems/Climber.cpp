#include "Climber.h"
#include "../Robotmap.h"
Climber::Climber() : Subsystem("Climber") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	safetyMotor = RobotMap::climberSafetyMotor;
	engageClaw = RobotMap::climberEngageClaw;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	engageCount = 0;
}
void Climber::InitDefaultCommand() {
}
