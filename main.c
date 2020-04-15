#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h> 
#include "operations.h"

/* 

Matrix Operations

Description:

TODO:
better input validation for matrix data
create an interactive menu
    -implement menu item: transpose
    -implement menu item: addition
    -implement menu item: subtraction
    -implement menu item: multiplication
    -implement menu item: exit
implement inverse function


*/

int main(){

    struct Matrix m[10];
    int selection = 0, valid = 0, counter = 0, index = -1, option = -1, option2 = -1;
    char c;

    for (int i = 0; i < 10; i++){
        m[i].active = false;
    }

    while (selection != 9){
        fflush(stdin);
        selection = 0;
        valid = 0;
        c = ' ';
        index = 0;
        option = -1;
        option2 = -1;

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
                printf("Invalid selection, please enter an option (1-9): ");
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
            printf("Which matrix number would you like to delete 1-10 (Enter 0 to return to menu): ");
            while (option < 0 || option > 10){
                valid = scanf("%d", &option);
                if (option < 0 || option > 10 || valid == 0){
                    printf("Incorrect input, please select a matrix to delete (or select 0 to go back to menu): ");
                }
                fflush(stdin);
            }
            if (option != 0){
                printf("Are you sure you want to delete Matrix %d? Y|N: ", option);
                while (toupper(c) != 'Y' && toupper(c) != 'N'){
                    scanf("%c", &c);
                    if (toupper(c) != 'Y' && toupper(c) != 'N'){
                        printf("Incorrect input, please enter a valid option (Y|N): ");
                        fflush(stdin);
                    }
                    else{
                        if (toupper(c) == 'Y'){
                            m[option-1].active = 0;
                            freeMatrix(&m[option-1]);
                        }
                    }
                }
                printf("Press Enter to return to menu...");
                scanf("%c", &c);
            }
            option = -1;
        }
        else if (selection == 3){
            printf("\nYou've selected display.\n\n");
            printf("Which matrix number would you like to display 1-10 (Enter 0 to display all): ");
            while (option < 0 || option > 10){
                valid = scanf("%d", &option);
                if (option < 0 || option > 10 || valid == 0){
                    printf("Incorrect input, please select a matrix (1-10): ");
                }
                fflush(stdin);
            }
            if (option == 0){
                for (int i = 0; i < 10; i++){
                    if (m[i].active == 1){
                        printf("Matrix %d: \n", i + 1);
                        display(&m[i]);
                    }
                }
            }
            else{
                if (m[option - 1].active == 1) {
                    printf("Matrix %d: \n", option);
                    display(&m[option - 1]);
                }
                else{
                    printf("Matrix %d does not exist yet.\n", option);
                }
            }
            option = -1;
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 4){
            printf("\nYou've selected transpose.\n\n");
            if (counter >= 10){
                printf("The Transpose function requires an empty matrix slot.\n");
                printf("You have too many matricies stored, please delete one before creating another.\n");
            }
            else{
                printf("Which matrix number would you like to Transpose 1-10 (Enter 0 to return to menu): ");
                while (option < 0 || option > 10){
                    valid = scanf("%d", &option);
                    if (option < 0 || option > 10 || valid == 0){
                        printf("Incorrect input, please select a matrix to Transpose (or select 0 to go back to menu): ");
                    }
                    fflush(stdin);
                }
                if (option != 0){
                    if (m[option - 1].active){
                        counter += 1;
                        for (int i = 0; i < 10; i++){
                            if (m[i].active == 0){
                                index = i;
                                break;
                            }
                        }
                        getTranspose(&m[option-1], &m[index]);
                        printf("Matrix %d Transpose has been stored in Matrix %d\n", option, index + 1);
                    }
                    else{
                        printf("Matrix %d does not exist yet.\n", option);
                    }
                }
                option = -1;
            }
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
        }
        else if (selection == 5){
            printf("\nYou've selected addition.\n\n");
            if (counter >= 10){
                printf("The Addition function requires an empty matrix slot.\n");
                printf("You have too many matricies stored, please delete one before creating another.\n");
            }
            else{
                printf("Please select the first Matrix to add (1-10) (Enter 0 to return to menu): ");
                while (option < 0 || option > 10){
                    valid = scanf("%d", &option);
                    if (option < 0 || option > 10 || valid == 0){
                        printf("Incorrect input, please select a matrix for Addition (or select 0 to go back to menu): ");
                    }
                    fflush(stdin);
                }
                printf("Please select the second Matrix to add (1-10) (Enter 0 to return to menu): ");
                while (option2 < 0 || option2 > 10){
                    valid = scanf("%d", &option2);
                    if (option2 < 0 || option2 > 10 || valid == 0){
                        printf("Incorrect input, please select a matrix for Addition (or select 0 to go back to menu): ");
                    }
                    fflush(stdin);
                }
                if (m[option-1].active == 1 && m[option2-1].active == 1){
                    if (m[option-1].rows == m[option2-1].rows && m[option-1].cols == m[option2-1].cols){
                        counter += 1;
                        for (int i = 0; i < 10; i++){
                            if (m[i].active == 0){
                                index = i;
                                break;
                            }
                        }
                        getSum(&m[option-1], &m[option2-1], &m[index]);
                        printf("The sum of Matrix %d and Matrix %d has been stored in Matrix %d\n", option, option2, index + 1);
                    }
                    else{
                        printf("Error, Matrix dimensions must match for addition.\n");
                    }
                }
                else{
                    printf("One of the selected Matricies does not exist.\n");
                    printf("Matrix Addition requires two existing matricies.\n");
                }
            }
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
            option = -1;
            option2 = -1;
        }
        else if (selection == 6){
            printf("\nYou've selected subtraction.\n\n");
            if (counter >= 10){
                printf("The Subtraction function requires an empty matrix slot.\n");
                printf("You have too many matricies stored, please delete one before creating another.\n");
            }
            else{
                printf("Please select the first Matrix to subtract from (1-10) (Enter 0 to return to menu): ");
                while (option < 0 || option > 10){
                    valid = scanf("%d", &option);
                    if (option < 0 || option > 10 || valid == 0){
                        printf("Incorrect input, please select a matrix for subtraction (or select 0 to go back to menu): ");
                    }
                    fflush(stdin);
                }
                printf("Please select the second Matrix to subtract (1-10) (Enter 0 to return to menu): ");
                while (option2 < 0 || option2 > 10){
                    valid = scanf("%d", &option2);
                    if (option2 < 0 || option2 > 10 || valid == 0){
                        printf("Incorrect input, please select a matrix for subtraction (or select 0 to go back to menu): ");
                    }
                    fflush(stdin);
                }
                if (m[option-1].active == 1 && m[option2-1].active == 1){
                    if (m[option-1].rows == m[option2-1].rows && m[option-1].cols == m[option2-1].cols){
                        counter += 1;
                        for (int i = 0; i < 10; i++){
                            if (m[i].active == 0){
                                index = i;
                                break;
                            }
                        }
                        getDifference(&m[option-1], &m[option2-1], &m[index]);
                        printf("The difference of Matrix %d and Matrix %d has been stored in Matrix %d\n", option, option2, index + 1);
                    }
                    else{
                        printf("Error, Matrix dimensions must match for subtration.\n");
                    }
                }
                else{
                    printf("One of the selected Matricies does not exist.\n");
                    printf("Matrix Subtraction requires two existing matricies.\n");
                }
            }
            printf("Press Enter to return to menu...");
            scanf("%c", &c);
            option = -1;
            option2 = -1;
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
    return 0;
}

