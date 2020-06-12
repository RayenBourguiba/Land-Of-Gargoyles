prog:main.o ennemi.o jeu.o background.o hero.o text.o
	gcc main.o ennemi.o jeu.o background.o hero.o text.o -o prog -lSDL -lSDL_ttf -lSDL_image -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -lSDL_image -g
hero.o:hero.c
	gcc -c hero.c -lSDL_image -g
background.o:background.c
	gcc -c background.c -g
text.o:text.c
	gcc -c text.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
