'''Asmita Dhakal
Practice Practicum 4'''

#1: Done
'''Write a function check_palindrome_case_insensitive that takes one input parameter, string.
Your function will have to check if the given string is a palindrome string and return True if 
it is palindrome and return False otherwise.
Your function should be case insensitive that is:"madam" and "Madam" are palindromes.'''
def check_palindrome_case_insensitive(pani):
    pani = pani.lower()
    if pani == "":
        return True
    reverse = ''.join(reversed(pani))
    if pani == reverse:
        return True
    return False
    
    
#2: DONE
'''Write a function check_palindrome that takes one input parameter, string.
Your function will have to check if the given string is a palindrome string and 
return True if it is palindrome and return False otherwise. '''
def check_palindrome(pani):
    reverse = ''.join(reversed(pani))
    if pani == " ":
        return True
    if pani == reverse:
        return True
    return False
    
#3: DONE
'''Hailstones are balls or irregular lumps of ice. They start in a cloud as raindrops and they are pushed higher and lower in the atmosphere until they freeze many times over and eventually fall on Earth. 
This problem simulates the sequence of altitude values of a hailstone as it goes through its formation process.
    1.Pick a positive integer value for the initial_altitude as the start.
    2.If the value of initial_altitude is even, divide it by 2 (or halve it).
    3.If the value of initial_altitude is odd, multiply it by 3 and add 1.
    4.Continue this process until the value of initial_altitude is 1 (we will consider the altitude of the hailstone right before it drops on Earth to be 1).
The variable initial_altitude will go through a sequence of values. It will increase and decrease, it will go higher and lower in the atmosphere, but will eventually end at 1. 
Write a function called hailStoneTracker that takes a single argument initial_altitude. The function should print the maximum value(as float) out of all the values initial_value went 
through and return a list of all the values(as float type) that initial_altitude went through. '''
def hailStoneTracker(initial_altitude):
    list = []
    list.append(initial_altitude)
    while True:
        if initial_altitude % 2 ==  0:
            initial_altitude /= 2
        elif initial_altitude == 1:
            break
        else:
            initial_altitude = (initial_altitude * 3) + 1
        list.append(float(initial_altitude))
    print("Max:",max(list))
    return list
''' '''    
#4:DONE
'''write a function that is given a list of integer values and an integer value, 
returns the integer number of items that are greater than the given value. '''
def CountItems(items, value):
    count = 0
    for item in items:
        if item > value:
            count += 1
    return count

#5:DONE 
'''Write a function that is given a list of string values and a character value, 
returns the integer number of items that ends with the given character. '''

def CountItems(items, letter):
    count = 0
    for i in items:
        if i[-1] == letter:
            count +=1
    return count
    
#6:DONE
'''Write a function find_host_in_file.  
The function will have 2 parameters, a file_name, and a hostname
The file contains an email Id in each line. 
e.g. ioana.fleming@colorado.edu where
       ioana.fleming is the username and colorado.edu is the host. 

The function should return a list of all the users in the file which have the hostname as the parameter passed.
The function should return a -1 if the file can't be opened. 
Hint: 

Use try-except for exception handling. 
There might be empty lines in the file, or the email ID might have leading and trailing spaces.
You should first parse the file and split each line and store it.'''
def find_host_in_file(file_name, hostname):
    users = []
    try:
        read = open(file_name, "r")
        for line in read:
            list = line.strip().split("@")
            if len(list) == 2 and hostname == list[1]:
                users.append(list[0].strip())
        return users
    except: 
        return -1
    return users
    
#7:DONE
'''Write a function create_dictionary that is given a list of string values, 
returns a dictionary by grouping the strings based on the first character of each string. 
Key will be the first character, the value will be a list of strings which start with that character. '''
def create_dictionary(list):
    dictionary = {}
    for key in list:
        if key[0] in dictionary:
            dictionary[key[0]].append(key)
        else:
            dictionary[key[0]] = [key]
    return dictionary
    
#8: DONE
'''Write a function repList that receives two input arguments: 
        a list and a number which tells the times each element in the list should be duplicated. 
The function should then return the resulting list. 
If the second input argument is 0(zero) then the function should return an empty list.'''
def repList(list, number):
    index = 0
    d = []
    for i in list:
        for j in range(number):
            d.append(i)
    return d

#9: DONE
'''Write a function find_items_in_file.  
1.The function will have 2 parameters, a file_name, and an integer number
2.The file contains an item and number of item separated by bar '|' in each line. 
e.g.
    pen|5
    phone|10
    book|3
The function should return a list of all the items in the file which have the number as the parameter passed.
The function should return a -1 if the file can't be opened. 
Hint: 
    Use try-except for exception handling. 
    The second parameter is of integer type
    There might be empty lines in the file, or the item might have leading and trailing spaces.
    You should first parse the file and split each line and store it.
    '''
def find_items_in_file(file_name, number):
    try:
        list = []
        read = open(file_name, 'r')
        for line in read:
            line = line.strip().split('|')
            if int(line[1]) == number:
                list.append(line[0].strip())
        return list
    except:
        return -1
        
'''returns the number in the dictionary'''
def dicti(number):
    dictionary = {}
    for key in number:
        dictionary[key] = number
    return dictionary