#include <stdio.h>

// Function to find the length of a string
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Function to concatenate two strings
void stringConcat(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    // Copy str1 to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Append str2 to result
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0'; // Null terminate the result
}

// Function to compare two strings (0 if equal, 1 if not)
int stringCompare(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 1; // Strings are not equal
        }
        i++;
    }

    // Check if both strings end at the same length
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0; // Strings are equal
    } else {
        return 1; // Strings are not equal
    }
}

// Function to insert a substring at a given position
void insertSubstring(char mainStr[], char subStr[], int pos, char result[]) {
    int i = 0, j = 0, k = 0;

    // Copy mainStr up to the insertion point
    while (i < pos) {
        result[i] = mainStr[i];
        i++;
    }

    // Copy subStr into result
    while (subStr[j] != '\0') {
        result[i] = subStr[j];
        i++;
        j++;
    }

    // Append the rest of mainStr
    while (mainStr[pos + k] != '\0') {
        result[i] = mainStr[pos + k];
        i++;
        k++;
    }

    result[i] = '\0'; // Null terminate the result
}

// Function to delete a substring
void deleteSubstring(char mainStr[], int pos, int len, char result[]) {
    int i = 0, j = 0;

    // Copy characters before the substring to be deleted
    while (i < pos) {
        result[i] = mainStr[i];
        i++;
    }

    // Skip the substring of length `len`
    j = pos + len;

    // Copy the rest of mainStr
    while (mainStr[j] != '\0') {
        result[i] = mainStr[j];
        i++;
        j++;
    }

    result[i] = '\0'; // Null terminate the result
}

// Main function to demonstrate the operations
int main() {
    char str1[100], str2[100], result[200];
    int pos, len, choice;

    // Input string for demonstration
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Perform operations
    printf("Choose an operation:\n");
    printf("1. Length of the string\n");
    printf("2. Concatenate strings\n");
    printf("3. Compare strings\n");
    printf("4. Insert a substring\n");
    printf("5. Delete a substring\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Length of string 1: %d\n", stringLength(str1));
            printf("Length of string 2: %d\n", stringLength(str2));
            break;
        case 2:
            stringConcat(str1, str2, result);
            printf("Concatenated string: %s\n", result);
            break;
        case 3:
            if (stringCompare(str1, str2) == 0) {
                printf("Strings are equal\n");
            } else {
                printf("Strings are not equal\n");
            }
            break;
        case 4:
            printf("Enter the position to insert the second string: ");
            scanf("%d", &pos);
            insertSubstring(str1, str2, pos, result);
            printf("String after insertion: %s\n", result);
            break;
        case 5:
            printf("Enter the position and length of the substring to delete: ");
            scanf("%d %d", &pos, &len);
            deleteSubstring(str1, pos, len, result);
            printf("String after deletion: %s\n", result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
