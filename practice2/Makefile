CC      = gcc
CFLAGS  = -std=c89 -pedantic -Wall -g
LDLIBS  = -lm
TARGET  = mathtask

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: clean
