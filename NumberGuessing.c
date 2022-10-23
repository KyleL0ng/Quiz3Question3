#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int menu();
int randomChoice(int max);

int main()
{
    int menuChoice = 0;
    int maxNum = 10;
    int randNum = 0;
    int userNum = 0;
    bool cont = true;
    // print menu and get user's choice (done within loop)
    printf("Welcome to Guess a Number!\n\n");

    // If 1: play game
    //   pick number
    //   get guess
    //   high/low
    //   repeat until successful
    // If 2: change max number
    // If 3: end
    while (cont)
    {
        menuChoice = menu();
        switch (menuChoice)
        {
        case 1:
            randNum = randomChoice(maxNum);
            while (userNum != randNum)
            {
                printf("Enter your guess:\n");
                scanf("%d", &userNum);
                printf("You guessed: %d\n", userNum);
                if (userNum == randNum)
                {
                    printf("Correct!\n");
                }
                else
                {
                    if (userNum < randNum)
                    {
                        printf("The number is higher\n");
                    }
                    else if (userNum > randNum)
                    {
                        printf("The number is lower\n");
                    } // end if
                } // end if
            } // end while
            break;
        case 2:
            printf("Enter new max number:\n");
            scanf("%d", &maxNum);
            printf("The new max number is: %d\n", maxNum);
            break;
        case 3:
            cont = false;
            printf("Thank you for playing!\n");
            break;
        } //end switch
    } //end while

    return EXIT_SUCCESS;
}

int menu()
{
    int choice = 0;
    bool valid = false;

    while (!valid)
    {
        switch (choice)
        {
        case 1:
            valid = true;
            break;
        case 2:
            valid = true;
            break;
        case 3:
            valid = true;
            break;
        default:
            valid = false;
            printf("Press 1 to play a game\n");
            printf("Press 2 to change the max number\n");
            printf("Press 3 to quit\n");
            scanf("%d", &choice);
            break;
        }
    }

    return choice;
}

int randomChoice(int max)
{
    time_t t;
    srand((unsigned)time(&t));

    int randomNum = rand() % max;
    randomNum = randomNum + 1;
    return randomNum;
}
