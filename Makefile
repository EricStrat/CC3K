CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = exec
OBJECTS = main.o textdisplay.o character.o player.o enemy.o shade.o vampire.o drow.o troll.o goblin.o human.o dwarf.o elf.o orc.o merchant.o dragon.o halfling.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
