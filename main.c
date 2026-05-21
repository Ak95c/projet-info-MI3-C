#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

int main() {
int choice = 0;
Quiz q;
do {
printf("\n=== WELCOME TO THE QCM PROJECT ===\n");
printf("1. Teacher Mode\n");
printf("2. Student Mode\n");
printf("3. Exit\n");
printf("Your choice: ");

// Si scanf ne lit pas un nombre valide, on rentre dans le if    
    if (scanf("%d", &choice) != 1) {    
        printf("Invalid input! Please enter a number.\n");    
        // Cette petite ligne magique consomme la lettre bonus pour débloquer le clavier    
        while (getchar() != '\n');     
        choice = 0; // On réinitialise pour éviter la boucle infinie    
        continue;   // On recommence la boucle proprement    
    }    

    switch (choice) {    
        case 1:    
            run_teacher_mode(&q);    
            break;    
        case 2:    
            run_student_mode();    
            break;    
        case 3:    
            printf("Goodbye!\n");    
            break;    
        default:    
            printf("Invalid choice, please try again.\n");    
            break;    
    }    
} while (choice != 3) ;    
return 0;
}
