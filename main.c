#include <stdio.h>
#include <stdlib.h>

struct Skier {

    int id;
    char firstName[50];
    char lastName[50];
    char club[50];

};

int addParticipant (int number) {
    struct Skier participant;
    printf("::::  Anmälan till 30km  ::::\n");

    /*
    participant.id = number;

    printf("        Förnamn  : ");
    scanf("%c\n", &participant.firstName);

    printf("        Efternam : ");
    scanf("%c\n", &participant.lastName);

    printf("        Klubb    : ");
    scanf("%c\n", &participant.club);
    */
    
    printf("\n");
    return 0;
}

int main () {

    int input, addSkier;
    int distance = 30000, participants = 0;

    do {
        printf(":::::::::::::::::::::\n");
        printf(":::  SKIDTÄVLING  :::\n");
        printf("1. Nollställ för en ny tävling\n");
        printf("2. Registera deltagare\n");
        printf("3. Lotta startordning\n");
        printf("4. Registera åktider\n");
        printf("5. Visa osorterade resultat\n");
        printf("6. Visa sorterade resultat\n");
        printf("0. Avsluta program\n");
        printf("\nVälj val: ");
        scanf("%i", &input);
        printf("\n");


        switch (input) {

            case 1:

                break;

            case 2:
                do {
                    printf("::::::::::::::::::::\n");
                    printf("::: Registrering :::\n");
                    printf("1. Ny åkare\n");
                    printf("0. Avsluta registrering\n");
                    printf("\nVälj val: ");
                    scanf("%i", &addSkier);
                    printf("\n");

                    switch (addSkier) {
                        case 1:

                            if (participants <= 43 ){
                                participants += 1;
                                addParticipant(participants);
                            }

                            else {
                                printf("Maximalt antal deltagare registrerade");
                            }
                            break;

                        case 0:
                            printf("Avslutar registrering...");
                            break;

                        default:
                            break;
                    }

                } while(addSkier != 0);

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

    /*
     FILE *fp;

    fp = fopen("test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
     */

    return 0;
}