CC = cc
CFLAGS = -std=c11 -Wall -Wextra

PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
INCDIR = $(PREFIX)/include

SRC = array_list.c
INC = array_list.h
OBJ = $(SRC:.c=.o)

TARGET = libarray_list.a libarray_list.so

all: $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -c -o $@

libarray_list.a: $(OBJ)
	ar rcs $@ $(OBJ)

libarray_list.so: $(OBJ)
	$(CC) $(CFLAGS) -fpic -shared $(OBJ) -o $@

clean:
	rm -f $(TARGET) $(OBJ)

install: all
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 libarray_list.a $(DESTDIR)$(LIBDIR)
	install -m 644 libarray_list.so $(DESTDIR)$(LIBDIR)
	install -d $(DESTDIR)$(INCDIR)
	install -m 644 $(INC) $(DESTDIR)$(INCDIR)
	ldconfig || true

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libarray_list.*
	rm -f $(DESTDIR)$(INCDIR)/$(INC)

.PHONY: all clean install uninstall
