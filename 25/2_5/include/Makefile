libmyfile.a:File.o
	@ar -rc $@ $^
	@echo "bulid $^ to $@ ... done"
%.o:%.c
	@gcc -c $<
	@echo "compling $< to $@ ... done"

.PHONY:output
output:
	mkdir -p ../lib/include
	mkdir -p ../lib/mylib
	cp -f *.h ../lib/include
	cp -f *.a ../lib/mylib
	tar czf lib.tgz lib

.PNOLY:clean
clean:
	@rm -rf *.a *.o *tgz
	@echo "clean ... done"
	