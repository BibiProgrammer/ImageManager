TARGET = ImageManager.out
SOURCES = $(wildcard src/*.cpp)
INCLUDE = $(wildcard src/include)


$(TARGET): $(SOURCES)
	g++ -o $(TARGET) $(SOURCES) -I $(INCLUDE) `pkg-config --cflags --libs opencv`

install:
	make
	cp ./$(TARGET) /usr/local/bin/ImageManager
