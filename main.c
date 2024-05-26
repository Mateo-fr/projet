#include "play.h"

int main() {
    srand(time(NULL)); // Seed initialization for random number generation using the current time

    int choice = 0; // Variable to store user's choice

    // Loop until a valid choice (between 1 and 4) is entered
    do {
        #ifdef _WIN32
            homeScreenWin(); // Display the home screen
        #else 
            homeScreen();
        #endif

        printf("Enter your choice: \n"); // Prompt the user to enter a choice

        // Check if the input is a valid number
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. "); // Print an error message for invalid input
            while (getchar() != '\n'); // Clear the input buffer to discard incorrect inputs
            continue; // Continue the loop to prompt the user again
        }

        // Check if the choice is within the valid range
        if (choice < 1 || choice > 4) {
            printf("Invalid input. Choose valid option "); // Print an error message for out-of-range choice
            clearTerminal(); // Clear the terminal screen
        }
    } while (choice < 1 || choice > 4); // Repeat the loop if the choice is not between 1 and 4

    // Execute the corresponding action based on the user's choice
    switch (choice) {
        case 1:
            displayRules();
            break;
        case 2:
            printf("2"); // Print "2" if choice is 2
            break;
        case 3:
            printf("3"); // Print "3" if choice is 3
            break;
        case 4:
            play(); // Call the play function if choice is 4
            break;
        default:
            printf("Error with the choice"); // Print an error message if there is an unexpected issue with the choice
            exit(5); // Exit the program with an error code 5
            break;
    }

    return 0; // Return 0 to indicate successful execution
}