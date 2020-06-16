prog1:main.o quit.o instruction.o options.o
	gcc quit.o main.o instruction.o options.o -o prog1 -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
quit.o:quit.c
	gcc -c quit.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
options.o:options.c
	gcc -c options.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
instruction.o:instruction.c
	gcc -c instruction.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
