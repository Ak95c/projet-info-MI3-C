#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_TEXT 256
#define MAX_OPTIONS 4

typedef struct {
    char questionText[MAX_TEXT];        // Le texte de la question
    char options[MAX_OPTIONS][MAX_TEXT]; // Les nchoix qui sont possibles: A, B, C, D
    int correctAnswers[MAX_OPTIONS];    // Tableau de 0 ou 1 (ex: {1, 0, 1, 0} si A et C sont vrais)
} Question;

typedef struct {
    char quizName[MAX_TEXT];
    int hasNegativePoints; // Paramètre : points négatifs [cite: 863]
    int isSequential;      // Paramètre : mode séquentiel 
    int multipleAnswers;   // Paramètre : plusieurs réponses vraies 
    int nbQuestions;
    Question list[50];     // Liste des questions chargées en mémoire [cite: 883]
} Quiz;

#endif
