#include <stdio.h>
#include <stdlib.h>

int read_file(char* filename, char **buffer) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "file read error\n");
		return 1;
	}
	
	// code inspired by
	// https://stackoverflow.com/questions/46933482/reading-integers-in-from-a-file-line-by-line-separated-by-whitespace

	int i = 0;
	char current = fgetc(file);

	// puts the contents of the file into the array
	while (current != EOF) {
		(*buffer)[i] = current;
		current = fgetc(file);
		i++;
	}

	fclose(file);
	return 0;
}

int write_file(char* filename, char *buffer, int size) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "file write error\n");
	}
	int i = 0;

	// puts the contents of the array into the file
	while (i < size) {
		fputc(buffer[i], file);
		i++;
	}
	fclose(file);
	return 0;
}
