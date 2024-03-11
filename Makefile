CC=g++
CFLAGS=--std=c++17 -Wall -Werror -Wextra -lm
CFLAGS2=-fprofile-arcs -ftest-coverage
WASH=rm -rf *.o *.out *css *gcno *gcda *.html .clang-format
OS=$(shell uname)
ifeq ($(OS), Linux)
	LFLAGS = -lgtest -pthread -lgmock --coverage
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_vector.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_array.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_list.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_stack.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_queue.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_map.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_set.out
#	LEAKS=CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./test_multiset.out
else
	LFLAGS = -fsanitize=address -lgtest -pthread -lgcov --coverage
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_vector.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_array.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_list.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_stack.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_queue.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_map.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_set.out
#	LEAKS=CK_FORK=no leaks --atExit -- ./test_multiset.out
endif

all: clean gcov_report

gcov_report: test
	gcovr -r . --html --html-details -o gcov_report.html
	open gcov_report.html

test: test_vector test_array test_list test_stack test_queue test_map test_set test_multiset

test_vector: test_vector.o src/containers/vector.h
	$(CC) $^ -o test_vector.out $(LFLAGS) && ./test_vector.out

test_vector.o: src/tests/test_vector.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_array: test_array.o src/containers/array.h
	$(CC) $^ -o test_array.out $(LFLAGS) && ./test_array.out

test_array.o: src/tests/test_array.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_list: test_list.o src/containers/list.h
	$(CC) $^ -o test_list.out $(LFLAGS) && ./test_list.out

test_list.o: src/tests/test_list.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_stack: test_stack.o src/containers/stack.h
	$(CC) $^ -o test_stack.out $(LFLAGS) && ./test_stack.out

test_stack.o: src/tests/test_stack.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_queue: test_queue.o src/containers/queue.h
	$(CC) $^ -o test_queue.out $(LFLAGS) && ./test_queue.out

test_queue.o: src/tests/test_queue.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_map: test_queue.o src/containers/map.h
	$(CC) $^ -o test_map.out $(LFLAGS) && ./test_map.out

test_map.o: src/tests/test_map.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_set: test_queue.o src/containers/set.h
	$(CC) $^ -o test_set.out $(LFLAGS) && ./test_set.out

test_set.o: src/tests/test_set.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

test_multiset: test_multiset.o src/containers/multiset.h
	$(CC) $^ -o test_multiset.out $(LFLAGS) && ./test_multiset.out

test_multiset.o: src/tests/test_multiset.cc
	$(CC) $(CFLAGS2) -c $^ -o $@

check_clang: containers/*.h backend/*.h tests/*.cc
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $^

check_leaks:
	$(LEAKS)

check_cppcheck: containers/*.h backend/*.h
	cppcheck --language=c++ --std=c++17 --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $^

clean:
	$(WASH)
