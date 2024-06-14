# ID: 319055430
# Email: noa.fishman@gmail.com

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -Werror -g

# Source files
SRCS = board.cpp catan.cpp game.cpp hex.cpp player.cpp road.cpp vertex.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable files
CATAN = game
TEST = Test

# Targets
all: $(CATAN) $(TEST)

$(CATAN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST): TestCounter.o Test.o board.o catan.o hex.o player.o road.o vertex.o
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile .cpp files to .o files

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(CATAN) $(TEST)
