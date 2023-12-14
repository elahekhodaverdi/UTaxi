CC := g++ --std=c++11
CC_OBJECTS := $(CC) -c 
DEBUG := $(CC) -g


all: utaxi.out 

utaxi.out: data.o driver.o get.o global_function.o inputmanager.o location.o passenger.o main.o person.o post.o request.o trip.o utaxi.o delete.o
	$(CC) *.o -o $@

debug.out: data.o driver.o get.o global_function.o inputmanager.o location.o passenger.o main.o person.o post.o request.o trip.o utaxi.o delete.o
	$(DEBUG) *.o -o $@

data.o: data.cpp data.hpp trip.hpp passenger.hpp driver.hpp location.hpp 
	$(CC_OBJECTS) $< -o $@

driver.o: driver.cpp driver.hpp person.hpp 
	$(CC_OBJECTS) $< -o $@

main.o: main.cpp 
	$(CC_OBJECTS) $< -o $@

get.o: get.cpp get.hpp request.hpp
	$(CC_OBJECTS) $< -o $@

delete.o: delete.cpp delete.hpp 
	$(CC_OBJECTS) $< -o $@

global_function.o: global_function.cpp global_function.hpp 
	$(CC_OBJECTS) $< -o $@

inputmanager.o: inputmanager.cpp inputmanager.hpp data.hpp request.hpp post.hpp get.hpp
	$(CC_OBJECTS) $< -o $@

location.o: location.cpp location.hpp 
	$(CC_OBJECTS) $< -o $@

passenger.o: passenger.cpp passenger.hpp person.hpp
	$(CC_OBJECTS) $< -o $@

person.o: person.cpp person.hpp define.hpp trip.hpp
	$(CC_OBJECTS) $< -o $@

post.o: post.cpp post.hpp driver.hpp passenger.hpp request.hpp
	$(CC_OBJECTS) $< -o $@

request.o: request.cpp request.hpp define.hpp global_function.hpp data.hpp
	$(CC_OBJECTS) $< -o $@

trip.o: trip.cpp trip.hpp define.hpp passenger.hpp driver.hpp
	$(CC_OBJECTS) $< -o $@

utaxi.o: utaxi.cpp utaxi.hpp passenger.hpp trip.hpp driver.hpp passenger.hpp driver.hpp location.hpp inputmanager.hpp data.hpp request.hpp
	$(CC_OBJECTS) $< -o $@