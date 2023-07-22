OBJ=obj/
SRC=src/
LIB=../../lib-cplusplus/src/
CORE=../core/src/
TARGET=$(OBJ)notas.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
OBJS=$(OBJ)main.o $(OBJ)ncurses-notas.o $(OBJ)Tetrade.o $(OBJ)Triade.o $(OBJ)Intervalo.o $(OBJ)Janela.o $(OBJ)Nota.o $(OBJ)Mathematics.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(NCURSES)
 
$(OBJ)Mathematics.o:  
	$(CC) -c $(CCFLAGS) $(LIB)Mathematics.cpp -o $(OBJ)Mathematics.o 

$(OBJ)Nota.o: $(CORE)Nota.h $(CORE)Nota.cpp 
	$(CC) -c $(CCFLAGS) $(CORE)Nota.cpp -o $(OBJ)Nota.o 

$(OBJ)Intervalo.o: $(CORE)Intervalo.h $(CORE)Intervalo.cpp
	$(CC) -c $(CCFLAGS) $(CORE)Intervalo.cpp -o $(OBJ)Intervalo.o 

$(OBJ)Triade.o: $(CORE)Triade.h $(CORE)Triade.cpp
	$(CC) -c $(CCFLAGS) $(CORE)Triade.cpp -o $(OBJ)Triade.o 

$(OBJ)Tetrade.o: $(CORE)Tetrade.h $(CORE)Tetrade.cpp 
	$(CC) -c $(CCFLAGS) $(CORE)Tetrade.cpp -o $(OBJ)Tetrade.o 

$(OBJ)Janela.o: $(SRC)Janela.h $(SRC)Janela.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)Janela.cpp -o $(OBJ)Janela.o $(NCURSES)

$(OBJ)ncurses-notas.o: $(SRC)ncurses-notas.h $(SRC)ncurses-notas.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)ncurses-notas.cpp -o $(OBJ)ncurses-notas.o 

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug:all
	gdb $(TARGET)
run:all
	$(TARGET) 
clean:
	rm $(OBJ)*.o


