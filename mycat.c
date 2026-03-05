#include <stdio.h>
#include <unistd.h> //para funcion read()
#include <fcntl.h> //para función open()

int main(int argc, char *argv[]){ // argc cuenta los argumentos
				  // argv[] los guarda en array
	int fd;			// file descriptor
	char buffer[256]; 	// maximum to read
	ssize_t bytes_read;  	// 
	
	if (argv[1] == NULL){
		fprintf(stderr,"Please choose a file\n",argv[0]); //show custom error 
		return 1;
	}
	else{
		
		printf("Showing file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY); //Open for read only
		if (fd == -1){
			perror("Error openning file");    // perror shows the error code of the syscall
			return 1;
		}
		
		while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){//lee cada caracter del archivo
			ssize_t written = write(STDOUT_FILENO, buffer, bytes_read);
			if (written == -1){
			perror("Error writing");
			return 1;
			}
		}
		if (bytes_read == -1){
			perror("Error reading file");
			close(fd);
			return 1;
		}
		close(fd);
		return 0;
	}
}


