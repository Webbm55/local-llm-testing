#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char sign[20];
    int start_month;
    int start_day;
    int end_month;
    int end_day;
} ZodiacSign;

const ZodiacSign zodiac_dates[] = {
    {"Capricorn", 12, 22, 1, 19},
    {"Aquarius", 1, 20, 2, 18},
    {"Pisces", 2, 19, 3, 20},
    {"Aries", 3, 21, 4, 19},
    {"Taurus", 4, 20, 5, 20},
    {"Gemini", 5, 21, 6, 20},
    {"Cancer", 6, 21, 7, 22},
    {"Leo", 7, 23, 8, 22},
    {"Virgo", 8, 23, 9, 22},
    {"Libra", 9, 23, 10, 22},
    {"Scorpio", 10, 23, 11, 21},
    {"Sagittarius", 11, 22, 12, 21}
};

char* get_zodiac_sign(int month, int day) {
    for (int i = 0; i < 12; i++) {
        if (zodiac_dates[i].start_month == zodiac_dates[i].end_month) {
            if (month == zodiac_dates[i].start_month && 
                day >= zodiac_dates[i].start_day && 
                day <= zodiac_dates[i].end_day) {
                return (char*)zodiac_dates[i].sign;
            }
        } else {
            if ((month == zodiac_dates[i].start_month && day >= zodiac_dates[i].start_day) ||
                (month == zodiac_dates[i].end_month && day <= zodiac_dates[i].end_day)) {
                return (char*)zodiac_dates[i].sign;
            }
        }
    }
    return NULL;
}

int main() {
    char name[100];
    char dob_input[9];
    int year, month, day;
    int age;
    
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline
    
    printf("What is your date of birth? (Enter in yyyyMMdd format) ");
    scanf("%8s", dob_input);
    
    // Parse the date of birth
    if (sscanf(dob_input, "%4d%2d%2d", &year, &month, &day) != 3 ||
        month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date format. Please use yyyyMMdd format.\n");
        return 1;
    }
    
    // Calculate age
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    
    age = today->tm_year + 1900 - year;
    if ((today->tm_mon + 1 < month) || 
        (today->tm_mon + 1 == month && today->tm_mday < day)) {
        age--;
    }
    
    // Determine zodiac sign
    char *sign = get_zodiac_sign(month, day);
    
    if (sign != NULL) {
        printf("Hello, %s! You are %d years old. Your zodiac sign is %s!\n", name, age, sign);
    } else {
        printf("Hello, %s! You are %d years old. That's not a valid date.\n", name, age);
    }
    
    return 0;
}
