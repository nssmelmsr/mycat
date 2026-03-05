#include <stdio.h>
#include <unistd.h> //para funcion read()
#include <fcntl.h> //para función open()

int main(int argc, char *argv[]){ // argc cuenta los argumentos
				  // argv[] los guarda en array
	int fd;			// file descriptor
	char buffer[256]; 	// maximum to read
	ssize_t bytes_read;  	// 
	
	if (argv[1] == NULL){
		fprintf(stderr,"Please choose a file\n",argv[0]);
		return 0;
	}
	else{
		//filename = argv[1];
		printf("Showing file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY); //Open for read only
		if (fd == -1){
			perror("open");
			return 0;
		}
		
		while ((bytes_read = read(fd, buffer, sizeof(buffer) -1)) > 0){//lee cada caracter del archivo
			write(STDOUT_FILENO, buffer, bytes_read);
		}
		if (bytes_read == -1){
			perror("reading file");
			close(fd);
			return 0;
		}
		//printf("%s\n",buffer);
		close(fd);
		return 0;
	}
}


