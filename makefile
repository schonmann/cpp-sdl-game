run: game cleanup
	./game

game: abstract_game.o play_scene.o graphics.o game_object.o main.o engine.o graphics_config.o game.o
	g++ -o game abstract_game.o play_scene.o graphics.o game_object.o main.o engine.o graphics_config.o game.o -lSDL2 -lSDL2_image
debug: abstract_game.o play_scene.o graphics.o game_object.o main.o engine.o graphics_config.o game.o
	g++ -o game abstract_game.o play_scene.o graphics.o game_object.o main.o engine.o graphics_config.o game.o -DDEBUG -lSDL2 -lSDL2_image
	
# TODO: Bash script to generate all .cpp files .o correspondant object files.

cleanup:
	rm *.o
main.o:
	g++ -c src/main.cpp -Iinclude
abstract_game.o:
	g++ -c src/game/abstract_game.cpp -Iinclude
game.o:
	g++ -c src/game/game.cpp -Iinclude
play_scene.o:
	g++ -c src/game/scene/play_scene.cpp -Iinclude
graphics.o:
	g++ -c src/core/graphics.cpp -Iinclude
game_object.o:
	g++ -c src/game/model/game_object.cpp -Iinclude
engine.o:
	g++ -c src/core/engine.cpp -Iinclude
graphics_config.o:
	g++ -c src/config/graphics_config.cpp -Iinclude