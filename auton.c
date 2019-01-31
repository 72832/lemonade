#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

/*-----------------------------------------------------------------------------*/
/*
/*  Auton functions
/*
/*-----------------------------------------------------------------------------*/

// Drive
void autoDrive(int speed1, int speed2){
	SetMotor(left1,speed1);
	SetMotor(right1,speed2);
	SetMotor(left2,speed1);
	SetMotor(right2,speed2);
}
void driveStop(int time){
	SetMotor(left1,0);
	SetMotor(right1,0);
	SetMotor(left2,0);
	SetMotor(right2,0);
	wait1Msec(time);
}

// Puncher
void autoShoot(int time){
	SetMotor(puncher1,100);
	SetMotor(puncher2,100);
	SetMotor(puncher3,100);
	wait1Msec(time);
}
void puncherStop(int time){
	SetMotor(puncher1,0);
	SetMotor(puncher2,0);
	SetMotor(puncher3,0);
	wait1Msec(time);
}

// Intake
void autoTake(int time){
	SetMotor(intake1,127);
	SetMotor(intake2,127);
	wait1Msec(time);
}
void autoGive(int time){
	SetMotor(intake1,-127);
	SetMotor(intake2,-127);
	wait1Msec(time);
}
void intakeStop(int time){
	SetMotor(intake1,0);
	SetMotor(intake2,0);
	wait1Msec(time);
}

/*-----------------------------------------------------------------------------*/
/*
*/
/*  Auton modes
/*
*/
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/*  Red alliance
/*-----------------------------------------------------------------------------*/

// Blue flag side (+3)
void autonR1(){
	// Start facing flags
	// Forward slightly
	autoDrive(127,127);{
	}
	wait1Msec(150);
	driveStop(50);{
	}
	wait1Msec(50);
	// Shoot top flag
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Turn left slightly
	autoDrive(0,127);{
	}
	wait1Msec(100);
	driveStop(50);{
	}
	wait1Msec(50);
	// Drive forward to hit bottom flag
	autoDrive(127,127);{
	}
	wait1Msec(1300);
	driveStop(50);{
	}
	wait1Msec(50);
	// Intake ball
	autoTake(1000);{
	}
	intakeStop(50);{
	}
}

// Red flag side (+6)
void autonR2(){
	// Start facing cap
	// Drive forward to hit cap (+1)
	autoDrive(127,127);{
	}
	wait1Msec(950);
	driveStop(50);
	// Intake ball halfway
	autoTake(500);{
	}
	intakeStop(50);{
	}
	// Drive back to alliance tile
	autoDrive(-127,-127);{
	}
	wait1Msec(900);
	driveStop(300);
	// Turn left to face flags
	autoDrive(-80,80);{
	}
	wait1Msec(195);
	driveStop(50);
	// Forward slightly
	autoDrive(127,127);{
	}
	wait1Msec(200);
	driveStop(50);{
	}
	wait1Msec(50);
	// Shoot top flag (+2)
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Drive forward
	autoDrive(127,127);{
	}
	wait1Msec(215);
	driveStop(50);
	// Intake ball fully
	autoTake(1000);{
	}
	intakeStop(50);{
	}
	// Bring intake down
	autoGive(200);{
	}
	intakeStop(50);{
	}
	// Intake ball fully
	autoTake(500);{
	}
	intakeStop(50);{
	}
	// Shoot middle flag (+2)
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Turn left slightly
	autoDrive(0,127);{
	}
	wait1Msec(120);
	driveStop(50);{
	}
	// Drive forward to hit bottom flag (+1)
	autoDrive(127,127);{
	}
	wait1Msec(800);
	driveStop(50);
}

// Red cap side (+4)
void autonR3(){
	// Start facing cap
	// Drive forward to hit cap (+1)
	autoDrive(127,127);{
	}
	wait1Msec(1150);
	driveStop(50);
	// Intake ball halfway
	autoTake(400);{
	}
	intakeStop(50);{
	}
	// Drive back
	autoDrive(-127,-127);{
	}
	wait1Msec(155);
	driveStop(50);
	// Turn left to face platform
	autoDrive(-127,127);{
	}
	wait1Msec(260);
	driveStop(50);
	// Drive onto platform (+3)
	autoDrive(127,127);{
	}
	wait1Msec(970);
	driveStop(50);
}

/*-----------------------------------------------------------------------------*/
/*  Blue alliance
/*-----------------------------------------------------------------------------*/

// Blue flag side (+3)
void autonB1(){
	// Start facing flags
	// Forward slightly
	autoDrive(127,127);{
	}
	wait1Msec(170);
	driveStop(50);{
	}
	wait1Msec(50);
	// Shoot top flag
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Turn right slightly
	autoDrive(127,0);{
	}
	wait1Msec(100);
	driveStop(50);{
	}
	wait1Msec(50);
	// Drive forward to hit bottom flag
	autoDrive(127,127);{
	}
	wait1Msec(1300);
	driveStop(50);{
	}
	wait1Msec(50);
	// Intake ball
	autoTake(1000);{
	}
	intakeStop(50);{
	}
}

// Blue flag side (+6)
void autonB2(){
	// Start facing cap
	// Drive forward to hit cap (+1)
	autoDrive(127,127);{
	}
	wait1Msec(950);
	driveStop(50);
	// Intake ball halfway
	autoTake(500);{
	}
	intakeStop(50);{
	}
	// Drive back to alliance tile
	autoDrive(-127,-127);{
	}
	wait1Msec(895);
	driveStop(300);
	// Turn right to face flags
	autoDrive(80,-80);{
	}
	wait1Msec(185);
	driveStop(50);
	// Forward slightly
	autoDrive(127,127);{
	}
	wait1Msec(200);
	driveStop(50);{
	}
	wait1Msec(50);
	// Shoot top flag (+2)
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Drive forward
	autoDrive(127,127);{
	}
	wait1Msec(215);
	driveStop(50);
	// Intake ball fully
	autoTake(1500);{
	}
	intakeStop(50);{
	}
	// Bring intake down
	autoGive(200);{
	}
	intakeStop(50);{
	}
	// Intake ball fully
	autoTake(500);{
	}
	intakeStop(50);{
	}
	// Shoot middle flag (+2)
	autoShoot(1800);{
	}
	puncherStop(50);{
	}
	// Turn right slightly
	autoDrive(127,0);{
	}
	wait1Msec(120);
	driveStop(50);{
	}
	// Drive forward to hit bottom flag (+1)
	autoDrive(127,127);{
	}
	wait1Msec(800);
	driveStop(50);
}

// Blue cap side (+4)
void autonB3(){
	// Start facing cap
	// Drive forward to hit cap (+1)
	autoDrive(127,127);{
	}
	wait1Msec(1100);
	driveStop(50);
	// Intake ball halfway
	autoTake(400);{
	}
	intakeStop(50);{
	}
	// Drive back
	autoDrive(-127,-127);{
	}
	wait1Msec(250);
	driveStop(50);
	// Turn right to face platform
	autoDrive(127,-127);{
	}
	wait1Msec(260);
	driveStop(50);
	// Drive onto platform (+3)
	autoDrive(127,127);{
	}
	wait1Msec(1100);
	driveStop(50);
}
