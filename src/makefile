#makefile

CC = g++ -std=c++11
CFLAGS=-c -Wall
SOURCES = Main.cpp Cli.cpp CliGet.cpp CliValidate.cpp Compute.cpp Draw.cpp Settings.cpp
OBJS = $(SOURCES:.cpp=.o)
EXEC = PolynomialConsoleGraph

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


