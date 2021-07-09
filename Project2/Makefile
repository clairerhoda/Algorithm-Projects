OBJS	= main.o
SOURCE	= main.cpp
HEADER	= ngraph.hpp set_ops.hpp
OUT	= main.o
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17

run:
	./main.o

clean:
	rm *.o main