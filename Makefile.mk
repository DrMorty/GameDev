CXX=g++
CXXFLAGS= -std=c++17 -Wall 
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window

csrc = $(wildcard src/*.cpp) 					        \
       $(wildcard src/core/*.cpp) 				        \
       $(wildcard src/core/GameControl/*.cpp)           \
       $(wildcard src/core/management/*.cpp)			\
       $(wildcard src/core/objects/*.cpp)		\
       $(wildcard src/core/storage/*.cpp)               \
       $(wildcard src/core/shortcuts/*.cpp)               \
       $(wildcard src/core/math/*.cpp)               \

obj = $(csrc:.cpp=.o)

all: application clean

application: $(obj)
	$(CXX) $(CFLAGS)-o $@ $^ $(LDFLAGS)	

clean: 
	rm $(obj)

