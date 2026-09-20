
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude
TARGET = student_records

$(TARGET): src/main.c src/system.c include/system.h
	$(CC) $(CFLAGS) src/main.c src/system.c -o $(TARGET)

clean:
	rm -f $(TARGET)
