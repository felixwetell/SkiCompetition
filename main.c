#include <stdio.h>
#include <stdlib.h>

struct Skier {

    int id;
    char firstName[50];
    char lastName[50];
    char club[50];

};

int main () {

    int input;
    int distance = 30000, participants = 42;

    do {
        printf(":::::::::::::::::::::\n");
        printf(":::  SKIDTÄVLING  :::\n");
        printf("1. Nollställ för en ny tävling\n");
        printf("2. Registera åkare\n");
        printf("3. Lotta startordning\n");
        printf("4. Registera åktider\n");
        printf("5. Visa osorterade resultat\n");
        printf("6. Visa sorterade resultat\n");
        printf("0. Avsluta program\n");
        printf("\n");
        printf("Välj val: ");
        scanf("%i", &input);
        printf("\n");

        switch (input) {

            case 1:
                
                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 0:
                input = 0;
                printf("Stänger av program...");
            default:
                break;
        }

    }while (input != 0);

    struct Skier participant;

    printf("::::    ANMÄLAN TILL 30KM    ::::\n");

    participant.id = 1;

    printf("        Förnamn  : ");
    scanf("%c\n", &participant.firstName);

    printf("        Efternam : ");
    scanf("%c\n", &participant.lastName);

    printf("        Klubb    : ");
    scanf("%c\n", &participant.club);

    /*
     FILE *fp;

    fp = fopen("test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
     */

    return 0;
}