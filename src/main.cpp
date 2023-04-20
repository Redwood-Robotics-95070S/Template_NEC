// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// GPS11                gps           11              
// fl                   motor         1               
// fr                   motor         7               
// bl                   motor         10              
// br                   motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// GPS11                gps           11              
// fl                   motor         1               
// fr                   motor         7               
// bl                   motor         10              
// br                   motor         3               
// EncoderA             encoder       A, B            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// GPS11                gps           11              
// fl                   motor         1               
// fr                   motor         7               
// bl                   motor         10              
// br                   motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// GPS11                gps           11              
// fl                   motor         1               
// fr                   motor         7               
// bl                   motor         10              
// br                   motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autonfunctions.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

//tank drive and arcade drive 1 and 2 joystick
void drivecode(int mode, double  x) {
  if(mode == 1) {
    fl.spin(forward, (Controller1.Axis3.value() + Controller1.Axis4.value())*x*0.01, percent);
    fr.spin(forward, (Controller1.Axis3.value() - Controller1.Axis4.value())*x*0.01, percent);
    bl.spin(forward, (Controller1.Axis3.value() - Controller1.Axis4.value())*x*0.01, percent);
    br.spin(forward, (Controller1.Axis3.value() + Controller1.Axis4.value())*x*0.01, percent);
  }
  else if (mode == 2) {
    fl.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value())*x*0.01, percent);
    fr.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value())*x*0.01, percent);
    bl.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value())*x*0.01, percent);
    br.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value())*x*0.01, percent);
  }
  else if (mode == 3) {
    fl.spin(forward, (Controller1.Axis3.value())*x*0.01, percent);
    fr.spin(forward, (Controller1.Axis2.value())*x*0.01, percent);
    bl.spin(forward, (Controller1.Axis3.value())*x*0.01, percent);
    br.spin(forward, (Controller1.Axis2.value())*x*0.01, percent);
  }
}

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
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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

int mode = 1;
int sensitivity = 1;
int a = 1;

//select the driving mode and sensitivity
void slctdrivetype() {
  while (a == 1) {
    if(mode < 1) {mode = 3;}
    else if(mode > 3) {mode = 1;}
    if(Controller1.ButtonRight.pressing()){mode++; wait(10,msec);}
    else if(Controller1.ButtonRight.pressing()){mode--; wait(10,msec);}
    if(Controller1.ButtonA.pressing()){a=0;}
    if(mode == 1) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("arcade 1 joystick");
    }
    else if(mode == 2) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("arcade 2 joystick");
    }
    else if(mode == 3) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("tank");
    }
  }
  while (a == 0) {
    if(Controller1.ButtonUp.pressing()) {sensitivity++; wait(10,msec);}
    else if(Controller1.ButtonDown.pressing()) {sensitivity--; wait(10,msec);}
    if(Controller1.ButtonLeft.pressing()) {sensitivity -= 10;}
    else if(Controller1.ButtonRight.pressing()) {sensitivity += 10;}
    if(sensitivity > 200) {sensitivity = 1;}
    else if(sensitivity < 1) {sensitivity = 100;}
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(sensitivity);
    if(Controller1.ButtonA.pressing()) {a = 3;};
  }
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    drivecode(mode,sensitivity);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
 /* Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }*/
}
