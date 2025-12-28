#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double minNormal;
    double maxNormal;
    double obesityI;
    double obesityII;
} BmiTable;

/**
 * Calculates and prints BMI and ideal weight range based on weight and height.
 */
double calculateBMI(double weight, double height, double minNormal, double maxNormal);
/** 
 * Classify BMI.
 */
void classifyBMI(double bmi, double minNormal, double maxNormal, double obesityI, double obesityII); 
/**
 * Load the table.
 */
BmiTable loadTable(double age);
/**
 * Clears the terminal screen depending on the OS.
 */
void clearScreen();
/**
 * Prints application banner.
 */
void printBanner();

#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

/**
 * Program entry point: prompts for weight and height, then shows BMI info.
 */
int main(void)
{
    // This causes the text to be printed immediately on the terminal
    setbuf(stdout, NULL);

    clearScreen();
    printBanner();

    double weight, height, age;

    // Prompt for weight
    printf(GREEN "Your weight (kg): " RESET);
    scanf("%lf", &weight);

    // Prompt for height
    printf(GREEN "Your height (m): " RESET);
    scanf("%lf", &height);

    // Prompt for age
    printf(GREEN "Your age (y): " RESET);
    scanf("%lf", &age);

    printf("\n" RESET);

    // Creates variables from the table
    BmiTable table = loadTable(age);

    // Calculate BMI
    double bmi = calculateBMI(weight, height, table.minNormal, table.maxNormal);

    // Classifies the BMI
    classifyBMI(bmi, table.minNormal, table.maxNormal, table.obesityI, table.obesityII);

    return 0;
}

/**
 * Create variables from the table for more precise results.
 */
BmiTable loadTable(double age)
{
    char line[256];
    int counter = 1;
    BmiTable bmiTable;
    FILE *table = fopen("./assets/table.csv", "r");

    double minNormal = 0;
    double maxNormal = 0;
    double obesityI = 0;
    double obesityII = 0;

    // Check if it has been loaded  
    if (table == NULL)
    {
        printf("Error in open the archive");
        return bmiTable;
    }

    // According to the Brazilian Unified Health System (SUS), from age 20 onwards, the BMI (Basal Metabolic Rate) is the same for everyone above that age.
    if (age >= 20)
        age = 20;

    // look for the age in the column
    while (fgets(line, sizeof(line), table))
    {
        int csvAge;
        char *token;

        token = strtok(line, ",");
        csvAge = atoi(token);

        counter++;

        if (csvAge == (int)age)
        {
            // Creates variables from the values ​​in the column
            bmiTable.minNormal = atof(strtok(NULL, ","));
            bmiTable.maxNormal = atof(strtok(NULL, ","));
            bmiTable.obesityI  = atof(strtok(NULL, ","));
            bmiTable.obesityII = atof(strtok(NULL, ","));

            break;
        }
    }

    // Close the table
    fclose(table);

    return bmiTable;
}

/**
 * Calculates BMI and ideal weight range based on weight and height.
 */
double calculateBMI(double weight, double height, double minNormal, double maxNormal)
{
    // Formula: BMI = weight / height²
    float heightSquared = height * height;
    float bmi = weight / heightSquared;

    // Ideal weight range based on BMI thresholds
    float idealWeightMax = maxNormal * heightSquared;
    float idealWeightMin = minNormal * heightSquared;

    printf("Your BMI is %.1lf\n", bmi);

    printf(CYAN "Ideal weight between %.1lf kg and %.1lf kg.\n" RESET, idealWeightMin, idealWeightMax);

    return bmi;
}
/**
 * Classify BMI based on the table.
 */
void classifyBMI(double bmi, double minNormal, double maxNormal, double obesityI, double obesityII)
{
    if (bmi < minNormal)
        printf(YELLOW "Underweight.\n" RESET);
    else if (bmi < maxNormal)
        printf(GREEN "Normal weight.\n" RESET);
    else if (bmi < obesityI)
        printf(YELLOW "Obesity I.\n");
    else if (bmi < obesityII)
        printf(YELLOW BOLD "Obesity II.\n" RESET);
    else
        printf(RED "Obesity III." RESET);
}

/**
 * Clears the screen using system command for the current platform.
 */
void clearScreen(void)
{
    // Clear the screen based on the operating system
    #if defined(_WIN32)
        system("cls");
    #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
        system("clear");
    #endif
}

/**
 * Renders the ASCII banner for the BMI app.
 */
void printBanner(void)
{
    printf(CYAN BOLD
        "=====================================\n"
        "       █████╗  ███╗   ███╗██╗\n"
        "       ██╔══██╗████╗ ████║██║\n"
        "       ███████║██╔████╔██║██║\n"
        "       ██╔══██║██║╚██╔╝██║██║\n"
        "       ███████║██║ ╚═╝ ██║██║\n"
        "       ╚══════╝╚═╝     ╚═╝╚═╝\n"
        "=====================================\n"
        "      BODY MASS INDEX\n"
        "=====================================\n"
        RESET
    );
}
