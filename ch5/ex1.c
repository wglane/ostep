#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int x = 100;
	int rc;
	if ((rc = fork()) < 0) {
		exit(1);
	}
	// child
	else if (rc == 0) {
		int x = 200;
		printf("Child process. Value of x is: %d\n", x);
	}
	// parent
	else {
		printf("Parent process. Value of x is: %d\n", x);
	}
	return 0;
}
