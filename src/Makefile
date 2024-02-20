CXX=g++
CXXFLAGS=-std=c++17 -c -Wall -Werror -Wextra 
GCOVFLAGS =--coverage
LDFLAGS=-lgtest
STATICLIBS=s21_graph.a s21_graph_algorithms.a
SOURCES=graph/s21_graph.cc \
		graph/s21_graph_algorithms.cc \
		graph/s21_ant_colony.cc \
		containers/s21_matrix.cc \
		interface/s21_interface.cc 
HEADERS=graph/s21_graph.h \
		graph/s21_graph_algorithms.h \
		graph/s21_ant_colony.h \
		containers/s21_matrix.h \
		containers/s21_queue.h \
		containers/s21_stack.h \
		interface/s21_interface.h 

OS=$(shell uname)
ifeq ($(OS), Linux)
LEAKS = CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out --gtest_filter=*test_*
OPEN=xdg-open
else
LEAKS = leaks --atExit -- ./test.out --gtest_filter=*test_*
OPEN=open
endif

all: clean build

build: $(STATICLIBS)

run: $(STATICLIBS)
	cp graph_txt/v*.txt . 
	$(CXX) main.cc ./interface/s21_interface.cc $(STATICLIBS) ./containers/s21_matrix.cc -o main.out
	./main.out
	$(RM) main.out

s21_graph.a:
	$(CXX) $(CXXFLAGS) ./graph/s21_graph.cc -o s21_graph.o
	ar rc s21_graph.a s21_graph.o 
	$(RM) s21_graph.o

s21_graph_algorithms.a:
	$(CXX) $(CXXFLAGS) ./graph/s21_graph_algorithms.cc -o s21_graph_algorithms.o
	$(CXX) $(CXXFLAGS) ./graph/s21_ant_colony.cc -o s21_ant_colony.o
	ar rc s21_graph_algorithms.a s21_graph_algorithms.o s21_ant_colony.o
	$(RM) s21_graph_algorithms.o s21_ant_colony.o

test: $(STATICLIBS)
	$(CXX) test.cc $(STATICLIBS) containers/s21_matrix.cc -o test.out $(LDFLAGS)
	./test.out

gcov_report: $(STATICLIBS)
	$(CXX)  test.cc $(STATICLIBS) containers/s21_matrix.cc $(GCOVFLAGS) -o gcov_rep.out $(LDFLAGS)
	./gcov_rep.out
	lcov -c -d . -o coverag.info --no-external #--ignore-errors mismatch
	genhtml -o ./report coverag.info
	# $(OPEN) ./report/index.html
	$(RM) *.out *.gcno *.gcda *.gcov *.info

clean:
	rm -rf ./report
	$(RM) *.o *.out *.gcno *.gcda *.gcov *.info *.dSYM *.a *.dot *.txt

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(SOURCES) $(HEADERS)
	clang-format -n $(SOURCES) $(HEADERS)
	$(RM) .clang-format

cppcheck:
	cppcheck --language=c++ --std=c++17 --suppress=unusedFunction \
	--suppress=missingInclude $(SOURCES) $(HEADERS)

leaks: clean test
	$(LEAKS)
