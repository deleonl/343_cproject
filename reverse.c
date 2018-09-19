#include "file_utils.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

/***********************************
reverse reads the data in the file
specified by the first argument and
puts it reversed into the file
specified by the second argument.
***********************************/
int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "invalid number of arguments");
		return 1;
	}

	// code from assignment specs
	struct stat st;
	stat(argv[1], &st);
	int size = st.st_size;
	
	char* buffer = malloc(size);
	if (buffer == NULL) {
		fprintf(stderr, "memory allocation error");
		return 1;
	}

	read_file(argv[1], &buffer);

	char* rev_buffer = malloc(size);
	if (rev_buffer == NULL) {
		fprintf(stderr, "memory allocation error");
		return 1;
	}
	
	// reverses the 'string'
	int i = size - 2;
	while (i >= 0) {
		rev_buffer[size - 2 - i] = buffer[i];
		i--;
	}
	rev_buffer[size - 1] = buffer[size  - 1];
	write_file(argv[2], rev_buffer, size);

	free(buffer);
	free(rev_buffer);
	return 0;
}
