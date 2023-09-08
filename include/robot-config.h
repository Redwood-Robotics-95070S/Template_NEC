using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern gps GPST;
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );