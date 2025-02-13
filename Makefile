CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS = dmanager_module.c
OBJECTS = $(LIBS:.c=.o)
QUEST1 = Quest_1

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

door_struct: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(QUEST1)


.PHONY: clean

clean: rm -f *.o $(QUEST1)
