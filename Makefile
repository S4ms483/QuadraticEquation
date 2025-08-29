FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

CXX = g++

SRC = main.cpp solve.cpp user.cpp tests.cpp equality.cpp assert.cpp

OBJ = $(SRC:.cpp=.o)

EXE = SquareEquation

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(FLAGS) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf *.o $(EXE)