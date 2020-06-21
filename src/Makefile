CC = g++
CCFLAGS = -g

Main: Game.o Level.o Map.o Snake.o Timer.o View.o Item.o Gate.o Mission.o
	$(CC) $(CCFLAGS) -std=c++11 -o Snake Game.o Level.o Map.o Snake.o Timer.o View.o Item.o Gate.o Mission.o -lncursesw

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -std=c++11 -c $< -lncursesw

%.o : %.cpp
	$(CC) $(CCFLAGS) -std=c++11 -c $< -lncursesw

% : %.cpp
	$(CC) $(CCFLAGS) -std=c++11 -o $@ $< -lncursesw

clean :
	rm *.o Main