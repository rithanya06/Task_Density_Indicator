/*
============================================================
  HoT SKILL ASSESSMENT - PROBLEM 1
  Token Density Indicator (Lexical Analysis)
============================================================
  Name    : Rithanya M
  Reg No  : RA2311026050117
  Tool    : C Language (Dev C++)
  Problem : Lexical Analysis - Token Density Indicator

  DESCRIPTION:
  A compiler development team collects lexical analysis logs
  containing raw tokens and line numbers. This program:
    - Derives Token_Density (tokens per line)
    - Creates flag Is_Token_Heavy if density > threshold
    - Shows line-wise token distribution
    - Classifies code complexity level

  HOTs Goal: Design complexity indicators from lexical data
============================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define THRESHOLD 5.0

/* Function: compute token density */
float computeDensity(int total_tokens, int total_lines) {
    if (total_lines == 0) return 0.0;
    return (float)total_tokens / total_lines;
}

/* Function: classify complexity */
void classifyComplexity(float density) {
    printf("\n  Complexity Analysis:\n");
    if (density < 3.0)
        printf("  Complexity Level   : LOW  (Highly Readable Code)\n");
    else if (density >= 3.0 && density <= 5.0)
        printf("  Complexity Level   : MEDIUM  (Moderate Complexity)\n");
    else
        printf("  Complexity Level   : HIGH  (Complex / Dense Code)\n");
}

/* Function: generate Is_Token_Heavy flag */
void generateFlag(float density) {
    printf("\n  Flag Generation (Threshold = %.1f tokens/line):\n", THRESHOLD);
    if (density > THRESHOLD)
        printf("  Is_Token_Heavy     : TRUE  --> Token Heavy Code Detected!\n");
    else
        printf("  Is_Token_Heavy     : FALSE --> Normal Code\n");
}

/* Function: display line-wise token distribution */
void displayDistribution(int tokens[], int lines) {
    int i;
    printf("\n  Line-wise Token Distribution:\n");
    printf("  %-10s | %-15s | %-10s\n", "Line No.", "Token Count", "Status");
    printf("  ------------------------------------------\n");
    for (i = 0; i < lines; i++) {
        printf("  Line %-5d | %-15d | %s\n",
               i + 1,
               tokens[i],
               (tokens[i] > THRESHOLD) ? "Heavy" : "Normal");
    }
}

int main() {
    int tokens[MAX_LINES];
    int lines, i;
    int total_tokens = 0;
    float density;

    printf("============================================================\n");
    printf("       HoT SKILL ASSESSMENT - TOKEN DENSITY INDICATOR       \n");
    printf("       Rithanya M | RA2311026050117                         \n");
    printf("============================================================\n\n");

    printf("  Enter number of source lines to analyze: ");
    scanf("%d", &lines);

    if (lines <= 0 || lines > MAX_LINES) {
        printf("  ERROR: Invalid input. Enter between 1 and %d.\n", MAX_LINES);
        return 1;
    }

    printf("\n  --- Enter Token Count for Each Line ---\n");
    for (i = 0; i < lines; i++) {
        printf("  Line %d token count: ", i + 1);
        scanf("%d", &tokens[i]);
        if (tokens[i] < 0) tokens[i] = 0;
        total_tokens += tokens[i];
    }

    density = computeDensity(total_tokens, lines);

    /* ---- OUTPUT REPORT ---- */
    printf("\n============================================================\n");
    printf("                  LEXICAL ANALYSIS REPORT                   \n");
    printf("============================================================\n");
    printf("  Total Lines        : %d\n", lines);
    printf("  Total Tokens       : %d\n", total_tokens);
    printf("  Token Density      : %.2f tokens/line\n", density);

    classifyComplexity(density);
    generateFlag(density);
    displayDistribution(tokens, lines);

    printf("\n============================================================\n");
    printf("  HOTS Goal: Derived complexity indicators from lexical data \n");
    printf("  Token_Density = %d / %d = %.2f\n", total_tokens, lines, density);
    printf("============================================================\n\n");

    return 0;
}

/*
============================================================
  SAMPLE INPUT:
    Enter number of source lines: 5
    Line 1: 7
    Line 2: 4
    Line 3: 8
    Line 4: 3
    Line 5: 6

  EXPECTED OUTPUT:
    Total Lines        : 5
    Total Tokens       : 28
    Token Density      : 5.60 tokens/line
    Complexity Level   : HIGH (Complex / Dense Code)
    Is_Token_Heavy     : TRUE --> Token Heavy Code Detected!
============================================================
*/
