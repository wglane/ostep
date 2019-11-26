#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("hello, world. this is pid: %i\n", getpid());
	printf("---\n");
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork() failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am a child process. pid: %i\n\n", getpid());
	} else {
		int rc_wait = wait(NULL);
		printf("I am the parent process of %d, and my pid is %d\n",
			rc_wait, getpid());
		printf("The child process has pid: %i\n\n", rc);
		
	}
	return 0;
}
