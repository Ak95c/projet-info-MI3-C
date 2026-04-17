#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes (Pre-processor)
#define MAX_TEXT 256
#define TEACHER_PASSWORD "CY2026"

// Structure pour une question
typedef struct {
    char text[MAX_TEXT];
    char options[4][MAX_TEXT];
    int correct_option; 
} Question;

// Structure pour le Quiz complet
typedef struct {
    char title[MAX_TEXT];
    int negative_points;    // Paramètre requis par le sujet
    int sequential_mode;    // Paramètre requis par le sujet
    int multiple_answers;   // Paramètre requis par le sujet
    int nb_questions;
    Question list[50];
} Quiz;

// Prototypes des fonctions (Noms en anglais)
void run_teacher_mode();
void run_student_mode();
void save_quiz_to_file(Quiz q);

#endif
