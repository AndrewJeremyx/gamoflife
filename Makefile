game : main.o Game.o 
	g++ -o game main.o  Game.o -lglut -lGLU -lGL 

main.o : main.cpp
	g++ -c main.cpp -lglut -lGLU -lGL 

Game.o : Game.cpp
	g++ -c -std=c++11 Game.cpp

clean:
	rm -rf *.o game
