OBJ=build/
SRC=./
TARGET=$(OBJ)notas.sh
CC=g++
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
GTK=$$(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
NCURSES=-lncurses
OBJS=$(OBJ)Nota.o   $(OBJ)Intervalo.o  \
	 $(OBJ)Triade.o $(OBJ)Tetrade.o    \
	 $(OBJ)main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
$(OBJ)Nota.o: $(SRC)Nota.cpp $(SRC)Nota.h 
	$(CC) -c $(CCFLAGS) $(SRC)Nota.cpp -o $(OBJ)Nota.o

$(OBJ)Intervalo.o: $(SRC)Intervalo.cpp $(SRC)Intervalo.h 
	$(CC) -c $(CCFLAGS) $(SRC)Intervalo.cpp -o $(OBJ)Intervalo.o

$(OBJ)Triade.o: $(SRC)Triade.cpp $(SRC)Triade.h 
	$(CC) -c $(CCFLAGS) $(SRC)Triade.cpp -o $(OBJ)Triade.o

$(OBJ)Tetrade.o: $(SRC)Tetrade.cpp $(SRC)Tetrade.h 
	$(CC) -c $(CCFLAGS) $(SRC)Tetrade.cpp -o $(OBJ)Tetrade.o

$(OBJ)main.o: $(SRC)main.cpp 
	$(CC) -c $(CCFLAGS) $(SRC)main.cpp -o $(OBJ)main.o 

debug:all
	gdb $(TARGET)
run:all
	$(TARGET) 
clean:
	rm $(OBJ)*.o


