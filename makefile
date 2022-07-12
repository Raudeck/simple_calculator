CC = gcc
CFLAGS = -Wall -Os
BUILDDIR = build
TARGET = $(BUILDDIR)/calculator.exe
SRC = src
OBJS = $(addprefix $(BUILDDIR)/, $(notdir $(patsubst %.c, %.o, $(wildcard $(SRC)/*.c))))
HEADERS = $(wildcard $(SRC)/*.h)

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRC)/%.c $(HEADERS)
	gcc -c $< -o $@

clean: 
	-rm -r $(BUILDDIR)/*.o
	-rm $(TARGET)