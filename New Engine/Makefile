CXX=g++
CXXFLAGS= -std=c++17 -Wall 
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window

csrc = $(wildcard /*.cpp) 					        \
       $(wildcard code/*.cpp) 				        \
       $(wildcard code/engine/*.cpp)           \
       $(wildcard code/engine/storage/*.cpp)           \


obj = $(csrc:.cpp=.o)

all: application clean

application: $(obj)
	$(CXX) $(CFLAGS)-o $@ $^ $(LDFLAGS)	

clean: 
	rm $(obj)
