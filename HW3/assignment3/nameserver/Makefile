CPP_CODE_FILES := $(sort $(wildcard *.cpp) $(wildcard *.cc))
CPP_OBJ_FILES := $(addsuffix .o,$(basename $(CPP_CODE_FILES)))
H_FILES := $(wildcard *.h)

.PHONY: all clean

all: nameserver

nameserver: $(CPP_OBJ_FILES) 
	g++ $(CPP_OBJ_FILES) -o nameserver -std=c++11

%.o: %.cpp $(H_FILES)
	g++ $< -I -ldl -std=c++11 -c -o $@ -g -std=c++11

clean:
	-rm -rf *.o
	-rm nameserver


