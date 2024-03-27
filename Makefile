IDIR=./header
BUILD_DIR=./build
CC=g++
CFLAGS=-Wall
CPPFLAGS=-I$(IDIR)
TARGET=query
SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILD_DIR)/%.o:src/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

