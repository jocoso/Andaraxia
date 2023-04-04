CFLAGS= 
BIN_DIR=./bin
OBJ_DIR=$(BIN_DIR)/obj

CLIENT_DIR=./Client

KRK_LIB_DIR=./KrakenEngine
KRK_LIB_CORE_DIR=$(KRK_LIB_DIR)/Core

SFML_INCLUDE=.\libraries\SFML-2.5.1\include
SFML_LIB=.\libraries\SFML-2.5.1\lib
SFML_DESC=-lsfml-graphics -lsfml-window -lsfml-system

EXEC=sfml-app

all: $(BIN_DIR)/$(EXEC) run

# create client object files
$(OBJ_DIR)/main.o: $(CLIENT_DIR)/main.cpp $(OBJ_DIR)
	g++ -c $< -I$(SFML_INCLUDE) -o $@

# create library object files
$(OBJ_DIR)/%.o: $(KRK_LIB_CORE_DIR)/%.cpp $(OBJ_DIR)
	g++ -c $< -I$(SFML_INCLUDE) -o $@

# creates bin iff bin directory does not exists
$(BIN_DIR):
	[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)

# creates obj iff obj directory does not exists
$(OBJ_DIR): $(BIN_DIR)
	[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR)

# linking...
$(BIN_DIR)/$(EXEC): $(OBJ) $(OBJ_DIR)/main.o $(OBJ_DIR)/krakeneng.o
	g++ $(OBJ_DIR)/main.o $(OBJ_DIR)/krakeneng.o -o $@ -L$(SFML_LIB) $(SFML_DESC)

run:
	$(BIN_DIR)/$(EXEC).exe

clean:
	rm -rf bin