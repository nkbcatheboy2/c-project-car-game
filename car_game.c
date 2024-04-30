#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Function to generate random numbers
int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    int carPosition = 10; // Initial position of the car
    int score = 0; // Initial score of the player
    int obstaclePosition = 0; // Initial position of the obstacle
    int speed = 0; // Initial speed of the game
    int level = 1; // Initial level of the game

    srand(time(NULL)); // Seed the random number generator

    while (1) // Infinite game loop
    {
        system("cls"); // Clear the console screen

        // Draw the game elements
        printf("Score: %d\tLevel: %d\n\n", score, level);
        printf("|");
        for (int i = 0; i < carPosition; i++)
            printf(" ");
        printf("0");
        for (int i = carPosition + 1; i < 50; i++)
            printf(" ");
        printf("|\n");
        printf("|");
        for (int i = 0; i < obstaclePosition; i++)
            printf(" ");
        printf("*");
        for (int i = obstaclePosition + 1; i < 50; i++)
            printf(" ");
        printf("|\n");

        // Move the car left or right
        if (kbhit()) // Check if a key has been pressed
        {
            char key = getch(); // Get the pressed key
            if (key == 'a' && carPosition > 0)
                carPosition--;
            else if (key == 'd' && carPosition < 49)
                carPosition++;
        }

        // Move the obstacle down and generate a new one
        obstaclePosition++;
        if (obstaclePosition >= 50)
        {
            obstaclePosition = 0;
            score++;
            speed++;
            if (score % 10 == 0)
                level++;
        }

        // Check if the car has collided with the obstacle
        if (obstaclePosition == carPosition)
        {
            system("cls"); // Clear the console screen
            printf("Game Over! Your score is: %d\n", score);
            break; // End the game loop
        }

        // Delay the game to control the speed
        int delay = 200 - speed;
        if (delay < 0)
            delay = 0;
        Sleep(delay);
    }

    return 0;
}
