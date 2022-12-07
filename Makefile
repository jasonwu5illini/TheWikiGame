
CXX=clang++
CXXFLAGS=-std=c++17 -g -fstandalone-debug

exec: bin/exec
test: bin/test

bin/exec: ./src/main.cpp ./src/TheWikiGame.cpp ./src/TheWikiGame.h
	$(CXX) $(CXXFLAGS) ./src/main.cpp ./src/TheWikiGame.cpp -o $@


bin/test: ./tests/test.cpp obj/catch.o ./src/TheWikiGame.cpp ./src/TheWikiGame.h 
	$(CXX) $(CXXFLAGS) ./tests/test.cpp obj/catch.o ./src/TheWikiGame.cpp -o $@

obj/catch.o: tests/catch.cc 
	$(CXX) $(CXXFLAGS) -c $^ -o $@



.DEFAULT_GOAL := exec
.PHONY: clean exec test

clean:
	rm -fr bin/* obj/*