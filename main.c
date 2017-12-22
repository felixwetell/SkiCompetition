#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


FILE *fp;

struct Skier {

    int  id;
    char firstName[50];
    char lastName[50];
    char club[50];

} participant;

int addParticipant (int number) {

   fp = fopen("ANMALAN.txt", "a");

    struct Skier participant;
    printf(":::::::::::::::::::::::::::::\n");
    printf("::::  Anmälan till 30km  ::::\n");
    participant.id = number;

    printf("      Förnamn  : ");
    scanf("%s", &participant.firstName);

    printf("      Efternam : ");
    scanf("%s", &participant.lastName);

    printf("      Klubb    : ");
    scanf("%s", &participant.club);

    fprintf(fp, "%i %s %s %s\n", participant.id, participant.firstName, participant.lastName, participant.club);
    printf("\n");

    fclose(fp);
    return 0;
}

// Checks if the array contains the number from the input variable
int duplicate(int array[42], int number){
    int answer = 0, i;

    for (i = 0; i < 43; i++) {
        if (array[i] == number) {
            answer = 1;
        }
    }
    return answer;
}

// Quicksort compare function
int cmpfunc (const void * a, const void * b) {
    return (* (int*) a - *(int*) b);
}

int main () {

    // Variables for case 2
    int input, participantInput, number;

    // Variables for case 3
    int max = 43, min = 1, i;
    int array[42];

    // Variables for case 4
    int registerInput, id;

    // Variables for case 5
    int result[42];

    // Variables for case 6

    int distance = 30000, participants, maxParticipants = 43;

    srand((int)time(NULL));

    do {
        printf("\n");
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

        usleep(200*1000);

        switch (input) {
            case 1:
                fp = fopen("ANMALAN.txt", "w");
                fclose(fp);

                fp = fopen("STARTFIL.txt", "w");
                fclose(fp);

                printf("::::::::::::::::::::::::\n");
                printf(":::  Listor rensade  :::\n");
                printf("::::::::::::::::::::::::\n");
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

                            fp = fopen("ANMALAN.txt", "r");
                            //extract character from file and store in chr
                            participants = 1;
                            number = getc(fp);
                            while (number != EOF)
                            {
                                //Count whenever new line is encountered
                                if (number == '\n')
                                {
                                    participants += 1;
                                }
                                //take next character from file.
                                number = getc(fp);
                            }
                            fclose(fp); //close file.

                            if (participants < maxParticipants) {
                                addParticipant(participants);
                            }

                            else {
                                printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
                                printf(":::  Max antal deltagare har registrerats  :::\n");
                                printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
                            }
                            break;

                        case 0:
                            printf("Avslutar registrering...");
                            printf("\n");
                            break;

                        default:
                            break;
                    }

                    usleep(200*1000);

                } while(participantInput != 0);

                break;

            case 3:

                /*
                 För att lotta startordningen på deltagarna kan vi hämta in alla information från filen
                 "ANMALAN.txt", stoppa in det i en array och se bara slumpa den.
                 */

                for (i = 1; i < 42; i++) {
                    number = rand() % max + min;

                    while (duplicate(array, number) == 1) {
                        number = rand() % max + min;
                    }
                    array[i] = number;
                }

                // Random piece of code, ignore
                //fseek(fp,(x-1)*sizeof(struct student),SEEK_SET);


                /*
                 Ny tanke, man kan bara slumpa en array med tal och sedan hämta ut informationen för
                 enskild deltagare som talet hamnar på. Det för att man inte behöver hämta in för mycket
                 information om den inte behövs.
                 */

                break;

            case 4:

                /*
                 Registrera deltagarnas tider, en tid per deltagare. 
                 */

                printf(":::::::::::::::::::::::::\n");
                printf(":::  Registera tider  :::\n");
                printf("1. Registrera tid på deltagare\n");
                printf("0. Avsluta\n");
                printf("\n");

                printf("Välj val: ");
                scanf("%i", &registerInput);
                printf("\n");


                do {

                    switch (registerInput) {
                        case 1:
                            fp = fopen("ANMALAN.txt", "r");

                            printf("Välj deltagare (startnummer): ");
                            scanf("%i", &id);

                            fseek(fp, (id)*sizeof(struct Skier),SEEK_SET);

                            if(fread(&participant, sizeof(struct Skier),1,fp) == 1)
                            {
                                printf("\n Startnumemr: ");
                                printf("%s\n", participant.id);
                                printf("\n Förnamn: ");
                                printf("%s\n", participant.firstName);
                                printf("\n Efternamn: ");
                                printf("%s\n", participant.lastName);
                                printf("\n Klubb: ");
                                printf("%s\n", participant.club);
                            }

                            fclose(fp);
                            break;

                        case 0:
                            printf("Avslutar registrering...\n");
                            break;
                        default:
                            break;
                    }

                } while (registerInput != 0);



                break;

            case 5:

                /*
                 Osorterad lista efter deltagarnas resultat
                 */

                break;

            case 6:

                /*
                 Sorterad lista efter deltagarnas resultat
                 */


                qsort(result, 42, sizeof(int), cmpfunc);

                break;

            case 0:
                printf("Stänger av program...");
            default:
                break;
        }
        usleep(200*1000);
    } while (input != 0);

    return 0;
}