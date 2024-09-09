#include <stdio.h>

// Define a structure for time
struct Time {
    int hour;
    int min;
    int sec;
};

// Function to read time
void readTime(struct Time *t) {
    printf("Enter time (HH MM SS): ");
    scanf("%d %d %d", &t->hour, &t->min, &t->sec);
}

// Function to display time
void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

// Function to add two time objects
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;

    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + (result.sec / 60);
    result.hour = t1.hour + t2.hour + (result.min / 60);

    result.sec %= 60;
    result.min %= 60;
    result.hour %= 24;  // Assuming 24-hour format

    return result;
}

// Function to find the difference between two time objects
struct Time differenceTime(struct Time t1, struct Time t2) {
    struct Time result;
    int seconds1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int seconds2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
    int diffSeconds = seconds1 - seconds2;

    if (diffSeconds < 0) {
        diffSeconds += 24 * 3600;  // Add 24 hours in seconds if negative
    }

    result.hour = diffSeconds / 3600;
    diffSeconds %= 3600;
    result.min = diffSeconds / 60;
    result.sec = diffSeconds % 60;

    return result;
}

int main() {
    struct Time t1, t2, sum, diff;

    printf("Enter the first time:\n");
    readTime(&t1);

    printf("Enter the second time:\n");
    readTime(&t2);

    printf("\nFirst Time: ");
    displayTime(t1);

    printf("Second Time: ");
    displayTime(t2);

    sum = addTime(t1, t2);
    printf("\nSum of Times: ");
    displayTime(sum);

    diff = differenceTime(t1, t2);
    printf("Difference of Times: ");
    displayTime(diff);

    return 0;
}
