#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MATERIALS 14
#define MAX_LENGTH 200

typedef struct
{
    char material[MAX_LENGTH];
    int cost;
    int recyclability;
    char pros[MAX_LENGTH];
    char cons[MAX_LENGTH];
    char goodForRain[MAX_LENGTH];
    char goodForSummer[MAX_LENGTH];
    char goodForWinter[MAX_LENGTH];
} Packaging;

void toLowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void cleanInput(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

const char *getCostString(int cost)
{
    const char *costLevels[] = {"Unknown", "Low", "Medium", "High"};
    return (cost >= 1 && cost <= 3) ? costLevels[cost] : costLevels[0];
}

const char *getRecyclabilityString(int r)
{
    const char *levels[] = {"Unknown", "No", "Hard to recycle", "Yes"};
    return (r >= 1 && r <= 3) ? levels[r] : levels[0];
}

void displayMaterialInfo(Packaging *options, int size, const char *userChoice)
{
    for (int i = 0; i < size; i++)
    {
        char matLower[MAX_LENGTH];
        strcpy(matLower, options[i].material);
        toLowercase(matLower);

        if (strcmp(userChoice, matLower) == 0)
        {
            printf("\n--- Material Info ---\n");
            printf("Material         : %s\n", options[i].material);
            printf("Cost             : %s\n", getCostString(options[i].cost));
            printf("Recyclability    : %s\n", getRecyclabilityString(options[i].recyclability));
            printf("Good for Rain    : %s\n", options[i].goodForRain);
            printf("Good for Summer  : %s\n", options[i].goodForSummer);
            printf("Good for Winter  : %s\n", options[i].goodForWinter);
            printf("Advantages       : %s\n", options[i].pros);
            printf("Disadvantages    : %s\n", options[i].cons);
            return;
        }
    }
    printf("\nMaterial not found. Please enter a valid material.\n");
}

int main()
{
    Packaging options[MAX_MATERIALS] = {
        {"Plastic", 1, 1, "Cheap, lightweight, versatile, waterproof", "Pollutes, hard to recycle, non-biodegradable", "Yes", "Yes", "Yes"},
        {"Glass", 3, 3, "Reusable, recyclable, does not degrade", "Breaks easily, heavy, costly", "Yes", "Yes", "Yes"},
        {"Polythene", 1, 1, "Cheap, flexible, waterproof", "Pollutes, harmful to wildlife", "Yes", "Yes", "Yes"},
        {"Aluminum", 3, 2, "Recyclable, strong, corrosion-resistant", "High production cost, requires mining", "Yes", "Yes", "Yes"},
        {"Aluminum Foil", 3, 2, "Flexible, heat-resistant", "Tears easily, hard to recycle if dirty", "Yes", "Yes", "Yes"},
        {"Aluminum Cans", 3, 3, "Durable, highly recyclable", "Costlier than plastic", "Yes", "Yes", "Yes"},
        {"Biodegradable Plastic", 2, 3, "Eco-friendly, decomposes naturally", "Expensive, needs special disposal", "No", "Yes", "No"},
        {"Cardboard", 2, 3, "Recyclable, biodegradable", "Weak, absorbs moisture", "No", "No", "No"},
        {"Corrugated Cardboard", 2, 3, "Strong, recyclable", "Bulky, weak when wet", "No", "No", "No"},
        {"Folding Cartons", 2, 3, "Customizable, recyclable", "Less durable, not waterproof", "No", "No", "No"},
        {"Kraft Paper Unbleached", 2, 3, "Strong, eco-friendly", "Absorbs moisture", "No", "No", "No"},
        {"Kraft Paper Bleached", 2, 3, "Aesthetic, smooth", "Weaker, uses chemicals", "No", "No", "No"},
        {"Recycled Kraft Paper", 2, 3, "Eco-friendly, cost-effective", "Lower strength, rough", "No", "No", "No"},
        {"Paperboard", 2, 3, "Recyclable, easy to print", "Weak, not waterproof", "No", "No", "No"}};

    char userChoice[MAX_LENGTH];

    printf("Enter a packaging material (Plastic, Glass, Paper, Polythene, Aluminum, Biodegradable Plastic, Cardboard): ");
    fgets(userChoice, sizeof(userChoice), stdin);
    cleanInput(userChoice);
    toLowercase(userChoice);

    if (strcmp(userChoice, "paper") == 0)
    {
        printf("Which type? (Kraft Paper Unbleached, Kraft Paper Bleached, Recycled Kraft Paper, Paperboard): ");
        fgets(userChoice, sizeof(userChoice), stdin);
        cleanInput(userChoice);
        toLowercase(userChoice);
    }
    else if (strcmp(userChoice, "aluminum") == 0)
    {
        printf("Which type? (Aluminum Foil, Aluminum Cans): ");
        fgets(userChoice, sizeof(userChoice), stdin);
        cleanInput(userChoice);
        toLowercase(userChoice);
    }
    else if (strcmp(userChoice, "cardboard") == 0)
    {
        printf("Which type? (Corrugated Cardboard, Folding Cartons): ");
        fgets(userChoice, sizeof(userChoice), stdin);
        cleanInput(userChoice);
        toLowercase(userChoice);
    }

    displayMaterialInfo(options, MAX_MATERIALS, userChoice);
    return 0;
}
