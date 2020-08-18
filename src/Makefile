APP = VcPcap
CXX = g++
CXXFLAGS = -W -Wall -g
objects = main.o 
all: $(objects) APP

main.o: main.cpp ../include/VcPcap.h
	$(CXX) $(CXXFLAGS) main.cpp -lpcap -o main.o

APP: 
	$(CXX) -c $(objects) -o $(APP)

.PHONY: clean
clean:
	rm  VcPcap $(objects)

