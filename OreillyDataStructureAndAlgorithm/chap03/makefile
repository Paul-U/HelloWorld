CC	= g++

all: q1.out q2.out

q1.out: q1.o list.o
q2.out: q2.o list.o

.o.out:
	$(CC) -o $@ $^

.cpp.o:
	$(CC) -c $<

q1.o: list.hpp
q2.o: list.hpp
list.o: list.hpp
