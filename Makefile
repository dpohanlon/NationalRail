CXX = clang++

INCLUDES = -I/usr/local/Cellar/boost/1.51.0/include/

CPPFLAGS = -std=c++11 -stdlib=libc++ -g -O3 $(INCLUDES)

SOURCES = $(wildcard src/*.cpp)
SOURCES += $(wildcard src/Parsers/*.cpp)
SOURCES += $(wildcard src/Records/*.cpp)

OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

TARGET = bin/connect

all: $(TARGET)

$(TARGET): build $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $(TARGET)

build:
	@mkdir -p bin

.PHONY: clean
clean:
	@-rm -rf src/*.o
	@-rm -rf src/Parsers/*.o
	@-rm -rf src/Records/*.o

	@if [ -d bin ] ; \
		then rm -rf bin; \
	fi