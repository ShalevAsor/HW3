CC=gcc
AR=ar
OBJECTS_ISORT_MAIN=isort.o
OBJECT_TXTFIND_MAIN=txtfind.o
FLAGS=-Wall -g

all: txtfind isort
isort.o: isort.c 
	$(CC) $(FLAGS) -c isort.c 

txtfind.o: txtfind.c 
	$(CC) $(FLAGS) -c txtfind.c

isort: $(OBJECTS_ISORT_MAIN)
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT_MAIN)
txtfind: $(OBJECT_TXTFIND_MAIN)
	$(CC) $(FLAGS) -o txtfind $(OBJECT_TXTFIND_MAIN)

.PHONY:clean all

clean:
	rm -f *.o txtfind isort 
