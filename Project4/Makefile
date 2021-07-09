OBJS	= main.o
SOURCE	= main.cpp
HEADER	= 
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)


