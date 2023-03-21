include config.mk

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

all: clean exploration

exploration: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ} exploration

.PHONY: all exploration clean
