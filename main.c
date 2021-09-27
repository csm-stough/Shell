#include "Shell.h"

/*
 * The overall operation of the shell can be described in 3 main phases:
 * -Initialize: Load and read config files, this can change the shells behavior
 * -Interpret: Reads commands entered through STDIN and executes them
 * -Terminate: Executes any shutdown commands, frees memory, and terminates.
 */
int main(int argc, char** argv) {
	//load config files
	
	//Run command loop
	rpe_loop();
	
	//perform shutdown/cleanup
	
	return EXIT_SUCCESS;
}
