# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRCS = main.c double_stack.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -std=c11 -g
# Regla por defecto: compilar todo
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regla para compilar main.o
main.o: main.c double_stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Regla para compilar double_list.o
double_list.o: double_stack.c double_stack.h
	$(CC) $(CFLAGS) -c double_stack.c -o double_stack.o

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)




# Indicar que estas reglas no son archivos
.PHONY: all clean
                  
