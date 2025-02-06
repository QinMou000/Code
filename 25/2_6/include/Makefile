libmyfile.so:File.o
	gcc -o $@ $^ -shared

%.o:%.c
	gcc -fPIC -c $<

.PHONY:output
output:
	mkdir -p ../lib/include
	mkdir -p ../lib/mylib
	cp -f *.h ../lib/include
	cp -f *.so ../lib/mylib
	tar czf lib.tgz lib

.PHONY:clean
clean:
	rm -rf *.o *.so lib.tgz