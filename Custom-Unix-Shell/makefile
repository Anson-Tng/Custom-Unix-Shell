main_test:  main.o job_executor.o
	gcc job_executor.o main.o -o main_test

main.o: main.c job_executor.h
	gcc -c main.c

job_executor.o: job_executor.c job_executor.h
	gcc -c job_executor.c

clean:
	TABrm *.o

