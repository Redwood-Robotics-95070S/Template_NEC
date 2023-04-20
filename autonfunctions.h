#include "vex.h"

//autonomous functions for use (make sure you know how to make them on your own before using this template)

//set motors to coasting
void setcoast() {
  fl.setStopping(coast);
  fr.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
}

void sethold() {
  fl.setStopping(hold);
  fr.setStopping(hold);
  bl.setStopping(hold);
  br.setStopping(hold);
}

void setbrake() {
  fl.setStopping(brake);
  fr.setStopping(brake);
  bl.setStopping(brake);
  br.setStopping(brake);
}

//set drivetrain velocity pct value
void setv(double pctamt) {
  fl.setVelocity(pctamt,percent);
  fr.setVelocity(pctamt,pct);
  bl.setVelocity(pctamt,pct);
  br.setVelocity(pctamt,pct);
}

//set drivetrain velocity rpm value
void setrpm(double rpmamt) {
  fl.setVelocity(rpmamt,rpm);
  fr.setVelocity(rpmamt,rpm);
  bl.setVelocity(rpmamt,rpm);
  br.setVelocity(rpmamt,rpm);
}

//move forward or backward an amount of degrees, waittime and vcity (wait time and velocity) are optional parameters, and are defaulted to 20 ms and 100 pct velocity, but can be changed when called
void forbackpct (double amt, double vcity = 100, double waittime = 20) {
  setv(vcity);
  fl.spinFor(forward,amt,degrees);
  fr.spinFor(forward,amt,degrees);
  bl.spinFor(forward,amt,degrees);
  br.spinFor(forward,amt,degrees);
  wait(20,msec);
}

//same as above function but input for velocity is rpm
void forbackrpm(double amt, double vcity = 200, double waittime  = 0) {
  setrpm(vcity);
  fl.spinFor(forward,amt,degrees);
  fr.spinFor(forward,amt,degrees);
  bl.spinFor(forward,amt,degrees);
  br.spinFor(forward,amt,degrees);
  wait(waittime,msec);
}

//same as forbackpct but for turning, positive value turns right, negative value turns left
void turnpct(double amt, double vcity = 100, double waittime = 0) {
  setv(vcity);
  fl.spinFor(forward,amt,degrees);
  fr.spinFor(reverse,amt,degrees);
  bl.spinFor(forward,amt,degrees);
  br.spinFor(reverse,amt,degrees);
  wait(waittime,msec);
}

//same as above, but rpm
void turnrpm(double amt, double vcity = 100, double waittime = 0) {
  setrpm(vcity);
  fl.spinFor(forward,amt,degrees);
  fr.spinFor(reverse,amt,degrees);
  bl.spinFor(forward,amt,degrees);
  br.spinFor(reverse,amt,degrees);
  wait(waittime,msec);
}

//move forward or backward an amount of time, setting velocity is setv or setvrpm
void ForBack(double ms) {
  fl.spin(forward);
  fr.spin(forward);
  bl.spin(forward);
  br.spin(forward);
  wait(ms,msec);
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

//same as above but for turning, bool dir 1 is turning right, 0 is turning left (true is right, false is left)
void Turn(double ms, bool dir) {
  if(dir) {
    fl.spin(forward);
    fr.spin(reverse);
    bl.spin(forward);
    br.spin(reverse);
  }
  else {
    fl.spin(reverse);
    fr.spin(forward);
    bl.spin(reverse);
    br.spin(forward);
  }
  wait(ms,msec);
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}