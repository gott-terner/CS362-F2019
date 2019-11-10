CFLAGS = -Wall -fpic -coverage -lm

randomTestResult.out: testme.C
	gcc -o testme testme.c $(CFLAGS)
		testme >> randomTestResult.out
		gcov -f -b testme.c >> randomTestResult.out

all: randomTestResult.out

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out randomTestResult.out