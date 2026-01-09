CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -O2

BUILD_DIR = build

SRC = array_list.c
INC = array_list.h
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

TARGET = libarray_list.a

all: $(TARGET)

debug: CFLAGS += -g
debug: all

$(BUILD_DIR)/%.o: $(SRC)
	@mkdir $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(SRC) -c -o $@

$(TARGET): $(OBJ)
	@ar rcs $(BUILD_DIR)/$@ $(OBJ)
	@echo "-> $@"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: debug all clean