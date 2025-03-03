.PONLY:all
all:server client

client:client.cc
	g++ -o $@ $^ -std=c++11
server:server.cc
	g++ -o $@ $^ -std=c++11


.PONLY:clean
clean:
	rm -rf client server