#include "prototypes.h" // Inclut les structures et la constante TEACHER_PASSWORD

void run_teacher_mode() { // La fonction appelée par le menu principal
    
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

}
