#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	printf("hello world (pid: %d)\n", getpid());
	int rc;
	if ((rc = fork()) < 0) {
		printf("fork failed!\n");
	}
	// child
	else if (rc == 0) {
		printf("I am the child process (pid: %d)\n", getpid());
		printf("Now I shall recite a poem:\n");
		char *args[3];
		args[0] = strdup("cat");
		args[1] = strdup("roses");
		args[2] = NULL;
		execvp(args[0], args);
		printf("This should not print.\n");
	}
	// parent
	else {
		int rc_wait = wait(NULL);
		printf("hello I am the parent of %d (rc_wait: %d) (pid: %d)\n",
			rc, rc_wait, (int) getpid());
	}
	return 0;
}
