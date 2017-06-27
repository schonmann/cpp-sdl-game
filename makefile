run: game cleanup
	./game
cleanup: game
	rm *.o
game: all.o
	g++ -o game *.o  -lSDL2 -lSDL2_image
debug: all.o
	g++ -o game *.o  -DDEBUG -lSDL2 -lSDL2_image
	
# TODO: Bash script to generate all .cpp files .o correspondant object files.

all.o:
	find . -type f -name '*.cpp' -exec sh -c 'g++ {} -Iinclude -c $(basename {} .cpp)' \;