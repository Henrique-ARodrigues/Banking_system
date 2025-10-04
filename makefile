CXX = g++
CXXFLAGS = -Wall -g -std=c++17
TARGET = main
TESTS = tests

# Arquivos fonte
SRC = main.cpp user.cpp bank_account.cpp auxiliary.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = tests.cpp user.cpp bank_account.cpp auxiliary.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Alvo padrão
all: $(TARGET) $(TESTS)

# Compilar main
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilar testes
$(TESTS): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TESTS) $(TEST_OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rodar main
run: $(TARGET)
	./$(TARGET)

# Rodar testes
run-tests: $(TESTS)
	./$(TESTS)

# Limpeza
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TESTS)
