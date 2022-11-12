
CXX=clang++
CXXFLAGS=-std=c++0x -g -fstandalone-debug

exec: bin/exec


bin/exec: ./src/main.cpp ./src/TheWikiGame.cpp ./src/TheWikiGame.h 
	$(CXX) $(CXXFLAGS) ./src/main.cpp ./src/TheWikiGame.cpp -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec 

clean:
	rm -fr bin/* obj/*