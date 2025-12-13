CC = cc
CFLAGS = -std=c11 -Wall -Wextra

PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
INCDIR = $(PREFIX)/include

SRC = array_list.c
INC = array_list.h
OBJ = $(SRC:.c=.o)

TARGET = libarray_list.a

all: $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -c -o $@

$(TARGET): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	rm -f $(TARGET) $(OBJ)

install: all
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 libarray_list.a $(DESTDIR)$(LIBDIR)
	install -d $(DESTDIR)$(INCDIR)
	install -m 644 $(INC) $(DESTDIR)$(INCDIR)
	ldconfig || true

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/$(TARGET)
	rm -f $(DESTDIR)$(INCDIR)/$(INC)

.PHONY: all clean install uninstall
