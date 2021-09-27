#include "Shell.h"

void rpe_loop() {
	char* line;
	char** args;
	int status;

	do {
		printf("> ");
		line = rpe_read_line();
		args = rpe_split_line(line);
		status = rpe_execute(args);

		free(line);
		free(args);
	} while(status);
}

char* rpe_read_line() {
	int bufsize = RPE_RL_BUFSIZE;
	int position = 0;
	char* buffer = (char*)malloc(sizeof(char)*bufsize);
	int c;

	if(!buffer) {
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	//Loop until the user hits enter or the command string hits EOF
	while(1) {
		//here we are parsing the entered character as an int b/c EOF is an int
		c = getchar();
		if(c == EOF || c == '\n') {
			//null terminating our command string and returning it
			buffer[position] = '\0';
			return buffer;
		}
		else {
			//set the char within the buffer
			buffer[position] = c;
		}
		position++;

		//if we enter more than the default buffer size, reallocate more memory
		if(position >= bufsize) {
			bufsize += RPE_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if(!buffer) {
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char** rpe_split_line(char* line) {
	int bufsize = RPE_TOK_BUFSIZE;
	int position = 0;
	char** tokens = (char**)malloc(sizeof(char*) * bufsize);
	char* token;

	if(!tokens) {
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	//Begin by getting the first token in our line
	token = strtok(line, RPE_TOK_DELIM);

	//while there are still tokens to get...
	while(token != NULL) {
		//set the token in the tokens array
		tokens[position] = token;
		position++;

		//reallocating the token buffer size if neccessary
		if(position >= bufsize) {
			bufsize += RPE_TOK_BUFSIZE;
			tokens = realloc(tokens, sizeof(char*) * bufsize);
			if(!tokens) {
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		//by passing NULL to strtok, were telling it to keep tokenizing the last string given
		token = strtok(NULL, RPE_TOK_DELIM);
	}
	//at this point we null terminate our tokens, much line we null terminated our line
	tokens[position] = NULL;
	return tokens;
}

int rpe_launch(char** args) {
	pid_t pid, wpid;
	int status;

	pid = fork();
	if(pid == 0) {
		if(execvp(args[0], args) == -1) {
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0) {
		perror("shell");
	}
	else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

int rpe_execute(char** args) {

}
