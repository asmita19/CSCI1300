#Refrences:
#    enumerate: http://book.pythontips.com/en/latest/enumerate.html



class Library:
    def __init__(self):
        self.book_list = [] 
        self.user_dic = {}
        
    def loadBookData(self, file_name):
        bookfile = open(file_name, 'r')
        for line in bookfile:
            self.book_list.append(line.lower().strip().split(","))
    def loadRatingsData(self, file_name):
        ratingsfile = open(file_name, 'r')
        for line in ratingsfile:
            name, ratings = line.strip().split(",")
            self.user_dic[name] = [int(r) for r in ratings.strip().split()] 
    
    def log_in(self): 
        name = input("Welcome to the Library, What is your name?: \n")
        name = name.lower() 
        while True:
            if len(name) == 0: 
                print("You provided an empty username, Please provide a valid user name to login or register")
                name = input("Enter your name again:")
                print()
                name = name.lower()
            else: 
                if name in self.user_dic: 
                    print("Welcome back,", name)
                    
                else: 
                    print("Welcome to the Library,", name)
                    
                    #print("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?: ")
                    self.user_dic[name] = [0] * len(self.book_list)
                return name 
        
    def showRatings(self, userIndex):
        first_book = True
        for show in range(len(self.user_dic[userIndex])):
            if self.user_dic[userIndex][show] != 0:
                if first_book: 
                    print("Here are the books that you have rated:")
                    first_book = False
                print("Title :", self.book_list[show][1], "\nRating :", self.user_dic[userIndex][show], "\n------------------------------")
        
        if first_book: 
            print("no book to show")
    def rateBook(self, username):
        is_updated = False
        
        while not is_updated:
        #rate = input("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?: \n")
            book_title = input("Enter the name of the book that you would like to rate: \n")
            book_title = book_title.lower()
            book_rate = input("Enter your rating of the book: \n")
            for i in range(len(self.book_list)):
                if self.book_list[i][1] == book_title:
                    self.user_dic[username][i] = int(book_rate)
                    print("Success!")
                    print("Thank-you. The rating for the book titled \"" + self.book_list[i][1] + "\" has been updated to", book_rate)
                    is_updated = True 
            if is_updated == False: 
                print("The book you requested does not exist in the database")
    
    def ssd(self, ratingA, ratingB): 
        return sum( [(a-b)**2 for a, b in zip(ratingA, ratingB)])
    
    def getRecomendation(self, userInput):
        matchrating = [3,5]
        
        sim_user = None 
        sim_score = 1000000 
        for user in self.user_dic:
            score = self.ssd(self.user_dic[userInput], self.user_dic[user])
            
            if user != userInput and score < sim_score:
                sim_score = score 
                sim_user = user 
        
        user_rating = self.user_dic[userInput]
        sim_rating = self.user_dic[sim_user]
        
        reccomdationlist = []
        for i in range(len(self.book_list)):
            if user_rating[i] == 0 and sim_rating[i] >= 3:
                reccomdationlist.append(self.book_list[i])
        
        if len(reccomdationlist) == 0: 
            print("There are no recommendations for you at present")
        else: 
            print("Here are some of the books that we think you would like")
            for b in reccomdationlist[:10]:
                a, t = b
                print(t,"by", a)
                
                
        # mostsimilar= self.loadRatingsData(userInput)
        # mostsimilarrating = self.user_dic[mostsimilar]
        # currentrating = self.user_dic[userInput]
        # reccomdationlist = []
        # for bookid, bookrating in range(mostsimilarrating):
        #     if bookrating not in matchrating:
        #         continue
        #     if currentrating[bookid] != 0:
        #         continue
        #     newbookr = self.
            
 
def menu(): 
    my_library = Library() 
    my_library.loadBookData("books.txt")
    my_library.loadRatingsData("ratings.txt")
    
    print("Data Loaded successfully!")
    u_name = my_library.log_in() 
    
    while True:
        choice = input("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:\n")
        if choice == "v":
            my_library.showRatings(u_name)
        elif choice == "r":
            my_library.rateBook(u_name)
        elif choice == "g":
            my_library.getRecomendation(u_name)
        elif choice == "q":
            print("Goodbye!")
            break
        else:
            print("Please input a valid choice")
menu()