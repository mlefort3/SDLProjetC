main: main.cpp twoplayers.o
	g++ main.cpp -o main -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
    
twoplayers.o: twoplayers.cpp twoplayers.hpp twoplayers.h
	g++ twoplayers.cpp -o twoplayers.o -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa