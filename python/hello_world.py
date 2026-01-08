"""
This script is a simple interactive program that asks for a user's name and date of birth,
then calculates their age and determines their zodiac sign!
"""

from datetime import datetime

# Prompt the user to enter their name and store it in the 'name' variable
name = input("What is your name? ")

# Ask for date of birth in yyyyMMdd format
dob_input = input("What is your date of birth? (Enter in yyyyMMdd format) ")

# Parse the date of birth
try:
    dob = datetime.strptime(dob_input, "%Y%m%d")
    today = datetime.now()
    
    # Calculate age
    age = today.year - dob.year - ((today.month, today.day) < (dob.month, dob.day))
    month = dob.month
    day = dob.day
except ValueError:
    print("Invalid date format. Please use yyyyMMdd format.")
    exit()

# Define zodiac signs with accurate date ranges
zodiac_dates = [
    ("Capricorn", (12, 22), (1, 19)),
    ("Aquarius", (1, 20), (2, 18)),
    ("Pisces", (2, 19), (3, 20)),
    ("Aries", (3, 21), (4, 19)),
    ("Taurus", (4, 20), (5, 20)),
    ("Gemini", (5, 21), (6, 20)),
    ("Cancer", (6, 21), (7, 22)),
    ("Leo", (7, 23), (8, 22)),
    ("Virgo", (8, 23), (9, 22)),
    ("Libra", (9, 23), (10, 22)),
    ("Scorpio", (10, 23), (11, 21)),
    ("Sagittarius", (11, 22), (12, 21)),
]

# Function to check if a date falls within a zodiac range
def get_zodiac_sign(month, day):
    for sign, (start_month, start_day), (end_month, end_day) in zodiac_dates:
        if start_month == end_month:
            if month == start_month and start_day <= day <= end_day:
                return sign
        else:  # Sign spans two months
            if (month == start_month and day >= start_day) or (month == end_month and day <= end_day):
                return sign
    return None

# Validate input and determine zodiac sign
if 1 <= month <= 12 and 1 <= day <= 31:
    sign = get_zodiac_sign(month, day)
    if sign:
        print(f"Hello, {name}! You are {age} years old. Your zodiac sign is {sign}!")
    else:
        print(f"Hello, {name}! You are {age} years old. That's not a valid date.")
else:
    print(f"Hello, {name}! You are {age} years old. Please enter a valid date.")