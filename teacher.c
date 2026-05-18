#include "prototypes.h" // Inclut les structures et la constante TEACHER_PASSWORD

void run_teacher_mode(Quiz *newquiz) { // La fonction appelée par le menu principal
    
    char password_attempt[MAX_TEXT]; // Crée une variable pour stocker le mot de passe tapé par l'utilisateur

    printf("\n=== TEACHER MODE ===\n"); // Affiche le titre du mode
    printf("Enter teacher password: "); // Demande de taper le mot de passe
    
    scanf("%s", password_attempt); // Lit le mot de passe tapé (sans espace) et le sauvegarde dans password_attempt

    // strcmp compare deux textes. Si le résultat est différent de 0, les textes ne sont pas identiques
    if (strcmp(password_attempt, TEACHER_PASSWORD) != 0) { 
        printf("Access denied. Incorrect password.\n"); // Affiche un message d'erreur
        return; // Stoppe la fonction immédiatement et retourne au main.c
    }

    // Si on arrive ici, c'est que le mot de passe était correct
    printf("Access granted! Welcome, Teacher.\n");

    // --- LA SUITE DU TRAVAIL DE LA PERSONNE 1 COMMENCE ICI ---
    // Il faudra créer une variable de type Quiz (ex: Quiz new_quiz;)
    // Et faire des printf/scanf pour demander le titre, le mode séquentiel, les questions, etc.

int i ;
printf ("Attention dans les passages où du texte sera demandé quand vous sauter une ligne ce sera considéré comme la fin du texte.\n") ;
printf ("Quel est le titre du quiz ? \n") ;
scanf (" %255[^\n]", newquiz->title) ;
do {
printf ("Voulez vous qu'il y ait des points négatifs ? Répondez par oui (avec 1) ou par non (avec 0).\n") ;
scanf ("%d", &newquiz->negative_points) ;
} while (newquiz->negative_points != 0 && newquiz->negative_points != 1) ;
do {
printf ("Voulez vous que ce quiz soit séquentiel ? Répondez par oui (avec 1) ou par non (avec 0).\n") ;
scanf ("%d", &newquiz->sequential_mode) ;
} while (newquiz->sequential_mode != 0 && newquiz->sequential_mode != 1) ;
do {
printf ("Combien voulez vous de questions dans ce quiz ?\n") ;
scanf ("%d", &newquiz->nb_questions) ;
} while (newquiz->nb_questions < 0 || newquiz->nb_questions > 50) ;
do {
printf ("Voulez vous qu'il y ait des réponses multiples ? Répondez par oui (avec 1) ou par non (avec 0).\n") ;
scanf ("%d", &newquiz->multiple_answers) ;
} while (newquiz->multiple_answers != 0 && newquiz->multiple_answers != 1) ;
for (i = 0; i < newquiz->nb_questions; i++){
Question q ;
int j ;
printf("Entrez la question :\n");
scanf(" %255[^\n]", q.text);
for (j = 0; j < 4; j++) {
printf("Option %d :\n", j + 1);
scanf(" %255[^\n]", q.options[j]);
}
if (newquiz->multiple_answers == 0) {
int bonne;
do {
printf("Quelle est la bonne réponse ? (1-4)\n");
scanf("%d", &bonne);
} while (bonne < 1 || bonne > 4);
for (j = 0; j < 4; j++) {
q.correct_option[j] = 0;
}
q.correct_option[bonne - 1] = 1;
}
else {
printf("Entrez les bonnes réponses (1 = oui, 0 = non)\n");
for (j = 0; j < 4; j++) {
do {
printf("Option %d est correcte ? (1/0)\n", j + 1);
scanf("%d", &q.correct_option[j]);
} while (q.correct_option[j] != 0 && q.correct_option[j] != 1);
}
}
newquiz->list[i] = q ;
}
}
