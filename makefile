CC = g++
INCLUDES =
DEFINE_FLAGS=

ifeq (${mode}, release)
	FLAGS = -O3 -march=native -std=c++17
else
	mode = debug
	FLAGS = -O0 -g -std=c++17
endif

GL_FLAGS =
LIB_FLAGS =
OBJS =
PROJECT_NAME = gp_project

ifeq (${mode}, debug)
	PROJECT = ${PROJECT_NAME}_debug
else
	PROJECT = ${PROJECT_NAME}
endif

${PROJECT}: ${OBJS} main.o clean_emacs_files
	@echo "Building on "${mode}" mode"
	@echo ".........................."
	${CC} ${INCLUDES} ${FLAGS} ${DEFINE_FLAGS} ${OBJS} main.o -o $@ ${GL_FLAGS} ${LIB_FLAGS}
	-make clean

main.o:
	${CC} ${INCLUDES} ${FLAGS} ${DEFINE_FLAGS} -c main.cpp -o $@ ${GL_FLAGS} ${LIB_FLAGS}

.PHONEY: clean clean_emacs_files clean_all
clean:
	-rm -rf ${OBJS} main.o
clean_emacs_files:
	-rm -rf *~
clean_all: clean clean_emacs_files
	-rm -rf ${PROJECT_NAME} ${PROJECT_NAME}_debug
