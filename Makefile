CC = g++
CFLAGS = -Wall
LDFLAGS =
#SRCS = main.cpp hotel.cpp chambre.cpp reservation.cpp
SRCS = $(wildcard *.cpp)
#OBJFILES = main.o hotel.o chambre.o reservation.o
OBJFILES = $(SRCS:.cpp=.o)
TARGET = exe_hotel

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<

clean:
	rm -f $(OBJFILES) $(TARGET)

cleanobj:
	rm -f $(OBJFILES)

depend:
	makedepend -I. $(SRCS)

exe: $(TARGET)
	./$(TARGET)

# DO NOT DELETE
