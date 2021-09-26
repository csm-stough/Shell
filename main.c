
/*
 * This basic shell operates on a Read/Parse/Execute loop:
 * -Read: read the command from STDIN
 * -Parse: seperates the command into a program and arguments
 * -Execute: run the command
 */
void rpe_loop() {
	char* line;
	char** args;
	int status;

	do {
		printf("> ");
		line=rpe_read_line();
		args=rpe_split_line(line);
		status=rpe_execute(args);

		free(line);
		free(args);
	} while(status);
}

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
