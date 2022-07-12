CC = gcc
CFLAGS = -Wall -Os
BUILDDIR = build
TARGET = $(BUILDDIR)/calculator.exe
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILDDIR)/%.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	gcc -c $< -o $@

clean: 
	-rm -r $(BUILDDIR)/*.o
	-rm $(TARGET)