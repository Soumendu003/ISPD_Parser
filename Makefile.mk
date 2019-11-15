CXX = g++
CXXFLAGS = -std=c++11 -Wall -g 

CURR_DIR = /home/Guddu/ISPD_parser
UTIL_DIR = /home/Guddu/Util
OBJECTS = $(addsuffix .o, $(basename $(wildcard *.cpp)))
INCLUDE_DIR = ./build

install: copy

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

copy: $(UTIL_DIR)
	rm -rf $(INCLUDE_DIR) 
	mkdir $(INCLUDE_DIR)
	cp $(UTIL_DIR)/* $(INCLUDE_DIR)
	cp -f ./*.* $(INCLUDE_DIR)
	$(MAKE) -C $(INCLUDE_DIR) -f Makefile.mk build

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o exe
	cp exe.exe ./..
	$(MAKE) -C $(CURR_DIR) -f Makefile.mk clean

clean:
	rm -rf $(INCLUDE_DIR)

run:
	./exe.exe -benchmark IBM01A_L0 -nets IBM01A_L0.nets -blocks IBM01A_L0.wts
	./exe.exe -benchmark IBM06A_L0 -nets IBM06A_L0.nets -blocks IBM06A_L0.wts
	./exe.exe -benchmark IBM10C_L1_V1 -nets IBM10C_L1_V1.nets -blocks IBM10C_L1_V1.wts