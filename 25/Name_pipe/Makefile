.PONLY:all
all:client server

client:client.cc
	g++ -o $@ $^ -std=c++11
server:server.cc
	g++ -o $@ $^ -std=c++11


.PONLY:clean
clean:
	rm -rf client server fifo