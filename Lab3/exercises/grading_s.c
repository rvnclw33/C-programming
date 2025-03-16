#include <stdio.h>

int main() {
    int score;

    // Loop through each student's score
    while (scanf("%d", &score) != EOF) {
        if (score == -1) {
            break;  // Stop processing if score is negative
        }
        
        // Determine the grade based on the score
        if (score >= 80) {
            printf("excellent\n");
        } else if (score >= 70) {
            printf("good\n");
        } else if (score >= 60) {
            printf("satisfactory\n");
        } else if (score >= 50) {
            printf("pass\n");
        } else {
            printf("fail\n");
        }
    }

    return 0;
}
