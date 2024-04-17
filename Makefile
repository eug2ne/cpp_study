all: compile link

compile:
	clang++ -c <file_name.cpp> -I"/opt/homebrew/Cellar/sfml/2.6.1/include"

link:
	clang++ <file_name.o> -o <file_name> -L"/opt/homebrew/Cellar/sfml/2.6.1/lib" -lsfml-graphics -lsfml-window -lsfml-system