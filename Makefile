LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: test

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

Game.o: Game.cpp
	g++ -c "Game.cpp" -o Game.o

Cell.o: Cell.cpp
	g++ -c "Cell.cpp" -o Cell.o

test: main.o Game.o Cell.o
	@echo "BUILDING..."
	g++ -o test main.o Game.o Cell.o $(LIB)

clean:
	@echo "Wiping out object files..."
	rm test *.o