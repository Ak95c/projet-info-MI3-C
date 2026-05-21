#include "prototypes.h"

/* Sauvegarde le quiz dans un fichier nommé d'après son titre */
void save_quiz_to_file(Quiz q) {
    char filename[MAX_TEXT];
    sprintf(filename, "%.251s.txt", q.title); /* Limite la taille pour éviter un dépassement de mémoire */

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Erreur : impossible de créer le fichier.\n");
        return;
    }

    /* Ligne 1 : les 4 paramètres numériques du quiz */
    fprintf(f, "%d %d %d %d\n", q.negative_points, q.sequential_mode, q.multiple_answers, q.nb_questions);

    /* Pour chaque question : texte et 4 options chacun sur une ligne séparée */
    for (int i = 0; i < q.nb_questions; i++) {
        fprintf(f, "%s\n", q.list[i].text);
        fprintf(f, "%s\n", q.list[i].options[0]);
        fprintf(f, "%s\n", q.list[i].options[1]);
        fprintf(f, "%s\n", q.list[i].options[2]);
        fprintf(f, "%s\n", q.list[i].options[3]);
        fprintf(f, "%d %d %d %d\n",
            q.list[i].correct_option[0], q.list[i].correct_option[1],
            q.list[i].correct_option[2], q.list[i].correct_option[3]);
    }
    fclose(f);
    printf("Quiz sauvegardé dans : %s\n", filename);
}

/* Supprime le '\n' que fgets laisse à la fin d'une chaîne */
void supprimer_retour_ligne(char *chaine) {
    int i = 0;
    /* On parcourt la chaîne jusqu'à trouver le '\n' et on le remplace par '\0' */
    while (chaine[i] != '\0') {
        if (chaine[i] == '\n') {
            chaine[i] = '\0';
            return;
        }
        i++;
    }
}

/* Charge un quiz depuis un fichier dont on fournit le nom */
Quiz load_quiz_from_file(char *filename) {
    Quiz q;
    q.nb_questions = 0; /* Valeur par défaut si le fichier est introuvable */

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir %s\n", filename);
        return q;
    }

    /* Le titre = nom du fichier sans l'extension .txt */
    int i = 0;
    while (filename[i] != '.' && filename[i] != '\0') {
        q.title[i] = filename[i];
        i++;
    }
    q.title[i] = '\0'; /* On termine la chaîne proprement */

    /* Ligne 1 : les paramètres numériques */
    fscanf(f, "%d %d %d %d", &q.negative_points, &q.sequential_mode, &q.multiple_answers, &q.nb_questions);

    /* Vide le reste de la ligne (le '\n') pour que fgets parte du bon endroit */
    fgetc(f);

    /* Lecture de chaque question avec fgets pour gérer les espaces dans les textes */
    for (int i = 0; i < q.nb_questions; i++) {
        fgets(q.list[i].text, MAX_TEXT, f);
        supprimer_retour_ligne(q.list[i].text); /* Enlève le '\n' laissé par fgets */

        fgets(q.list[i].options[0], MAX_TEXT, f);
        supprimer_retour_ligne(q.list[i].options[0]);
        fgets(q.list[i].options[1], MAX_TEXT, f);
        supprimer_retour_ligne(q.list[i].options[1]);
        fgets(q.list[i].options[2], MAX_TEXT, f);
        supprimer_retour_ligne(q.list[i].options[2]);
        fgets(q.list[i].options[3], MAX_TEXT, f);
        supprimer_retour_ligne(q.list[i].options[3]);

        fscanf(f, "%d %d %d %d",
            &q.list[i].correct_option[0], &q.list[i].correct_option[1],
            &q.list[i].correct_option[2], &q.list[i].correct_option[3]);

        /* Vide le '\n' après les bonnes réponses avant la prochaine question */
        fgetc(f);
    }
    fclose(f);
    return q;
}

/* Affiche les 3 QCM disponibles dans l'application */
void list_available_quizzes() {
    printf("\n--- QCM disponibles ---\n");
    printf("  1. Culture_Generale\n");
    printf("  2. Mathematiques\n");
    printf("  3. Informatique\n");
    printf("-----------------------\n");
}
