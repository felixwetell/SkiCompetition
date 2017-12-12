#include <stdio.h>
#include <stdlib.h>

struct Skier {

    int id;
    char firstName[50];
    char lastName[50];
    char club[50];

};

int main () {

    int distance = 30000, participants = 42;

    struct Skier participant;

    printf("::::    ANMÄLAN TILL 30KM    ::::\n");

    participant.id = 1;

    printf("        Förnamn  : ");
    scanf("%c\n", participant.firstName);

    printf("        Efternam : ");
    scanf("%c\n", participant.lastName);

    printf("        Klubb    : ");
    scanf("%c\n", participant.club);


    FILE *testFile;

    testFile = fopen("test.txt", "r");
    fprintf(testFile, participant.lastName);

    fclose(testFile);

    return 0;
}