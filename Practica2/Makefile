DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -lglut -lGLU -lGL
CC := gcc

all: dirs ej1 ej3 ej4 ej5 ej6 ej7 ej8

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

ej1: $(DIROBJ)ej1.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej3: $(DIROBJ)ej3.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej4: $(DIROBJ)ej4.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej5: $(DIROBJ)ej5.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej6: $(DIROBJ)ej6.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej7: $(DIROBJ)ej7.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ej8: $(DIROBJ)ej8.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
