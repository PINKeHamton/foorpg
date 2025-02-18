CC := clang
CFLAGS = -g3 -lldb

LIBS = -lSDL3 -lGL

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<
