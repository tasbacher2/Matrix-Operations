#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h> 
#include "operations.h"

/* 

Matrix Operations

Description:

TODO:
create an interactive menu
    -implement menu item: display
    -implement menu item: transpose
    -implement menu item: addition
    -implement menu item: subtraction
    -implement menu item: multiplication
    -implement menu item: exit
implement inverse function


*/

int main(){

    struct Matrix m[10];
    int selection = 0, valid = 0, counter = 0, index = -1, displayOption = -1;
    char c;

    for (int i = 0; i < 10; i++){
        m[i].active = false;
    }

    while (selection != 9){
        selection = 0;
        valid = 0;
        c = ' ';

        printf("Welcome to the Matrix Calculator.\n"); 
        printf("please select an option number:\n");
        printf("1. Create a new matrix.\n");
        printf("2. Delete a matrix.\n");
        printf("3. Display Matricies.\n");
        printf("4. Transpose a Matrix.\n");
        printf("5. Matrix Addition.\n");
        printf("6. Matrix Subtraction.\n");
        printf("7. Matrix Multiplication.\n");
        printf("8. Matrix inverse.\n");
        printf("9. Exit Program.\n");
        printf("Enter Selection: ");

        while (selection < 1 || selection > 9){
            valid = scanf("%d", &selection);
            if (selection < 1 || selection > 9 || valid ==0){
                printf("Invalid selection, please enter an option (1-8): ");
            }
            fflush(stdin);
        }

        if (selection == 1){
            printf("\nYou've selected create.\n\n");
            if (counter >= 10){
                printf("You have too many matricies stored, please delete one before creating another.\n");
            }
            else{
                counter += 1;
                for (int i = 0; i < 10; i++){
                    if (m[i].active == 0){
                        index = i;
                        break;
                    }
                }
                getMatrix(&m[index]);
            }
            fflush(stdin);
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 2){
            printf("\nYou've selected delete.\n\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 3){
            fflush(stdin);
            printf("\nYou've selected display.\n\n");
            //printf("Error 404 no functionality found.\n\n");
            printf("Which matrix number would you like to display 1-10 (Enter 0 to display all): ");
            while (displayOption < 0 || displayOption > 10){
                valid = scanf("%d", &displayOption);
                if (displayOption < 0 || displayOption > 10 || valid == 0){
                    printf("Incorrect input, please enter the number of rows (max 20): ");
                }
                fflush(stdin);
            }
            if (displayOption == 0){
                for (int i = 0; i < 10; i++){
                    if (m[i].active == 1){
                        printf("Matrix %d: \n", i + 1);
                        display(&m[i]);
                    }
                }
            }
            else{
                if (m[displayOption - 1].active == 1) {
                    printf("Matrix %d: \n", displayOption);
                    display(&m[displayOption - 1]);
                }
                else{
                    printf("Matrix %d does not exist.\n", displayOption);
                }
            }
            displayOption = -1;
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 4){
            printf("\nYou've selected transpose.\n\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 5){
            printf("\nYou've selected addition.\n\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 6){
            printf("\nYou've selected subtraction.\n\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 7){
            printf("\nYou've selected multiplication.\n\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 8){
            printf("\nYou've selected Inverse.\n");
            printf("Error 404 no functionality found.\n\n");
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else {
            printf("\nAre you sure you want to exit? Y|N: ");
            while (toupper(c) != 'Y' && toupper(c) != 'N'){
                scanf("%c", &c);
                if (toupper(c) != 'Y' && toupper(c) != 'N'){
                    printf("Incorrect input, please enter a valid option (Y|N): ");
                    fflush(stdin);
                }
                else{
                    if (toupper(c) == 'N'){
                        selection = 0;
                    }
                }
            }
        }
        
    }
    for (int i = 0; i < 10; i++){
        if (m[i].active == 1){
            printf("Freeing Matrix %d\n", i + 1);
            freeMatrix(&m[i]);
        }
    }
    //build matrix with input from user
    //getMatrix(&m1);
    //getMatrix(&m2);

    //print matrix
    //display(&m1);

    //find the sum of each row
    //sumrows(&m1);

    //find the sum of each column
    //sumcolumns(&m1);

    //find the sum of the main diagonal of a square matrix
    //sumMainDiagonal(&m1);

    //transpose matrix
    //getTranspose(&m1, &transpose);

    //display(&transpose);

    //getSum(&m1, &m2, &m3);
    //getDifference(&m1, &m2, &m3);
    //getProduct(&m1, &m2, &m3);
    //display(&m3);

    //freeMatrix(&m1);
    //freeMatrix(&m2);
    //freeMatrix(&m3);
    //freeMatrix(&transpose);

    return 0;
}

