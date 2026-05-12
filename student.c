#include "prototypes.h"

// Fonction principale du mode étudiant
void run_student_mode() {
    
    printf("\n=== STUDENT MODE ===\n");
    printf("This section is under construction...\n");
    
    // La Personne 2 écrira toute sa logique ici plus tard
    // (affichage des questions, calcul du score, etc.)
    //coquile vide histoire de pouvoir faire un test a modifier juste apres
    
}
#include "prototypes.h"

void run_student_mode() {
    Quiz q = load_quiz_from_file(); // On charge le quiz que le prof a créé
    int score = 0;
    int user_answer;

    printf("\n--- BIENVENUE DANS LE QUIZ: %s ---\n", q.title);

    for (int i = 0; i < q.nb_questions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, q.list[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q.list[i].options[j]);
        }

        printf("votre réponse (1-4): ");
        scanf("%d", &user_answer);

        if (user_answer == q.list[i].correct_option) {
            printf("Correct!\n");
            score++; // On gagne 1 point
        } else {
            printf("FAUX La bonne réponse était: %d.\n", q.list[i].correct_option);
            // Si le prof a activé les points négatifs, on retire 1 point
            if (q.negative_points == 1) {
                score--;
            }
        }

        // Si le mode séquentiel est activé, on prévient l'élève qu'il ne peut pas revenir en arrière
        if (q.sequential_mode == 1) {
            printf("[System] Sequential mode active: Answer locked.\n");
        }
    }

    printf("\n--- SCORE FINAL: %d/%d ---\n", score, q.nb_questions);
}
