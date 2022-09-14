/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    14, 12, 16, 20  
// intakemotor          motor         11              
// shooter              motor         3               
// Controller2          controller                    
// turretmotor          motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
//vex::controller con(vex::controllerType::primary);
/*
vex::motor      intakemotor1(vex::PORT5,vex::gearSetting::ratio18_1,false);
vex::motor      towermotor1(vex::PORT11,vex::gearSetting::ratio18_1,false);
*/
//digital_out dig1 = digital_out( Brain.ThreeWirePort.H );
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

void autonomous(void) {
digital_out dig1 = digital_out( Brain.ThreeWirePort.H );
/*liftmotor1.spinFor(reverse,260,degrees);
Drivetrain.turnFor(left,18,degrees);
Drivetrain.driveFor(reverse, 36, inches);
dig1.set(false);
  

dig1.set(true);

for(int i=0;i<10;i++){
liftmotor1.spin(vex::directionType::rev,127,vex::velocityUnits::pct);
}

//not waiting before it goes back
wait(1, seconds);
//should be 34 in 
Drivetrain.driveFor(forward, 9, inches);
Drivetrain.turnFor(left,95,degrees);
Drivetrain.driveFor(reverse, 22, inches);
Drivetrain.turnFor(right,7,degrees);
Drivetrain.driveFor(reverse, 8, inches);
Drivetrain.turnFor(left,3,degrees);
dig1.set(false);
Drivetrain.driveFor(forward, 6, inches);
/*for (int i=0;i<10;i++){
ringmotor1.spin(vex::directionType::rev,127,vex::velocityUnits::pct);
}
Drivetrain.turnFor(left,90,degrees); 
Drivetrain.turn(right);
Drivetrain.driveFor(forward,35,inches);
dig1.set(true);
for (int i=0;i<10;i++){
liftmotor1.spin(vex::directionType::rev,127,vex::velocityUnits::pct);
}
Drivetrain.driveFor(reverse,35,inches);*/
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  /* pneumatics*/
  Controller1.ButtonUp.pressed([]{
    static digital_out dig1 = digital_out( Brain.ThreeWirePort.H );
    static bool isPressed = true;
  
    isPressed = !isPressed;
    dig1.set(isPressed);
  
  });

  // User control code here, inside the loop
  /*
  Controller Configuration:
  Left joystick: Drivetrain
  R1+L1: Lift motor 1
  R2+L2: Lift motor 2
  Left+Right: Grab motor (tower)
  UP: Solenoid
  A+Y: Ring grab motor
  */
  /*
  L1+R1= intake motor
  
  */
/* driving, intake, and pneumatics */
  while (1) {
    /*shooter.spin(vex::directionType::fwd,Controller2.Axis4.value(),velocityUnits::pct);*/
    /* intake up */
    
    /*if (Controller1.ButtonR1.pressing()) {
      intakemotor.spin(vex::directionType::rev,127,vex::velocityUnits::pct);
    }*/
    
    /* intake down */
    
    /*else if (Controller1.ButtonL1.pressing()) {
      intakemotor.spin(vex::directionType::fwd,127,vex::velocityUnits::pct);
      
    }*/
    shooter.setVelocity(127,vex::velocityUnits::pct);
    
    /*else{
        liftmotor1.stop(vex::brakeType::hold);
    }*/
    /*if (Controller2.ButtonUp.pressing()){
      shooter.spin(vex::directionType::rev,127,vex::velocityUnits::pct);
    }
    else{
        shooter.stop(vex::brakeType::hold);
    }*/
    
  /*Controller1.ButtonUp.pressed([]{
    static digital_out dig1 = digital_out( Brain.ThreeWirePort.H );
    static bool isPressed = true;
  
    isPressed = !isPressed;
    dig1.set(isPressed);
  
  });*/
  this_thread::sleep_for(10);      
        
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
  
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
