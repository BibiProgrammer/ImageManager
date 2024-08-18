TARGET = ImageManager.out
SOURCES = $(wildcard src/*.cpp)
INCLUDE = $(wildcard src/include)


$(TARGET): $(SOURCES)
ifeq ($(OS),Windows_NT)
	g++ -o $ImageManager.exe $(SOURCES) -I $(INCLUDE) `pkg-config --cflags --libs opencv`
else
	g++ -o $(TARGET) $(SOURCES) -I $(INCLUDE) `pkg-config --cflags --libs opencv`
endif

install:
	make
ifeq ($(OS), Windows_NT)
	windows_install.bat
else
	cp ./$(TARGET) /usr/local/bin/ImageManager
endif