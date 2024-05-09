all: compile link run

compile:
	clang++ -c sfml.cpp -I"/opt/homebrew/Cellar/sfml/2.6.1/include"

link:
	clang++ sfml.o -o sfml -L"/opt/homebrew/Cellar/sfml/2.6.1/lib" -lsfml-graphics -lsfml-window -lsfml-system

run:
	./sfml