#include <stdio.h>
#include <string.h>

// Function prototypes
int is_digit(char *input);
char* rotate_char(char *input, int shift_by);
int conv_stoi(char *input);
void get_string(char *buffer, int size, const char *prompt);

int main(int argc, char *argv[]) // Takes value of k after prompting ./decrypt 'k value'
{
    // Make sure program was run with just one command-line argument
    if (argc == 2)
    {
        // Make sure every character in argv[1] is a digit
        if (is_digit(argv[1]))
        {
            char value[256];
            get_string(value, sizeof(value), "ciphertext: ");
            int shift_by = conv_stoi(argv[1]) % 26;
            char *result = rotate_char(value, shift_by);

            printf("plaintext: %s\n", result);
            return 0; // Exit
        }
        else
        {
            printf("Usage: ./decrypt key\n");
            return 1; // Error Type 2
        }
    }
    else
    {
        printf("Usage: ./decrypt key\n");
        return 1; // Error Type 1
    }
}

// Function to get a string from the user
void get_string(char *buffer, int size, const char *prompt)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

// Function to check if a string is a digit
int is_digit(char *input)
{
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return 0; // False
        }
    }
    return 1; // True
}

// Function to rotate characters in a string
char* rotate_char(char *input, int shift_by) // Rotates only char types
{
    char offset;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            offset = 'A';
            input[i] = (input[i] - offset - shift_by + 26) % 26 + offset;
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            offset = 'a';
            input[i] = (input[i] - offset - shift_by + 26) % 26 + offset;
        }
    }
    return input;
}

// Function to convert a string to an integer
int conv_stoi(char *input)
{
    int value = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        value = value * 10 + (input[i] - '0');
    }
    return value;
}
