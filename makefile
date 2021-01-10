VPATH = Square/Square:Sample2/Sample2
HEADER_PATH = -I./include/

.PHONY : all
all : _Square _ Sample2

_Square : Square.o Square_class.o
	g++ -o _Square Square.o Square_class.o

Square.o Square_class.o : Square_class.h

.PHONY : clean cleanobj cleanrun

clean : cleanobj cleanrun

cleanobj :
	rm *.o
cleanrun :
	rm _Square _Sample2
