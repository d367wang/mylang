.PHONY: clean

TARGET='./bin/test'

all:
	cd ./parser/ && make
	g++ -g -Wall *.cpp  src/*.cc  ./parser/*.c  ./parser/libs/libantlr3c.a -o $(TARGET) \
	-I./include -I./parser -I./parser/include

clean:
	rm -rf $TARGET