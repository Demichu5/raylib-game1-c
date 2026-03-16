all: main

CC = tcc

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	clear ; $(CC) -bench -Wall $(SRCS) -o "$@" ; ls -lh

raylibold: $(SRCS) $(HEADERS)
	clear ; $(CC) -bench -Wall $(SRCS) -lraylib -lrt -lX11 -o "main" ; ls -lh

raylib: $(SRCS) $(HEADERS)
	clear ; $(CC) -bench -Wall $(SRCS) -lraylib -lrt -o "main" ; ls -lh

run:
	clear ; ./main

clean:
	clear ; rm -f main main-debug ; ls -lh