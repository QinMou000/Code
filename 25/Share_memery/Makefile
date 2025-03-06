.PHONY:all
all:server client

client:client.cc
	g++ -o $@ $^ -std=c++11
server:server.cc
	g++ -o $@ $^ -std=c++11


.PHONY:clean
clean:
	rm -rf client server fifo