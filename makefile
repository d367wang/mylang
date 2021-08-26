.PHONY: clean

TARGET='./bin/test'

all:
#	cd ./3rdparty/ && make
#	g++ -g -Wall *.cpp  src/*.cc  ./3rdparty/*.c  ./3rdparty/libs/libantlr3c.a -o $(TARGET)
	g++ -g *.cpp  src/*.cc  ./3rdparty/*.c  ./3rdparty/libs/libantlr3c.a -o $(TARGET) \
	-I./include -I./3rdparty -I./3rdparty/include

clean:
	rm -rf $(TARGET)
