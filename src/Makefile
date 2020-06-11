CC = g++
CCFLAGS = -g

Main: Game.o Level.o Map.o Snake.o Timer.o View.o
	$(CC) $(CCFLAGS) -std=c++11 -o Main Game.o Level.o Map.o Snake.o Timer.o View.o -lncursesw

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -std=c++11 -c $< -lncursesw

%.o : %.cpp
	$(CC) $(CCFLAGS) -std=c++11 -c $< -lncursesw

% : %.cpp
	$(CC) $(CCFLAGS) -std=c++11 -o $@ $< -lncursesw