#include "prototypes.h"

void run_student_mode() {
    Quiz q = load_quiz_from_file(); 
    int score = 0;
    int user_answer;

    printf("\n--- WELCOME TO QUIZ: %s ---\n", q.title);

    for (int i = 0; i < q.nb_questions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, q.list[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q.list[i].options[j]);
        }

        printf("Your answer (1-4): ");
        scanf("%d", &user_answer);

        // Note explicative : user_answer - 1 permet de vérifier la bonne case du tableau (0 à 3)
        if (q.list[i].correct_option[user_answer - 1] == 1) {
            printf("Correct!\n");
            score++; 
        } else {
            printf("Wrong answer!\n");
            if (q.negative_points == 1) {
                score--;
            }
        }

        if (q.sequential_mode == 1) {
            printf("[System] Sequential mode active: Answer locked.\n");
        }
    }

    printf("\n--- FINAL SCORE: %d/%d ---\n", score, q.nb_questions);
}
