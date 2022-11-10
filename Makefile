
CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++0x -g -fstandalone-debug

exec: bin/exec


bin/exec: ./src/main.cpp ./src/TheWikiGame.cpp ./includes/TheWikiGame.h 
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/driver.cc ./src/branched-linked-list.cc -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec 

clean:
	rm -fr bin/* obj/*