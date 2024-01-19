CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -MD
BUILD := ./build
BIN := ./pepe
LIBS := -lsfml-window -lraylib
OBJS := pepe.o
OBJS := $(addprefix $(BUILD)/, $(OBJS))

.PHONY: clean

$(BIN): $(BUILD) $(OBJS)
	$(CXX) $(LIBS) $(OBJS) -o $@

$(BUILD):
	mkdir -p $(BUILD)

$(OBJS): $(BUILD)/%.o: ./src/%.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $<

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD) $(BIN)
