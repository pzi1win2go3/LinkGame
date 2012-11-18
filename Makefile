CC = g++

all: link

link: Sources/main.cpp Headers/Board.h Headers/ComboBar.h Sources/Board.cpp Sources/ComboBar.cpp \
	Sources/LinkGame.cpp Headers/LinkGame.h Headers/Point.h Headers/TimeBar.h Sources/TimeBar.cpp
	$(CC) -o link Sources/main.cpp Sources/ComboBar.cpp Sources/Board.cpp Sources/TimeBar.cpp Sources/LinkGame.cpp