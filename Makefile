CXX = g++
CXXFLAGS = -g -Wall -Wextra


BIN 	 = main
OBJ		 = main.o
HEADERS	 = calculator.h
SLIB	 = calculator.a
SLIB_OBJ = calculator.o



all: $(BIN)


$(BIN): $(BIN).o $(SLIB)
	$(CXX) $(CXXFLAGS) $(BIN).o -o $(BIN) -L. -l:calculator.a


$(OBJ): main.cpp
	$(CXX) $(CXXFLAGS) -c $<


calculator.a: $(SLIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^


calculator.o: calculator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -rf $(BIN) $(OBJ) $(SLIB) $(SLIB_OBJ)