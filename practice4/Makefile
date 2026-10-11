CC      = gcc
CFLAGS  = -std=c89 -pedantic -Wall -g
TARGET  = books

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: clean
