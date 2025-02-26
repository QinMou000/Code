*.o:*.c
	gcc -c $@ $^
	
main:*.o
	gcc -o $@ $^

.PONLY:clean
clean:
	rm -rf code.o hello.o
