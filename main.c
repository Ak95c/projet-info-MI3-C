#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h" // Inclut ton fichier "prototypes.h" pour que le main connaisse tes structures et fonctions

int main() { // Début de la fonction principale (le point d'entrée de ton programme)
    
    int choice = 0; // Déclare une variable locale pour stocker le choix tapé au clavier (initialisée à 0)

    while (choice != 3) { // Lance une boucle qui se répète tant que l'utilisateur ne tape pas '3' (Quitter)
        
        printf("\n=== WELCOME TO THE QCM PROJECT ===\n"); // Affiche le titre du menu principal
        printf("1. Teacher Mode\n"); // Affiche l'option 1 à l'écran
        printf("2. Student Mode\n"); // Affiche l'option 2 à l'écran
        printf("3. Exit\n"); // Affiche l'option 3 à l'écran
        printf("Your choice: "); // Demande à l'utilisateur de taper son choix
        
        scanf("%d", &choice); // Lit le nombre tapé au clavier et le sauvegarde dans la variable 'choice'

        switch (choice) { // Vérifie la valeur de la variable 'choice' pour agir en fonction
            
            case 1: // Si l'utilisateur a tapé '1'
                run_teacher_mode(); // Appelle la fonction du mode enseignant (qui sera codée dans teacher.c)
                break; // Quitte le 'switch' pour éviter d'exécuter les cas suivants
                
            case 2: 
                run_student_mode(); // Appelle la fonction du mode étudiant (qui sera codée dans student.c)
                break; // Quitte le 'switch'
                
            case 3: 
                printf("Goodbye!\n"); // Affiche un message d'au revoir (la boucle while s'arrêtera juste après)
                break; // Quitte le 'switch'
                
            default: // Si l'utilisateur a tapé autre chose (ex: 4, 9, ou un nombre négatif)
                printf("Invalid choice, please try again.\n"); // Affiche un message d'erreur
                break; // Quitte le 'switch' et la boucle recommence
        }
    }

    return 0; // Termine le programme correctement en renvoyant 0 au système d'exploitation
}
