CC = g++ -Wall -Werror -Wextra -g -std=c++17
SRC= $(wildcard *.c)
OBJ= $(patsubst %.c, %.o, ${SRC})
LFLAGS= -lgtest -lpthread 
GCF= -ftest-coverage -fprofile-arcs --coverage
FILES = ./Model/s21_model_calc.cpp

ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit -lm
endif


all: clean SmartCalc.a gcov_report

rebuild: clean SmartCalc.a

clean:
	rm -rf *.o && rm -rf *.gcno
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf ./report/
	rm -rf test_output/	
	rm -rf *.out
	rm -rf ./doxygen
	rm -rf html
	rm -rf docs
	rm -rf Doxyfile.bak
	rm -rf build-SmartCalc-Desktop_Qt_6_5_2_GCC_64bit-Debug
	rm -rf Archive_calc_v1.0.tgz
	rm -rf build

SmartCalc.o:
	$(CC) -c ${FILES} -o SmartCalc.o

SmartCalc.a: SmartCalc.o
	ar rcs SmartCalc.a SmartCalc.o
	ranlib SmartCalc.a
	rm *.o

tests: SmartCalc.a
	$(CC) -o test ./Unit_tests/unit_tests.cpp ${FILES} ${LFLAGS}
	./test

gcov_report: tests
	$(CC) $(GCF) Unit_tests/unit_tests.cpp Model/s21_model_calc.cpp $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\

install:
	make clean
	mkdir build
	cd View && qmake && make && make clean && rm -rf Makefile && cd ../
ifeq ($(shell uname -s), Linux)
	mv View/calculator build
else
ifeq ($(shell uname -s), Darwin)
	mv View/calculator.app build
endif
endif

uninstall:
	rm -rf build*

dvi:
	doxygen Doxyfile
	google-chrome docs/html/index.html

dist: install
	rm -rf Archive_calc_v1.0/
	mkdir Archive_calc_v1.0/
	mkdir Archive_calc_v1.0/src
ifeq ($(OS),Linux)
	cp -r ./build/SmartCalc Archive_calc_v1.0/src/
else
ifeq ($(OS),Darwin)
	cp -r ./build/SmartCalc.app Archive_calc_v1.0/src/
endif
endif
	tar cvzf Archive_calc_v1.0.tgz Archive_calc_v1.0/
	rm -rf Archive_calc_v1.0/

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n */*.cpp */*.cpp */*.h
	rm -f .clang-format

style_correct:
	cp ../materials/linters/.clang-format ./
	clang-format -i */*.cpp */*.cpp */*.h
	rm -f .clang-format
