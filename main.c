#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates and prints BMI and ideal weight range based on weight and height.
 */
void calculateBMI(double weight, double height);
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

// BMI thresholds based on WHO
#define BMI_MIN_NORMAL    18.5
#define BMI_MAX_NORMAL    24.9

#define BMI_MIN_OB1       30.0
#define BMI_MIN_OB2       35.0

/**
 * Program entry point: prompts for weight and height, then shows BMI info.
 */
int main(void)
{
    // This causes the text to be printed immediately on the terminal
    setbuf(stdout, NULL);
    
    clearScreen();
    printBanner();

    double weight, height;

    // Prompt for weight
    printf(GREEN "Your weight (kg): " RESET);
    scanf("%lf", &weight);

    // Prompt for height
    printf(GREEN "Your height (m): " RESET);
    scanf("%lf", &height);

    printf("\n" RESET);

    // Calculate BMI and print results
    calculateBMI(weight, height);

    return 0;
}

/**
 * Calculates and prints BMI and ideal weight range based on weight and height.
 */
void calculateBMI(double weight, double height)
{
    // Formula: BMI = weight / height²
    float heightSquared = height * height;
    float bmi = weight / heightSquared;

    // Ideal weight range based on BMI thresholds
    float idealWeightMax = BMI_MAX_NORMAL * heightSquared;
    float idealWeightMin = BMI_MIN_NORMAL * heightSquared;

    printf("Classification: ");

    if(bmi < BMI_MIN_NORMAL)
        printf(YELLOW "Underweight\n" RESET);
    else if(bmi < BMI_MAX_NORMAL)
        printf(GREEN "Normal weight\n" RESET);
    else if(bmi < BMI_MIN_OB1)
        printf(YELLOW "Obesity I.\n");
    else if(bmi < BMI_MIN_OB2)
        printf(YELLOW BOLD "Obesity II.\n" RESET);
    else
        printf(RED "Obesity III." RESET);

    printf("Your BMI is %.1lf\n", bmi);

    printf(CYAN "Ideal weight between %.1lf kg and %.1lf kg.\n" RESET, idealWeightMin, idealWeightMax);
}

/**
 * Clears the screen using system command for the current platform.
 */
void clearScreen()
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
void printBanner() {
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
        "=====================================\n\n"
        RESET
    );
}
