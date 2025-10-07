// Author: Spencer Niemeyer
// Description: Demonstrates fundamental C functions.
#include <stdio.h>

// Prototypes for functions
int count_digits(int n);
int sum_digits(int n);
int is_vowel(char c);
int gcd(int a, int b);
int isPrime(int n);
int absVal(int n);

int main(void) {
    int userNum = 0;
    char userChar;
    printf("Enter a number: ");
    scanf(" %d", &userNum);

    // Task 1: Count digits in int (length of int)
    printf("Number of digits = %d\n", count_digits(userNum)); // uses count_digits function to count digits

    // Task 2: Sum digits in int
    printf("Sum of digits = %d\n\n", sum_digits(userNum)); // uses sum_digits function to sum digits

    // Task 3: Check vowel
    printf("Enter a character: ");
    scanf(" %c", &userChar); // user input char
    if(is_vowel(userChar)) { // uses is_vowel function to check if char is a vowel
        printf("%c is a vowel\n", userChar);
    } else {
        printf("%c is not a vowel\n", userChar);
    }

    // Task 4: GCD
    int num1, num2;
    printf("Enter two numbers: ");
    scanf(" %d %d", &num1, &num2);
    printf("gcd(%d, %d) = %d\n", num1, num2, gcd(num1, num2)); // uses gcd function to find gcd and prints result

    return 0;
}

int count_digits(int n) {
    if(n == 0) { return 1; } // special case
    int temp = absVal(n);
    int count = 0;
    while(temp != 0) { // loop divides absVal(n) by 10 until == 0 to count digits
        temp /= 10;
        count++;
    }
    return count;
}

int sum_digits(int n) {
    int temp = absVal(n);
    int sum = 0;

    for (int i = 0; i < count_digits(n); i++) { // uses modulo to sum numbers
        sum += temp % 10;
        temp /= 10;
    }

    return sum;
}

int is_vowel(char c) {
    // Checks user input char against all vowels, lowercase and uppercase
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int gcd(int a, int b) {
    int aTemp = absVal(a);
    int bTemp = absVal(b);
    int gcdResult = 1;

    if (aTemp == 0 && bTemp == 0) return 0;
    if (aTemp == 0) return bTemp;
    if (bTemp == 0) return aTemp;
    
    // Loop to find greatest common divisor
    for(int i = 2; i <= aTemp; i++) {
        if (aTemp % i == 0 && bTemp % i == 0) {
            gcdResult = i;
        }
    }

    return gcdResult;
}

// Returns absolute value
int absVal(int n) {
    int num = n;
    if (num < 0) num *= -1;
    return num;
}