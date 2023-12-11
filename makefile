SRC := ./src
BUILD := ./build
BIN := $(BUILD)/bin
TARGET := game_of_life

build: $(SRC)/game_of_life.c
	./build.sh

$(BIN)/$(TARGET): $(SRC)/game_of_life.c
	./build.sh

run: $(BIN)/$(TARGET)
	$(BIN)/$(TARGET)

clean:
	rm $(BIN)/$(TARGET)
