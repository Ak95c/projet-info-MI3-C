# Nom de l'exécutable final


EXEC = projet_qcm

# Le compilateur à utiliser
CC = gcc

# Les options de compilation (pour afficher tous les avertissements et aider au débogage)
CFLAGS = -Wall -Wextra -g

# La liste de tous les fichiers objets nécessaires (un par fichier .c)
OBJ = main.o teacher.o student.o quiz_io.o

# Règle principale : comment créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règle générique : comment créer un .o à partir d'un .c
%.o: %.c prototypes.h
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tout nettoyer (pratique avant de rendre le projet)
clean:
	rm -f *.o $(EXEC)

#projet_qcm: main.c teacher.c student.c quiz_io.c
	#gcc main.c teacher.c student.c quiz_io.c -o projet_qcm


