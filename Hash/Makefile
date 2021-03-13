# Alunos: Eduardo Purkote e Guilherme Mota                   #
# GRR's      20182960          20197268                       #
#   **Arquivo Make para Gerar os arquivos do Programa**      #

CFLAGS = "-Wall" 

all: myht

myht: myht.o
	gcc main.c -lm -omyht 

myht.o: myht.c myht.h
	gcc myht.c -lm -c $(CFLAGS)

clean:
	-rm -f *~ *.o *.out
purge: clean
	-rm -f myht
