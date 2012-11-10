CC = g++

all: link

link: Sources/main.cpp Headers/Board.h Headers/ComboBar.h Sources/Board.cpp Sources/ComboBar.cpp
	$(CC) -o link Sources/main.cpp Sources/ComboBar.cpp Sources/Board.cpp
