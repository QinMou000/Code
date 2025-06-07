selectserver:SelectServer.cc
	g++ -o $@ $^ -std=c++17 -lpthread
# client:Tcpclient.cc
# 	g++ -o $@ $^ -std=c++17 -ljsoncpp -lpthread #-static # 没有静态库不能直接static

.PHONY:clean
clean:
	rm -rf selectserver