all:
	g++ -I src/include -L src/lib -o mpgameboy main.c -lmingw32 -lSDL2main -lSDL2