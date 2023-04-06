CFLAGS= 
BIN_DIR=./bin
OBJ_DIR=$(BIN_DIR)/obj

CLIENT_DIR=./Client

ENG_LIBDIR=./Engine

SFML_INCLUDE=.\libraries\SFML-2.5.1\include
SFML_LIB=.\libraries\SFML-2.5.1\lib
SFML_DESC=-lsfml-graphics -lsfml-window -lsfml-system

EXEC=sfml-app

all: createDirectories $(BIN_DIR)/$(EXEC) run

createDirectories: $(OBJ_DIR)

# create client object files
$(OBJ_DIR)/main.o: ./main.cpp
	g++ -c $< -I$(SFML_INCLUDE) -o $@

# create library object files
$(OBJ_DIR)/%.o: $(ENG_LIBDIR)/%.cpp
	g++ -c $< -I$(SFML_INCLUDE) -o $@

# creates bin iff bin directory does not exists
$(BIN_DIR):
	[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)

# creates obj iff obj directory does not exists
$(OBJ_DIR): $(BIN_DIR)
	[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR)

# linking...
$(BIN_DIR)/$(EXEC): $(OBJ_DIR)/main.o $(OBJ_DIR)/engine.o
	g++ $(OBJ_DIR)/main.o $(OBJ_DIR)/engine.o -o $@ -L$(SFML_LIB) $(SFML_DESC)

run:
	$(BIN_DIR)/$(EXEC).exe

clean:
	rm -rf bin