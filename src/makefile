#makefile

CC = g++
CFLAGS=-c -Wall
SOURCES = Main.cpp Draw.cpp Compute.cpp Settings.cpp
OBJS = $(SOURCES:.cpp=.o)
EXEC = PolynomialConsoleGraph

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


