CC = gcc
CFLAGS = -Wall -Wextra -pthread

sync_car: sync_car.c sync_car-runner.c sync_car.h
	$(CC) $(CFLAGS) -o sync_car sync_car.c sync_car-runner.c

clean:
	rm -f sync_car *.o