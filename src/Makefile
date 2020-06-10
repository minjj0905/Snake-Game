CC = g++
CCFLAGS = -g

Main: Game.o Level.o Map.o Snake.o Timer.o View.o
	$(CC) $(CCFLAGS) -o Main Game.o Level.o Map.o Snake.o Timer.o View.o -lncursesw

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $< -lncursesw

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -lncursesw

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $< -lncursesw