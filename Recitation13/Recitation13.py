'''Asmita Dhakal
CSCI 1300 
Reciatation: Bu Sun 202
Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
Recitation 13: 1st python'''

'''
function print_param that prints out whatever is passed in as argument. 
The function takes in one parameter and should not return anything.
'''
#1:
def print_param(whatever):
    print(whatever)#prints the parameter

'''
function odd_or_even that takes in one integer and prints out whether the integer is even or odd. 
(e.g. if the input is even, print the string 'even', and if the number is odd, print the string 'odd') 
The function takes in one parameter and not return anything.
'''   
#2
def odd_or_even(inte):
    if inte % 2 == 0:
        print("even")#prints even
    else:
        print("odd")#prints odd

'''
function fizz_buzz that loops from 0 up to a number n, printing the number or a word at each iteration.
--If the current number is divisible by 3, print the word "Fizz"
--If it is divisible by 5, print "Buzz"
--If it is divisible by 3 and 5 print "FizzBuzz"
--Otherwise, print the number itself. (If the number is 0, also print the number itself.)
--The function takes one parameter n and should not return anything.
'''
#3
def fizz_buzz(n):
    for i in range(n + 1):
        if i == 0:
            print(i)
        elif i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
        elif i % 3 == 0:
            print("Fizz")
        elif i % 5 == 0:
            print("Buzz")
        else:
            print(i)

'''
function oneSum which takes one input, n, and finds the sum:
1 + 11 + 111 + 1111 + ... up to n digits of 1.
Which is 1 + 11 + 111 = 123
'''
#4
def oneSum(n):
    return sum([int("1" * i) for i in range(1, n+1)]) #sum function with for loop to iterate  
    # total = 0 - dummy variable for the sum 
    # for i in range(1, n+1): - for loop to iterate through 
    #     total += int("1" * i)
    # return total- returns the answer such as 1, 12, 123, 1234




#Test cases

#1
print_param(3)
print_param(-12.0)

#2
odd_or_even(12)
odd_or_even(0)

#3
fizz_buzz(10)
fizz_buzz(14)

#4
print(oneSum(3))
print(oneSum(10))