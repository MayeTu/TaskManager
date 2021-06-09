CFLAGS=-c -Wall -Wextra -Wpedantic

all: taskManager

taskManager: main.o Manager.o Employee.o Task.o
	g++ main.o Manager.o Employee.o Task.o -o taskManager

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

Manager.o: Manager.cpp
	g++ $(CFLAGS) Manager.cpp

Employee.o: Employee.cpp
	g++ $(CFLAGS) Employee.cpp
	
Task.o: Task.cpp
	g++ $(CFLAGS) Task.cpp

clean:
	rm -rf *.o taskManager
