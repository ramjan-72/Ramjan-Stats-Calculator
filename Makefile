# Makefile for Ramjan Stats Calculator

CC = gcc
CFLAGS = -Wall
TARGET = calculator

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
