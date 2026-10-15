CXX = g++

OPENCV_CFLAGS = $(shell pkg-config --cflags opencv5)
OPENCV_LIBS   = $(shell pkg-config --libs opencv5)

CXXFLAGS = -std=c++17 -Wall $(OPENCV_CFLAGS)

SRC = \
    DIP.cpp \
    Course_Lib/myHist.cpp \
	HW/ImageFlip.cpp 

TARGET = dip.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) $(OPENCV_LIBS) -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q $(TARGET) 2>nul

rebuild: clean all

.PHONY: all run clean rebuild