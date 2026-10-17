#include <stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int is_prime(int n);
float calculate_CGPA(float grades[], int count);
void show_ConfigMenu();


int main()
{
    int choice;

    printf("========================================\n");
    printf("           Welcome to MATHBOT\n");
    printf("========================================\n");
    printf("Hello! I am MathBot.\n");
    printf("I am your personal mathematical\n");
    printf("assistant.\n");
    printf("What can I help you calculate today?\n");

    do{
        printf("\n============== MAIN MENU ==============\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Prime Number Checker\n");
        printf("6. CGPA Calculator\n");
        printf("0. Configuration\n");
        printf("7. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                float a, b;
                printf("\nADDITION\n");
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Answer = %.2f\n", add(a, b));
                printf("\n");
                break;
            }

            case 2: {
                float a, b;
                printf("\nSubtraction\n");
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Answer = %.2f\n", subtract(a, b));
                printf("\n");
                break;
            }

            case 3: {
                float a, b;
                printf("\nMultiplication\n");
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Answer = %.2f\n", multiply(a, b));
                printf("\n");
                break;
            }

            case 4: {
                float a, b;
                printf("\nDivision\n");
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);

                if(b==0)
                {
                    printf("MathBot cannot divide by zero!\n");
                }
                else
                {
                    printf("Answer = %.2f\n", divide(a, b));
                }
                printf("\n");
                break;
            }

            case 5: {
                int n;
                printf("\nPrime Number Checker\n");
                printf("Enter an integer: ");
                scanf("%d", &n);

                if(is_prime(n))
                {
                    printf("%d is a prime number.\n", n);
                }
                else
                {
                    printf("%d is not a prime number!\n", n);
                }
                printf("\n");
                break;
            }

            case 6: {
                int n;
                printf("\nCGPA Calculator\n");
                printf("Enter the number of courses: ");
                scanf("%d", &n);

                float grades[100];
                for(int i=0; i<n; i++){
                    printf("Enter grade point for course %d: ", i+1);
                    scanf("%f", &grades[i]);
                }

                float average = calculate_CGPA(grades, n);
                printf("Calculated CGPA = %.2f\n", average);
                printf("\n");
                break;
            }

            case 0: {
                int password;
                printf("========================================\n");
                printf("              Configuration\n");
                printf("========================================\n");
                printf("Enter configuration password: ");
                while (1){
                    if(scanf("%d", &password) != 1){
                        printf("Invalid input. Try again: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if(password == 1234){
                        printf("\n");
                        printf("Access Granted!");
                        printf("\n");
                        show_ConfigMenu();
                        break;
                    }
                    else {
                        printf("Incorrect password!\n");
                        printf("Try again: ");
                    }
                }
                break;
            }

            case 7: {
                printf("\nExiting MathBot...\n");
                printf("\n========================================\n");
                printf("Thank you for using MathBot!\n");
                printf("Goodbye! Keep calculating!\n");
                break;
            }
             default:
                printf("Invalid choice! Please select between 0 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}




float add(float a, float b){
    return a+b;
}

float subtract(float a, float b){
    return a-b;
}

float multiply(float a, float b){
    return a*b;
}

float divide(float a, float b){
    return a/b;
}

int is_prime(int n){
    if(n<=1){
        return 0;
    }
    for (int i=2; i<n; i++)
    {
        if(n%i==0){
            return 0;
        }
    }
return 1;
}

float calculate_CGPA(float grades[], int count){
    float sum = 0.0;
    for (int i=0; i<count; i++)
    {
        sum += grades[i];
    }
    return sum / count;
}

void show_ConfigMenu(){
    int ConfigChoice;

    do{
        printf("\n============== Configuration ==============\n");
        printf("1. Bot information\n");
        printf("2. Return to main menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

    if(scanf("%d", &ConfigChoice) != 1){
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');
        ConfigChoice = 0;
        continue;
    }

    switch (ConfigChoice){
        case 1:
        printf("\n========== BOT INFORMATION ==========\n");
        printf("Name: MathBot\n");
        printf("Version: 1.0\n");
        printf("Purpose: Mathematical Assistant\n");
        printf("\n");
        printf("Available functions:\n");
        printf("- Addition\n");
        printf("- Subtraction\n");
        printf("- Multiplication\n");
        printf("- Division\n");
        printf("- Prime Number Checker\n");
        printf("- CGPA Calculator\n");
        printf("========================================\n");
        break;

        case 2:
        printf("\n");
        printf("Returning to main menu...\n");
        break;

        default:
        printf("Invalid choice! Please select 1 or 2.\n");
        break;
        }
        } while (ConfigChoice != 2);
}
