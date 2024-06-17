CC := g++ --std=c++11
CC_OBJECTS := $(CC) -c 
DEBUG := $(CC) -g


all: utaxi.out 

utaxi.out: build/data.o build/driver.o build/get.o build/request.o build/response.o build/route.o build/template_parser.o build/utilities.o build/server.o build/handler.o build/global_function.o build/inputmanager.o build/location.o build/passenger.o build/main.o build/person.o build/post.o build/requestt.o build/trip.o build/utaxi.o build/delete.o
	$(CC) build/*.o -o $@

build/data.o: data.cpp data.hpp trip.hpp passenger.hpp server/handler.hpp driver.hpp location.hpp 
	$(CC_OBJECTS) $< -o $@

build/handler.o: server/handler.cpp server/handler.hpp post.hpp delete.hpp get.hpp define.hpp
	$(CC_OBJECTS) $< -o $@

build/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC_OBJECTS) $< -o $@

build/response.o: utils/response.cpp utils/response.hpp utils/include.hpp utils/utilities.hpp
	$(CC_OBJECTS) $< -o $@

build/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/utilities.hpp  utils/request.hpp server/server.hpp
	$(CC_OBJECTS) $< -o $@

build/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC_OBJECTS) $< -o $@

build/route.o: server/route.cpp server/route.hpp utils/response.hpp utils/include.hpp utils/request.hpp
	$(CC_OBJECTS) $< -o $@

build/server.o: server/server.cpp server/server.hpp utils/template_parser.hpp utils/utilities.hpp  utils/request.hpp utils/response.hpp server/route.hpp
	$(CC_OBJECTS) $< -o $@

build/driver.o: driver.cpp driver.hpp person.hpp 
	$(CC_OBJECTS) $< -o $@

build/main.o: main.cpp 
	$(CC_OBJECTS) $< -o $@

build/get.o: get.cpp get.hpp requestt.hpp
	$(CC_OBJECTS) $< -o $@

build/delete.o: delete.cpp delete.hpp 
	$(CC_OBJECTS) $< -o $@

build/global_function.o: global_function.cpp global_function.hpp define.hpp
	$(CC_OBJECTS) $< -o $@

build/inputmanager.o: inputmanager.cpp inputmanager.hpp data.hpp requestt.hpp post.hpp get.hpp
	$(CC_OBJECTS) $< -o $@

build/location.o: location.cpp location.hpp 
	$(CC_OBJECTS) $< -o $@

build/passenger.o: passenger.cpp passenger.hpp person.hpp
	$(CC_OBJECTS) $< -o $@

build/person.o: person.cpp person.hpp define.hpp trip.hpp
	$(CC_OBJECTS) $< -o $@

build/post.o: post.cpp post.hpp driver.hpp passenger.hpp requestt.hpp
	$(CC_OBJECTS) $< -o $@

build/requestt.o: requestt.cpp requestt.hpp define.hpp global_function.hpp data.hpp
	$(CC_OBJECTS) $< -o $@

build/trip.o: trip.cpp trip.hpp define.hpp passenger.hpp driver.hpp
	$(CC_OBJECTS) $< -o $@

build/utaxi.o: utaxi.cpp utaxi.hpp passenger.hpp trip.hpp driver.hpp passenger.hpp driver.hpp location.hpp inputmanager.hpp data.hpp requestt.hpp
	$(CC_OBJECTS) $< -o $@