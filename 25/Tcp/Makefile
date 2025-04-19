.PHONY:all
all:server client

server:Tcpserver.cc
	g++ -o $@ $^ -std=c++17
client:Tcpclient.cc
	g++ -o $@ $^ -std=c++17 -static

.PHONY:clean
clean:
	rm -rf server client