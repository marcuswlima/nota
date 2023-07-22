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
#OBJS=$(OBJ)main.o $(OBJ)GTKNotas.o
OBJS=$(OBJ)main.o $(OBJ)Tetrade.o $(OBJ)Triade.o $(OBJ)Intervalo.o $(OBJ)Nota.o $(OBJ)Mathematics.o $(OBJ)GTKNotas.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTK) 
 
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

$(OBJ)GTKNotas.o: $(SRC)GTKNotas.h $(SRC)GTKNotas.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)GTKNotas.cpp -o $(OBJ)GTKNotas.o $(GTK) 

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o $(GTK)

debug:all
	gdb $(TARGET)
run:all
	$(TARGET) 
clean:
	rm $(OBJ)*.o


