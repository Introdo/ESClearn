TARGET := LEL

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := compiled
LIB_DIR := libs

OUT := $(BIN_DIR)/$(TARGET)

CC := gcc

CFLAGS := \
    -std=c99 \
    -Wall \
    -Wextra \
    -D_POSIX_C_SOURCE=200809L \
    -O2 \
    -I$(LIB_DIR)/include \

LDFLAGS := -L$(LIB_DIR)
LIBS := $(wildcard $(LIB_DIR)/*.a)

SRC := $(shell find $(SRC_DIR) -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: build clean

build: $(OUT)

$(OUT): $(OBJ)
    @mkdir -p $(BIN_DIR)
    $(CC) $(OBJ) $(LIBS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(@D)
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR) build
