#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	// child
	else if (rc == 0) {
		printf("hello from %d\n", getpid());
	}
	// parent
	else {
		waitpid(rc, NULL, 0); 
		printf("goodbye from %d\n", getpid());
	}
	return 0;
}
