CFLAGS= -g -ggdb
BIN_DIR=./bin
OBJ_DIR=$(BIN_DIR)/obj
TEST_DIR=./Test

CC = g++

ENG_LIBDIR=./Engine

NLOHMANN_INCLUDE = ./libraries/json/include
SFML_INCLUDE=./libraries/SFML-2.5.1/include
SFML_LIB=./libraries/SFML-2.5.1/lib
SFML_DESC=-lsfml-graphics -lsfml-window -lsfml-system

EXEC=andaraxia

ENGINE_SRCS:=$(wildcard $(ENG_LIBDIR)/*.cpp)
ENGINE_OBJS:=$(ENGINE_SRCS:$(ENG_LIBDIR)/%.cpp=$(OBJ_DIR)/%.o)

all: createDirectories $(BIN_DIR)/$(EXEC) 
#run

createDirectories: $(OBJ_DIR)

.PHONY: test
TEST_NAME?=enginetest
test: createDirectories $(ENGINE_OBJS)
	$(CC) -c $(TEST_DIR)/$(TEST_NAME).cpp -I$(SFML_INCLUDE) -o $(TEST_DIR)/$(TEST_NAME).o
	$(CC) $(TEST_DIR)/$(TEST_NAME).o $> -o $(TEST_DIR)/$(TEST_NAME).exe -L$(SFML_LIB) $(SFML_DESC) 
	./$(TEST_DIR)/$(TEST_NAME).exe

# create client object files
$(OBJ_DIR)/main.o: 
	$(CC) -c main.cpp $(CFLAGS) -I$(SFML_INCLUDE) -I$(NLOHMANN_INCLUDE) -o $@

# create library object files
$(OBJ_DIR)/%.o: $(ENG_LIBDIR)/%.cpp
	$(CC) -c $^ $(CFLAGS) -I$(SFML_INCLUDE) -I$(NLOHMANN_INCLUDE) -o $@

# creates bin iff bin directory does not exists
$(BIN_DIR):
	[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)

# creates obj iff obj directory does not exists
$(OBJ_DIR): $(BIN_DIR)
	[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR)

# linking...
$(BIN_DIR)/$(EXEC): $(OBJ_DIR)/main.o $(ENGINE_OBJS)
	$(CC) $^ -o $@ $(CFLAGS) -L$(SFML_LIB) $(SFML_DESC)

run:
	$(BIN_DIR)/$(EXEC).exe 

install:
	make clean && make

clean:
	rm -rf bin $(TEST_DIR)/*.o $(TEST_DIR)/*.exe