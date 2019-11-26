#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	printf("Attempting to write file.\n");
	int fd;
	if ((fd = open("./ex2_output", O_RDWR | O_APPEND | O_CREAT, S_IRWXU)) < 0) {
		printf("Could not open file.\n");
		exit(1);
	}
	int rc;
	if ((rc = fork()) < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	// child
	else if (rc == 0) {
		dprintf(fd, "child (%d) is writing to file\n", getpid());
	}

	// parent
	else {
		dprintf(fd, "parent (%d) is writing to file\n", getpid());
	}
	close(fd);
	
	return 0;
}
