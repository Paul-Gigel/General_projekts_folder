LDFLAGS = rollenspiel.h rollenspiel.cpp

rollenspiel :
	g++ -o rollenspiel.exe main.cpp $(LDFLAGS)

exe :
	./rollenspiel.exe

clean :
	rm -f rollenspiel.exe

test : clean rollenspiel exe
	rm -f rollenspiel.exe

.PHONY: exe clean test