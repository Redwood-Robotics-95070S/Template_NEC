#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
gps GPST = gps(PORT11, 0.00, 0.00, mm, 180);
motor fl = motor(PORT1, ratio18_1, false);
motor fr = motor(PORT7, ratio18_1, true);
motor bl = motor(PORT10, ratio18_1, false);
motor br = motor(PORT3, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}