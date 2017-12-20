#include <stdio.h>
#include <stdlib.h>

struct Skier {

    int id;
    char firstName[50];
    char lastName[50];
    char club[50];

};

int addParticipant (int number) {

    FILE *fp;
    fp = fopen("STARTFIL.DAT", "w+");

    struct Skier participant;
    printf("::::  Anmälan till 30km  ::::\n");
    participant.id = number;

    printf("      Förnamn  : ");
    scanf("%s", &participant.firstName);

    printf("      Efternam : ");
    scanf("%s", &participant.lastName);

    printf("      Klubb    : ");
    scanf("%s", &participant.club);

    fprintf(fp, "%i:%s:%s:%s", participant.id, participant.firstName, participant.lastName, participant.club);
    printf("\n");

    fclose(fp);
    return 0;
}

int main () {

    int input, participantInput;
    int distance = 30000, participants = 0, maxParticipants = 42;

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
                    scanf("%i", &participantInput);
                    printf("\n");

                    switch (participantInput) {
                        case 1:
                            if (participants < maxParticipants ){
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

                } while(participantInput != 0);

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

    return 0;
}