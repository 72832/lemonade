#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  jumper9,        sensorTouch)
#pragma config(Sensor, dgtl10, jumper10,       sensorTouch)
#pragma config(Sensor, dgtl11, jumper11,       sensorTouch)
#pragma config(Sensor, dgtl12, jumper12,       sensorTouch)
#pragma config(Motor,  port1,           left1,         tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           left2,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           left3,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intakeB,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           intakeT,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           flipper,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           right1,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           right2,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          right3,        tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

// SmartMotorLibrary
#include "jpearman/SmartMotorLib.c"
// Joystick Controls
// #include "JoystickDriver.c"
// Other files
#include "functions.c"
#include "auton.c"
// #include "leftPID.c"

#include "Vex_Competition_Includes.c"  // Main competition background code...do not modify!
#pragma systemFile

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

// Main competition background code...do not modify!

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	// Enable smart motor library
	SmartMotorsInit();

	// Define motors plugged into power expander
	// SmartMotorsAddPowerExtender( motorA, motorB, motorC, motorD );

	// Link motors
	// Drive motors
	SmartMotorLinkMotors(left2,left1);
	SmartMotorLinkMotors(left2,left3);
	SmartMotorLinkMotors(right2,right1);
	SmartMotorLinkMotors(right2,right3);
	// Intake motors
	SmartMotorLinkMotors(intakeT,intakeB);

	// Current monitor
	SmartMotorCurrentMonitorEnable();
	// Smart motor start
	SmartMotorRun();

	nMotorEncoder[left2] = 0;
	nMotorEncoder[right2] = 0;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	if(SensorValue[jumper12]==1){
		autonB1(); // Blue flag side auton
	}

} // End of task auton

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// User control code here, inside the loop

// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.

// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................

task usercontrol()
{
	while(true){

		// Drive program
		drive();{
		}

		// Intake program
		if (vexRT[Btn6D]==1){ // Right bottom trigger
			intakeIn();
			}else if (vexRT[Btn8D]==1){ // Right bottom button
			intakeOut();
			} else{
			intakeStay();
		}

		// Puncher program
		if (vexRT[Btn6U]==1){ // Right top trigger
			puncherShoot();
			} else{
			puncherStay();
		}

		// Flipper Progam
		if (vexRT[Btn7U]==1){ // Left top button
			flipperUp();
			}else if (vexRT[Btn7D]==1){ // Left bottom button
			flipperDown();
			} else{
			flipperStay();
		}


	} // End of while true loop
} // End of task usercontrol
