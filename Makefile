all: mycat.c
	gcc -o mycat mycat.c
clean:
	rm -f mycat
