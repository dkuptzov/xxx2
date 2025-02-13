CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS = dmanager_module.c
QUEST1 = Quest_1

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

door_struct: $(LIBS)
        $(CC) $(CFLAGS) $^ -o $(QUEST1)

.PHONY: clean

clean:
        rm -rf $(QUEST1)
