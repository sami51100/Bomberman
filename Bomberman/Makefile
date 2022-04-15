#by DRIOUCHE Sami

CC = g++
FLAGS := -Wall -g -Wextra -std=c++17
EXEC = prog 
SRC= $(wildcard *.cpp) $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

$(EXEC): $(OBJ) 
	$(CC) $(FLAGS) -o $@ $^

%.o : %.c 
	$(CC) $(FLAGS) -o $@ -c $<

clean : 
	rm -rf $(OBJ)