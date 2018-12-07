#Variable
CC=g++ -Wall 

F=pgrm

#Commande
all : ${F}

$(F) : $(F).o $(F)1.o $(F)_main.o
	$(CC) $(F).o $(F)1.o $(F)_main.o -o $(F)

$(F).o : $(F).cpp
	$(CC) -c $(F).cpp

$(F)1.o : $(F)1.cpp
	$(CC) -c $(F)1.cpp

$(F)_main.o : $(F)_main.cpp $(F).h $(F)1.h
	$(CC) -c $(F)_main.cpp

clean:
	rm -rf *.o
