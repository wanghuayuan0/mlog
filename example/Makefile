
all:
	mkdir build
	gcc -c -DMLOG_ENABLE -I. -I../src main.c -o build/main.o
	gcc -c -DMLOG_ENABLE -I. -I../src test_dynamic.c -o build/test_dynamic.o
	gcc -c -DMLOG_ENABLE -I. -I../src test_static.c -o build/test_static.o
	gcc -c  -DMLOG_ENABLE -I../src ../src/mlog.c -o build/mlog.o
	gcc build/*.o -o build/main

run:
	./build/main

clean:
	rm -rf build