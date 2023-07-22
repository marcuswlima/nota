OBJ=obj/
SRC=src/
LIB=../../lib-cplusplus/src/
CORE=:
TARGET=$(OBJ)notas.sh
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
OBJS=$(OBJ)Mathematics.o                  \
     $(OBJ)Nota.o   $(OBJ)Intervalo.o     \
	 $(OBJ)Triade.o $(OBJ)Tetrade.o       \
	 $(OBJ)Janela.o $(OBJ)ncurses-notas.o \
     $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(NCURSES)
 
$(OBJ)Mathematics.o: $(SRC)Mathematics.cpp $(SRC)Mathematics.h  
	cp -v $(LIB)Mathematics* $(SRC)
	$(CC) -c $(CCFLAGS) $(SRC)Mathematics.cpp -o $(OBJ)Mathematics.o

$(OBJ)Nota.o: $(SRC)Nota.cpp $(SRC)Nota.h 
	$(CC) -c $(CCFLAGS) $(SRC)Nota.cpp -o $(OBJ)Nota.o

$(OBJ)Intervalo.o: $(SRC)Intervalo.cpp $(SRC)Intervalo.h 
	$(CC) -c $(CCFLAGS) $(SRC)Intervalo.cpp -o $(OBJ)Intervalo.o

$(OBJ)Triade.o: $(SRC)Triade.cpp $(SRC)Triade.h 
	$(CC) -c $(CCFLAGS) $(SRC)Triade.cpp -o $(OBJ)Triade.o

$(OBJ)Tetrade.o: $(SRC)Tetrade.cpp $(SRC)Tetrade.h 
	$(CC) -c $(CCFLAGS) $(SRC)Tetrade.cpp -o $(OBJ)Tetrade.o

$(OBJ)Janela.o: $(SRC)Janela.cpp $(SRC)Janela.h 
	$(CC) -c $(CCFLAGS) $(SRC)Janela.cpp -o $(OBJ)Janela.o

$(OBJ)ncurses-notas.o: $(SRC)ncurses-notas.cpp $(SRC)ncurses-notas.h $(SRC)Janela.h $(SRC)Tetrade.h
	$(CC) -c $(CCFLAGS) $(SRC)ncurses-notas.cpp -o $(OBJ)ncurses-notas.o

$(OBJ)main.o: $(SRC)main.cpp $(SRC)ncurses-notas.h
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug:all
	gdb $(TARGET)
run:all
	$(TARGET) 
clean:
	rm $(OBJ)*.o


