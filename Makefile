SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
LIB_OBJS=$(subst obj/main.o,,$(OBJS))

CC=clang++
CFLAGS=-stdlib=libstdc++ -std=c++11 -c
LFLAGS=

DEPS=src/Singleton.d

TARGET=$(BIN_DIR)/ResourceManager
LIB_TARGET=$(BIN_DIR)/libresource_manager.a


$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) -o$@ $(OBJS)

$(LIB_TARGET): $(LIB_OBJS)
	ar -cvq $(LIB_TARGET) $(LIB_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o$@ $<

-include $(DEPS)

clean: $(OBJS)
	rm $(OBJS)

run: $(OBJS)
	./$(TARGET)

.PHONY:clean
