// A C program to convert characters to integers

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// we will be using two parallel arrays: one for the string representations of numbers and another for their corresponding integer values

int main(int argc, char* argv[])
{

    //  argc should be between 2 and 11, inclusive, to allow up to 10 arguments
    if (argc < 2 || argc > 11)
    {
        printf("Usage: ./chartoint [one to zero] (max 10 words)\n");
        return 1;
    }

    // first array for int values, we use 'long' data type as that prevents integer overflow with larger numbers
    long digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // second array for char/string representations
    char* numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero"};

    // someone provides input of str, compare input string (argv[1]) with string in numbers array
    // take that input ie argv[1]
    // if match, then use the index to get corresponding integer from digits array.

    // The variable n should be the length of the numbers array, not the length of a specific string, agian using 'long'
    long n = sizeof(numbers) / sizeof(numbers[0]);

    // to keep track of the concatonated result, initially 0, using 'long' here as well, since result might go upto 9,999,999,999
    long result = 0;

    // digit counter
    int digit_counter = 0;

    // for each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // flag variable, to keep track of whether a match is found
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            // compare argv[i] with the strings in the numbers[j] array
            if (strcmp(argv[i], numbers[j]) == 0)
            {

                // comma after every 3 digits, if there is a fourth, upto 10 digits ignoring argv[1] (first argument is the program)
                // result times 10 for that digit in the array
                // lot of if-else statements, but we can simplify it by using a loop or a formula use a loop to multiply the result by 10
                // for each digit we processed

                // formula for when to multiply by 10 and add the n + 1th digit in the array
                result = result * 10 + digits[j];

                // if match found increment counter
                digit_counter++;
                found = true;
            }

        }
        if (found == false)
        {
            printf("Invalid input: %s\n", argv[i]);
            return 1;
        }
    }

    // now we want to print with commas using digit_counter, using the "putchar" function to insert a comma character where we want
    // we cant do that with an int, so convert the result to a string

    // set a buffer for characters (twice of possible chars for safety)
    char buffer[20];

    // change result to char by using buffer above, then use "sprintf" to convert the result integer to a string and store it in the buffer
    // then create a int variable to check length of this buffer, using the result variable
    sprintf(buffer, "%ld", result); // place holder is "%ld" for long

    // we get this value from the counter variable, of which the "result" variable we just converted to a string, is keeping track of
    // ie, buffer, now len
    int len = strlen(buffer);

    // don’t need to print twice, we are only using "sprintf" to convert result to string
    printf("Int value: ");

    // iterate for every buffer ie "word" and check length:
    // make sure its only after every 3, by checking the buffer[i] is NOT the defined length - 1, ie only 2.
    // iterate through the buffer and use putchar to print each character, inserting commas where necessary
    for (int i = 0; i < len; i++)
    {
        putchar(buffer[i]);

        // If "len", which is the "buffer" value, which in turn is the "counter" variable value, is divisible by 3, with no remainder
        // BUT "len" is the total length of the number, not the current position in the number, so we use "i", which represents the current position
        // in the number. Then by checking i != len - 1, we make sure not to print a comma after the last digit
        if (((len - i - 1) % 3 == 0) && (i != len - 1))
        {
            putchar(',');
        }
    }
    printf("\n");

    return 0;
}

