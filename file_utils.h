#ifndef FILE_UTIL
#define FILE_UTIL
/****************************************
read_file reads the contents of the file
specified by filename and saves it to
memory. It returns 0 on success and 1
on failure.
*****************************************/
int read_file(char* filename, char **buffer);

/*****************************************
write_file writes the contents of the char
array that begins with the address buffer
to a file specified by filename. The argument
size is the total number of characters in the
array. 
*****************************************/
int write_file(char* filename, char *buffer, int size);

#endif
