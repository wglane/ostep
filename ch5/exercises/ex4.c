#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char **argv) {
	char *args[3];
	args[0] = strdup("/bin/ls");
	args[1] = strdup("-l");
	args[2] = NULL;

	execvp(args[0], args);

	return 0;
}
