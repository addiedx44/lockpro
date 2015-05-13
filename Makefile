CC = gcc
CFLAGS = -Wall
RM = rm

EXE = lockpro

all: $(EXE)

$(EXE): $(EXE).c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	$(RM) -f $(EXE)
