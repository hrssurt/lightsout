CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
EXEC = a4q3
OBJECTS = cell.o grid.o textdisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
