run: game cleanaft
	./game
game: all.o
	g++ -o game *.o  -lSDL2 -lSDL2_image
debug: all.o
	g++ -o game *.o  -DDEBUG -lSDL2 -lSDL2_image

# Compile all .cpp object files for future linking.

all.o: cleanb4
	find . -type f -name '*.cpp' -exec sh -c 'g++ {} -Iinclude -c $(basename {} .cpp)' \;

cleanb4:
	-rm *.o
cleanaft:
	-rm *.o

