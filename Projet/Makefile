#Variable
CC=g++ -Wall 


#Commande
all : prog

prog : *.o
	$(CC) *.o -lncurses -o prog

*.o  : *.cpp
	$(CC) -lncurses -c *.cpp

#
#$(Y) : $(X).o $(Y).o $(Y)-main.o
#	$(CC) $(X).o $(Y).o $(Y)-main.o -o $(Y)
#
#$(X).o : $(X).cpp
#	$(CC) -c $(X).cpp
#
#$(Y).o : $(Y).cpp
#	$(CC) -c $(Y).cpp
#
#$(Y)_main.o : $(Y)_main.cpp $(X).h $(Y).h
#	$(CC) -c $(Y)-main.cpp

clear:
	rm -rf *.o

