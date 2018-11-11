#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

// PID using optical shaft encoder
//
// Shaft encoder has 360 pulses per revolution
//

#define LEFT_SENSOR_INDEX    leftEncoder
#define RIGHT_SENSOR_INDEX   rightEncoder
#define PID_SENSOR_SCALE     1

#define PID_MOTOR_SCALE     -1

#define PID_DRIVE_MAX       80
#define PID_DRIVE_MIN     (-80)

#define PID_INTEGRAL_LIMIT  50

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"
float  pid_Kp = 2.0;
float  pid_Ki = 0.04;
float  pid_Kd = 0.0;

static int   pidRunning = 1;
static float pidRequestedValue;

// Delay void
void waitFunc(int time){
	wait1Msec(time);
}

// Drive encoders
int leftEncode(){
	return(SensorValue[leftEncoder]);
}
int rightEncode(){
	return(SensorValue[rightEncoder]);
}

// User control drive function
void driveFunc(int speed1, int speed2){
	SetMotor(left1,speed1);
	SetMotor(right1,speed2);
	SetMotor(left2,speed1);
	SetMotor(right2,speed2);
	SetMotor(left3,speed1);
	SetMotor(right3,speed2);
}

// Drive PID
void drivePID(int power1, int power2){
	leftDrivePID(power1);
	rightDrivePID(power2);
}

// Auton Middle Level
// Drive functions
// Drive Function Middle Level
void driveStraight(int power){
	drivePID(power,power);
}

void driveStop(){
	drivePID(0,0);
}

// User control drive functions
void drive(){
	driveFunc(vexRT[Ch3], vexRT[Ch2]);
}
void driveStop(){
	driveFunc(0,0);
}

// User control intake functions
void intakeUp(){
	SetMotor(intake,100);
}
void intakeDown(){
	SetMotor(intake,-100);
}
void intakeStay(){
	SetMotor(intake,0);
}

// User control puncher functions
void puncherShoot(){
	SetMotor(puncher,80);
}
void puncherStay(){
	SetMotor(puncher,0);
}