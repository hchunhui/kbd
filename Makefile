#CROSS = x86_64-w64-mingw32-
CROSS = i686-w64-mingw32-

CFLAGS = -mwindows -D_UNICODE -DUNICODE -municode

all:
	$(CROSS)windres kbd.rc kbd.res.o
	$(CROSS)gcc $(CFLAGS) -o kbd.exe main.c kbd.res.o
	$(CROSS)strip kbd.exe

clean:
	rm -rf kbd.res.o kbd.exe *~

check-syntax:
	$(CROSS)gcc $(CFLAGS) -Wall -Wextra -fsyntax-only $(CHK_SOURCES)
