#include "prototypes.h"

void run_student_mode() {
    char quiz_name[MAX_TEXT];
    char filename[MAX_TEXT];
    int score = 0;
    int user_answer;

    // Affiche la liste des quiz disponibles
    list_available_quizzes();

    printf("Entrez le nom du QCM que vous voulez passer : ");
    scanf(" %255[^\n]", quiz_name);

    // Construit le nom du fichier en ajoutant .txt au nom saisi
    snprintf(filename, sizeof(filename), "%.251s.txt", quiz_name);

    Quiz q = load_quiz_from_file(filename);

    // Verifie que le quiz contient bien des questions
    if (q.nb_questions == 0) {
        printf("Erreur : ce QCM est vide ou n'existe pas.\n");
        return;
    }

    printf("\n--- BIENVENUE DANS LE QUIZ : %s ---\n", q.title);

    for (int i = 0; i < q.nb_questions; i++) {
        printf("\nQuestion %d : %s\n", i + 1, q.list[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q.list[i].options[j]);
        }

        // Verifie que la saisie est entre 1 et 4
        do {
            printf("Votre reponse (1-4) : ");
            scanf("%d", &user_answer);
        } while (user_answer < 1 || user_answer > 4);

        // user_answer - 1 convertit de 1-4 vers l'index tableau 0-3
        if (q.list[i].correct_option[user_answer - 1] == 1) {
            printf("Bonne reponse !\n");
            score++;
        } else {
            printf("Mauvaise reponse !\n");
            if (q.negative_points == 1) {
                score--; // Point negatif si le parametre est active
            }
        }

        if (q.sequential_mode == 1) {
            printf("[Systeme] Mode sequentiel actif : passage a la question suivante.\n");
        }
    }

    printf("\n--- SCORE FINAL : %d/%d ---\n", score, q.nb_questions);
}
