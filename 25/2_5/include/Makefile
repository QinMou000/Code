libmyfile.a:File.o
	@ar -rc $@ $^
	@echo "bulid $^ to $@ ... done"
%.o:%.c
	@gcc -c $<
	@echo "compling $< to $@ ... done"

.PNOLY:clean
clean:
	@rm -rf *.a *.o
	@echo "clean ... done"
	