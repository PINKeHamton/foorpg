CC := clang
CFLAGS = -g3

LIBS = -lSDL3 -lGL -ldl

all:
	${CC} src/main.c glad/src/gl.c -Iglad/include ${LIBS} ${CFLAGS}
