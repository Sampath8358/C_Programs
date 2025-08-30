#include <stdio.h>

int main() {
    int pass = 1234;
    int PassUser;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter your password: ");
        scanf("%d", &PassUser);

        if (PassUser == pass) {
            printf("Password is correct\n");
            return 0;  // Exit program
        } else {
            attempts++;
                printf("Password is invalid\n");
                printf("You have %d attempts left\n", 3 - attempts);
        }
    }
    printf("Your account is blocked\n");
    return 0;
}
