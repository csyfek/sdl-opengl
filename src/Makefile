C_SOURCES=$(wildcard *.c)
C_OBJECTS=$(C_SOURCES:.c=.o)
AS_SOURCES=$(wildcard *.s)
AS_OBJECTS=$(AS_SOURCES:.s=.o)
OBJECTS=$(C_OBJECTS) $(AS_OBJECTS)
WARNINGS := -Wall -Wextra
CFLAGS := -O2 $(WARNINGS) -I/usr/include/SDL -lSDL -I/usr/include/GL -lGL

.PHONY: all clean

all: sdl-opengl ex1 ex2 ex3

sdl-opengl: sdl-opengl.c
	gcc -o $@ $< $(CFLAGS)

ex1: ex3.c
	g++ -o ex1 ex1.c -I/usr/local/include/GL -lGL -lglut

ex2: ex2.c
	g++ -o ex2 ex2.c -I/usr/local/include/GL -lGL -lglut

ex3: ex3.c
	g++ -o ex3 ex3.c -I/usr/local/include/GL -lGL -lglut

