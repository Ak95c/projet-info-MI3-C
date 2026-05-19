#include "prototypes.h"

void save_quiz_to_file(Quiz q) {
    FILE *f = fopen("quiz.txt", "w"); // Ouvre le fichier en mode écriture
    if (f == NULL) return;

    // Enregistre l'entête du quiz
    fprintf(f, "%s %d %d %d %d\n", q.title, q.negative_points, q.sequential_mode, q.multiple_answers, q.nb_questions);

    // Enregistre chaque question
    for (int i = 0; i < q.nb_questions; i++) {
        fprintf(f, "%s\n", q.list[i].text);
        fprintf(f, "%s %s %s %s\n", q.list[i].options[0], q.list[i].options[1], q.list[i].options[2], q.list[i].options[3]);
        fprintf(f, "%d %d %d %d\n", q.list[i].correct_option[0], q.list[i].correct_option[1], q.list[i].correct_option[2], q.list[i].correct_option[3]);
    }
    fclose(f);
}

Quiz load_quiz_from_file() {
    Quiz q;
    FILE *f = fopen("quiz.txt", "r"); // Ouvre le fichier en mode lecture
    if (f == NULL) {
        q.nb_questions = 0;
        return q;
    }

    // Lit l'entête du quiz
    fscanf(f, "%s %d %d %d %d", q.title, &q.negative_points, &q.sequential_mode, &q.multiple_answers, &q.nb_questions);

    // Lit chaque question une par une
    for (int i = 0; i < q.nb_questions; i++) {
        fscanf(f, "%s", q.list[i].text);
        fscanf(f, "%s %s %s %s", q.list[i].options[0], q.list[i].options[1], q.list[i].options[2], q.list[i].options[3]);
        // Ligne corrigée ci-dessous :
        fscanf(f, "%d %d %d %d", &q.list[i].correct_option[0], &q.list[i].correct_option[1], &q.list[i].correct_option[2], &q.list[i].correct_option[3]);
    }
    fclose(f);
    return q;
}
}
