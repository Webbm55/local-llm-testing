"""
This script is a simple interactive program that asks for a user's name and age,
then greets them with their information.
"""

# Prompt the user to enter their name and store it in the 'name' variable
name = input("What is your name? ")

# Prompt the user to enter their age, convert it to an integer, and store it in the 'age' variable
age = int(input("How old are you? "))

# Print a formatted greeting message using the user's name and age
print(f"Hello, {name}! You are {age} years old.")