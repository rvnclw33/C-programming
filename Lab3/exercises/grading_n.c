#include <stdio.h>

int main() {
    int n;
    
    // Read the number of students
    scanf("%d", &n);

    // Loop through each student's score
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);

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
