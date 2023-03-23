HEADER_PATH = -I./include/ 

MAIN =  src/main.cpp src/mocha.cpp src/unit_test.cpp  src/espresso_based.cpp src/cappuccino.cpp

GCC = g++ -Wall -std=c++11 

T = build/main

$(T): $(UNIT_TEST) $(HW1) $(MAIN)
	$(GCC) $^ -o $@  $(HEADER_PATH)  -lpthread -lgtest 

.PHONY:clean run

run:
	./$(T)

clean:
	rm  $(T)