CC := gcc
CFLAGS := -Wall -Wextra

SRC := src
INCLUDE := include
BUILD := build
OBJ := $(BUILD)/obj
BIN := $(BUILD)/checksumgen

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

.PHONY: clean create-build-folder

all: create-build-folder $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cc $(INCLUDE)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

create-build-folder:
	@mkdir -p $(BUILD) $(OBJ)

clean:
	@rm -rf $(BUILD)
