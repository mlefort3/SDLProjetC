main: main.cpp 2j.o
	g++ main.cpp -o main -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
    
twoplayers.o: twoplayers.cpp
	g++ twoplayers.cpp -o twoplayers.o -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa