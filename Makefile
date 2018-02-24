DEUBG = -DXOP_DEBUG

TARGET = test

CXX   = g++
CC    = gcc
STRIP = 

INC  = 
LIB  = 
									   
LD_FLAGS  = -lrt -pthread -lpthread -ldl -lm $(DEBUG)
CXX_FLAGS = -std=c++11 

O_FLAG   = -O2 -g 

SRC1  = $(notdir $(wildcard ./*.cpp))	
OBJS1 = $(patsubst %.cpp,objs/%.o,$(SRC1))	

SRC2  = $(notdir $(wildcard ./xop/*.cpp))		
OBJS2 = $(patsubst %.cpp,objs/%.o,$(SRC2))	

$(TARGET) : $(OBJS1) $(OBJS2) 
	$(CXX) $^ -o $@ $(CFLAGS) $(LD_FLAGS) 

objs/%.o : ./%.cpp  
	$(CXX) -c  $< -o  $@ $(CXX_FLAGS) $(LD_FLAGS) 
objs/%.o : ./xop/%.cpp  
	$(CXX) -c  $< -o  $@ $(CXX_FLAGS) $(LD_FLAGS) 

clean: 
	rm $(OBJS1) $(OBJS2) $(TARGET)














