CC=gcc
CFLAGS=-Wall -Werror

TARGET=byte_stuffing

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
