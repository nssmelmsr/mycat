all: mycat.c
	gcc -o mycat mycat.c -g

clean:
	rm -f mycat
