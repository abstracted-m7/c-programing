#include <stdio.h>
#include <string.h>

typedef struct {
    char question[100];
    char options[4][50];
    int correctOption;
} Question;

int main() {
    Question quiz[3];
    
    strcpy(quiz[0].question, "What is the capital of France?");
    strcpy(quiz[0].options[0], "A. London");
    strcpy(quiz[0].options[1], "B. Paris");
    strcpy(quiz[0].options[2], "C. Rome");
    strcpy(quiz[0].options[3], "D. Madrid");
    quiz[0].correctOption = 1;

    strcpy(quiz[1].question, "Which planet is known as the Red Planet?");
    strcpy(quiz[1].options[0], "A. Earth");
    strcpy(quiz[1].options[1], "B. Mars");
    strcpy(quiz[1].options[2], "C. Jupiter");
    strcpy(quiz[1].options[3], "D. Venus");
    quiz[1].correctOption = 1;

    strcpy(quiz[2].question, "What gas do plants use for photosynthesis?");
    strcpy(quiz[2].options[0], "A. Nitrogen");
    strcpy(quiz[2].options[1], "B. Oxygen");
    strcpy(quiz[2].options[2], "C. Carbon Dioxide");
    strcpy(quiz[2].options[3], "D. Hydrogen");
    quiz[2].correctOption = 2;

    int score = 0;
    printf("Welcome to the Quiz Game!\n");

    for (int i = 0; i < 3; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        int userAnswer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &userAnswer);

        if (userAnswer == quiz[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", 'A' + quiz[i].correctOption - 1);
        }
    }

    printf("Quiz completed! Your score: %d/%d\n", score, 3);

    return 0;
}
