.PHONY:all
all:server client

server:server.cc
	g++ -o $@ $^ -std=c++17
client:client.cc
	g++ -o $@ $^ -std=c++17

.PHONY:clean
clean:
	rm -rf server client