'''Asmita Dhakal
CSCI 1300 
Reciatation: Bu Sun 202
Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
Homework # 9'''


#1:
'''Algorithm: Function countNames takes in a list of names 
-returns a dictionary with keys as first name and its value as a list of last names.'''
def countNames(list_of_names):
    nameDictionary = {}
    for i in range(len(list_of_names)):
        names = list_of_names[i].split() # strips the name and splits it up
        if names[0] in nameDictionary:
            nameDictionary[names[0]].append(names[1])
        else:
            lists = [] # craeting an empty array
            lists.append(names[1])
            nameDictionary[names[0]] = lists
    return nameDictionary #returns the dictionary of names

#2:
'''Algorithm:function, compute_grade(...), 
that takes a parameter, file_name, and computes the final grade of class given the grades of each section of the course
the weights associate with the section.
Function reads each line of a file, computes the average of the values associated with the section and weight the
average by the weights indicated. The final grade is the sum of the weighted
averages. 
The function returns the final grade of the class.
'''
def compute_grade(file_name):
    overrall = 0  
    total = 0
    try:
        with open(file_name)as file: #opens up the passed parameter file name
            for line in file:
                list_in_line = line.split(',') #splits up the line given in a list with a comma
                average = 0
                for i in range(0, len(list_in_line)-2):
                    average += int(list_in_line[i])
                average = float(average/(len(list_in_line)-2)) #calculates the average
                average *= float(list_in_line[-1])
                total += float(list_in_line[-1])
                overrall /= total #divides the overall value by total number of points
    except:
        return "File not found" #if file doesn't exist returns the file doesn't exist
    return overrall #returning the overall weighted grade in class

#3:
'''Algorithm:function called update_dictionary that has two parameters: a filename and a dictionary. 
The function:
1. Opens the given file
    a. If the file open succeeds, it prints filename "loaded successfully."
    b. If the file open fails: prints  filename "does not exist."
2. Reads in the data from the file and fills the dictionary.
''' 
def update_dictionary(filename, dictionary):
    try:
        with open(filename) as filee:
            print(filename, 'loaded successfully.')
            for line in filee:
                slangs = line.strip().split(",")
                dictionary[slangs[0]] = slangs[1]
        print('The dictionary has ' + str(len(dictionary.items()))+' entries.')
    except:
        print(filename, 'does not exist.\nThe dictionary has 0 entries.')
    return dictionary

#4:
'''Algorithm: function deslang, takes two parameters, a string and a dictionary
1.Returns the deslanged string. 
2.Each word in the string will be replaced if it has an entry in the dictionary. 
3.Any word not in the dictionary should be copied to the results.
'''
def deslang(slang, wordDictionary):
    swords = []
    swords = slang.split()
    for i in range(len(swords)):
        full = swords[i]
        if full in wordDictionary:
            slang = slang.replace(full, wordDictionary[full])
    return slang
#5:
'''Algorithm: main function in the file containing the functions:
    1.update_dictionary
    2.deslang
Provides the following menu:
    Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?:
    
1. If the the user inputs 'a' then asks to:
    'Enter a file name:'
    -If the file exixst, 
        *calls the update_dictionary function
        *adds the file to the dictionary and says filename, 'loaded sussessfully.'
    -If doesn't exist,
        *prints filename, 'does not exist'
2. If the user inputs 'd' then asks to:
    'Enter a sentence:'
    -Then prints the deslanged word with calling the deslang function to with given parameters. 
'''    
def main():
    choice = ""
    dic = {}
    while choice != "q":
        choice = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
        if choice == "a":
            fil = ""
            while len(fil) == 0: # empty file name
                fil = input("Enter a filename: ")
            dic = update_dictionary(fil, dic) #calls the update dictionary function with given parameter
        elif choice == "d":
            d = ""
            while len(d) == 0: #emtpy string 
                d = input("Enter a sentence: ")
            print(deslang(d, dic))#prints the deslanges word with calling the deslang function with given parameters

if __name__ == "__main__":
    main()
    