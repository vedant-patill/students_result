#include <stdio.h>

// Define a structure for Student
struct Student {
    int rollNo;
    char name[50];
    float marks[3];
    float total;
    float percentage;
    char grade;
};

int main() {
    int n, i, j;

    printf("Enter the number of students (max 100): ");
    scanf("%d", &n);

    struct Student students[100]; // Array of structures

    // Accepting details for each student
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        
        printf("Name: ");
        scanf("%s", students[i].name); // Note: scanf reads a single-word name without spaces

        students[i].total = 0;
        printf("Enter marks for 3 subjects:\n");
        for (j = 0; j < 3; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j]; // Accumulate total marks
        }

        // Calculate percentage (assuming each subject is out of 100)
        students[i].percentage = students[i].total / 3.0;

        // Determine grade based on percentage
        if (students[i].percentage >= 85) {
            students[i].grade = 'A';
        } else if (students[i].percentage >= 70) {
            students[i].grade = 'B';
        } else if (students[i].percentage >= 50) {
            students[i].grade = 'C';
        } else if (students[i].percentage >= 35) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F'; // Fail
        }
    }

    // Displaying the results in a formatted table
    printf("\n\n=================================================================\n");
    printf("                        STUDENT RESULT REPORT                    \n");
    printf("=================================================================\n");
    printf("%-10s %-20s %-10s %-12s %-6s\n", "Roll No", "Name", "Total", "Percentage", "Grade");
    printf("-----------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f %-11.2f%% %-6c\n", 
               students[i].rollNo, 
               students[i].name, 
               students[i].total, 
               students[i].percentage, 
               students[i].grade);
    }
    printf("=================================================================\n");

    return 0;
}