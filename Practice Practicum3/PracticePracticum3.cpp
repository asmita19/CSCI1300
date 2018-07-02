#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


/*Algirithm:
*/
//#1: DONE
class ChildGrowth{
    private:
        string name;
        int currentAge;
        float weightMetricConversion;
        float height[10];
        float weight[10];
    public:
        ChildGrowth();
        ChildGrowth(string);
        ChildGrowth(string, int);
        ChildGrowth(string, int, float[], float[]);
        string getName();
        void setName(string);
        int getCurrentAge();
        void setCurrentAge(int);
        void setHeight(float[]);
        void setWeight(float[]);
        float feetToMeter(float);
        float poundToKg(float);
        float calculateBmi(int);
        float calculation(int);
        string getCategory(int);
};

/*Algirithm:
*/
//#2: DONE
class Quarterback{
     private:
        int pass_completes;
        int pass_attempts;
        int total_yards;
        int touchdowns;
        int intercepts;
        string name;
    public:
        Quarterback();
        Quarterback(string);
        
        void setName(string);
        string getName();
        void setComp(int);
        int getComp();
        void setAtt(int);
        int getAtt();
        void setYards(int);
        int getYards();
        void setTD(int);
        int getTD();
        void setPick(int);
        int getPick();
        void PassCompleted(int);
        void PassAttempted();
        void Interception();
        float PasserRating();
        void Touchdown(int);
};

/**Algirithm: Create a class Book with the data members listed below.  Include a default constructor, a constructor with parameters for each data member, and getters and setters methods for each data member.  
 * For example if a class had a data member named mydata, the class would require methods named: getMydata and setMydata.  You must also provide the float AvgCost() method for the class to calculate the average cost of the book (based on sales divided by units).
 * title,  which is a string (initialize to empty string)
 * units, which is an integer value (initialize to 0)
 * sales, which is a floating point value (initialize to 0.0)
 * Your second constructor should take all data member variables as input in the order they are specified above.
 * You only need to write the class definition and any code that is required for that class.  Place all code within the class definition
        * NOTE:  you must not use the implicit "private" for class data types and methods.  Include public or private explicitly.
*/
//#3: DONE
class Book{
    private:
        string title = "";
        int units = 0;
        float sales = 0.0;
    public:
        Book();
        Book(string, int, float);
        void setTitle(string tit);
        string getTitle();
        void setUnits(int uni);
        int getUnits();
        void setSales(float sal);
        float getSales();
        float AvgCost();
};

Book::Book(){}

Book::Book(string tit, int uni, float sal){
    title = tit;
    units = uni;
    sales = sal;
}
void Book::setTitle(string tit){
    title = tit;
}
string Book::getTitle(){
    return title;
}
void Book::setUnits(int uni){
    units = uni;
}
int Book::getUnits(){
    return units;
}
void Book::setSales(float sal){
    sales = sal;
}
float Book::getSales(){
    return sales;
}
float Book::AvgCost(){
    return sales/units;
}

/**Algirithm: Create a class CoffeeCustomer with the following data members:
 * customerName: A string for the customer's name
 * brewType: A string representing the kind of brewing method the customer prefers
 * numCups: An integer denoting how many cups the customer typically orders
 * Your class should have a default constructor and another constructor that takes two string, first for customer name and second for brew type and sets customer's name and brew type accordingly.  
        * It should set numCups to 0.
 * Create getter and setter methods for each of the data members.  Here are the details about these methods:
        * setCustomerName: takes a string as a parameter, does not return anything
        * getCustomerName: takes no parameters, returns the customer's name
        * setBrewType: takes one of three strings as a parameter: "aeropress", "cold brew", or "drip".  
            * If one of these three strings are specified, this method sets brewType appropriately and returns the integer 1.  
            * If not, the method doesn't change brewType and returns the integer 0.
        * getBrewType returns the customer's preferred brew type.
        * setNumCups: takes an integer as a parameter.  If the integer is not greater than 0, the method returns -1 and does not change numCups.  
                * Otherwise, the method should change the numCups data member to the value specified and return 1.
        * getNumCups: returns the preferred number of cups the customer usually orders.
        * Your class's methods should be publicly accessible.  The data members should not be.  You only need to write the class definition and any code that is required for that class.  
                * Place all code within the class definition.
        * NOTE:  you must not use the implicit "private" for class data types and methods.  Include public or private explicitly.
*/
//#4: DONE
class CoffeeCustomer{
    private:
        string customerName;
        string brewType;
        int numCups = 0;
    public:
        CoffeeCustomer(){};
        CoffeeCustomer(string name, string type){
            customerName = name;
            brewType = type;
            numCups = 0;
        }
        void setCustomerName(string name){
            customerName = name;
        }
        string getCustomerName(){
            return customerName;
        }
        string setBrewType(string type){
            if(type == "aeropress" || type == "cold brew" || type == "drip"){
                brewType = type;
                return "1";
            }
            else{
                return 0;
            }
        }
        string getBrewType(){
            return brewType;
        }
        int setNumCups(int number){
            if(number < 0){
                return -1;
            }
            else{
                numCups = number;
                return 1;
            }
        }
        int getNumCups(){
            return numCups;
        }
};

/**Algirithm:Create a class TextBook with the data members listed below. 
 * Include a default constructor, a constructor with parameters for each data member, and "get" and "set" access method for each data member.  
 * For example if a class had a data member named mydata, the class would require methods named: getMydata and setMydata.  
 * You must also provide the float CostPerPage() method for the class to calculate the average cost of a book page (based on cost divided by pages).
        * title,  which is a string (initialize to empty string)
        * pages, which is an integer value (initialize to 0)
        * cost, which is a floating point value (initialize to 0.0)
        * online, which is a Boolean value (initialize to false)
    * Your second constructor should take all data member variables as input in the order they are specified above.
    * You only need to write the class definition and any code that is required for that class.  
    * Place all code within the class definition.
*/
//#5:DONE
class TextBook{
    private:
        string title = "";
        int pages = 0;
        float cost = 0.0;
        bool online;
    public:
        TextBook(){}
        TextBook(string tit, int p, float c, bool o){
            title = tit;
            pages = p;
            cost = c;
            online = o;
        }
        void setTitle(string tit){
            title = tit;
        }
        string getTitle(){
            return title;
        }
        void setPages(int p){
            pages = p;
        }
        int getPages(){
            return pages;
        }
        void setCost(float c){
            cost = c;
        }
        float getCost(){
            return cost;
        }
        void setOnline(bool o){
            online = o;
        }
        bool getOnline(){
            return online;
        }
        float CostPerPage(){
            return cost/pages;
        }
};

/**Algirithm:1) Create a class named Country with a default constructor, a public methods ReadFile, getMaxAreaState and a private data members-
        * stateName, which is an array with 50 string values
        * area, which is an array of 50 integer values.  
        * Use -1.0 to initialize all the area values of the array and empty string for the stateName values initialization.  
 * 2) The public method ReadFile will read each line from the given filename and store each value into the arrays. 
 * Each line of the file contains a stateName and its area separated by a comma. 
        * This method does not return a value.
 * Please note, each line in the file contains a stateName and its area but not necessarily in order, you need to determine if the read value is a stateName or area. 
 * Note: state names will be in lower case only.
 * Hint: stateName will consist of only alphabets and area only of digits.
 * e.g. Data in File can be in following order:
        * alaska,1723337
        * colorado,269601
        * 219882,utah
        * 295234,arizona
* 3) The public method getMaxAreaState returns the name of the state with maximum area.
* You only need to write the class definition and any code that is required for that class.  
* Place all code within the class definition.  Our code will create and test your class.


*/
//#6:
class Country{
    private:
        string stateName[50];
        int area[50];
    public:
        Country(){
            for(int i = 0; i < 50; i++){
                stateName[i] = "";
                area[i] = -1;
            }
        }
    void ReadFile(string filename){
        ifstream myfile;
        myfile.open(filename);
        if(myfile.is_open()){
            string line = "";
            string myline[2];
            int h = 0;
            while(getline(myfile, line)){
                if(isalpha(line[0]) != 0){
                    split(line, ',', myline, 2);
                    stateName[h] = myline[0];
                    area[h] = stoi(myline[1]);
                }else if(isdigit(line[0])!= 0){
                    split(line, ',', myline, 2);
                    stateName[h] = myline[1];
                    area[h] = stoi(myline[0]);
                }
                h++;
            }
        }
        myfile.close();
    }
    string getMaxAreaState(){
        int index = 0;
        int max = 0;
        for(int i = 0; i < 50; i++){
            if(area[i] > max){
                max = area[i];
                index = i;
            }
        }
        return stateName[index];
    }
};

//Or:
class Country{
    private:
        string stateName[50];
        int area[50];
    public:
        Country();// default constructor
        void ReadFile(string file);
        string getMaxAreaState();
};
Country::Country(){
    for(int i=0; i < 50; i++){
        stateName[i] = "";
        area[i] = -1;
    }
}

void Country::ReadFile(string file){
    string newArray[2];
    string line = "";
    char sep = ',';
    int counter = 0;
    
    ifstream my_file;
    my_file.open(file);
    if (my_file.is_open()){
       while (getline(my_file, line ) ){
          split(line, sep, newArray, 2 );
          if(isdigit( newArray[0][0]) ){
              area[counter] = stoi(newArray[0]);
              stateName[counter] = newArray[1];
          }
          else{
              stateName[counter] = newArray[0];
              (area[counter]) = stoi(newArray[1]);
          }
          counter++;
       }
    }
}
string Country::getMaxAreaState(){
    int tempValue = area[0];
    int index = 0;
    for(int i=0; i< 50; i++){
        if(area[i] > tempValue){
            index = i;
            tempValue = area[i];
        }
    }
    return stateName[index];
}

/**Algirithm:1) Create a class named Players with a default constructor, a public methods ReadFile, MaxSalary, and MaxSalaryName and a private data member salaries, 
 * which is an array with 50 floating point values and names which is an array of 50 strings.  
 * Use -1.0 to initialize all the salary values of the array and empty string for the name values initialization.  
 * 2) The public method ReadFile will read each line from the given filename and store each value into the arrays.  
 * The file is in the following format:\
        * Nebula, 1.2
        * The Collector, 3.4
        * Drax, 5.6
        * Ronan, 7.8
        * Gamora, 9.10
    * This method does not return a value.
* 3) The public method MaxSalary returns the maximum salary in the data.
* 4) The public method MaxSalaryName returns the name associated with maximum salary in the data.
* You only need to write the class definition and any code that is required for that class.  Place all code within the class definition.  
* Our code will create and test your class.
*/
//#7:
class Players{
    private:
        float salaries[50];
        string names[50];
    public:
        Players(){
            for(int i = 0; i < 50; i++){
                salaries[i] = -1;
                names[i] = "";
            }
        }
        void ReadFile(string filename){
            ifstream myfile;
            myfile.open(filename);
            if(myfile.is_open()){
                string line = "";
                string myline[2];
                int h = 0;
                while(getline(myfile, line)){
                    split(line, ',', myline, 2);\
                    names[h] = myline[0];
                    salaries[h] = stof(myline[1]);
                    h++;
                }
            }
            myfile.close();
        }
        float MaxSalary(){
            float max = 0;
            for(int i = 0; i < 50; i++){
                if(salaries[i] > max){
                    max = salaries[i];
                }
            }
            return max;
        }
        string MaxSalaryName(){
            int m = 0;
            int y = 0;
            for(int i = 0; i < 50; i++){
                if(salaries[i] > m){
                    m = salaries[i];
                    y = i;
                }
            }
            return names[y];
        }
};


//Or:
class Players{
    private:
        float salaries[50];
        string names[50];
    public:
        Players();
        void ReadFile(string file);
        float MaxSalary();  //returns max salary in the data
        string MaxSalaryName(); //returns nameassociated w/ max salary in the data
};

Players :: Players(){
    for(int i=0; i< 50; i++){
        names[i] = "";
        salaries[i] = -1.0;
    }
}
void Players::ReadFile(string file){
    char sep = ',';
    string line = "";
    int index = 0;
    ifstream my_file;
    my_file.open(file);
    
    if(my_file.is_open()){
        while( getline(my_file, line) ){
            string newArray[2];//first element will be name and second will be salary
            split(line, sep, newArray, 2);
            //hiddentestcase
            if(line.length() != 0){
                for(int i=0; i<50; i++) //setting ith value of salarie to integer
                {
                    salaries[index] = stof(newArray[1]);
                }
                for(int j=0; j<50; j++){
                    names[index] = newArray[0];
                }
            }
            index++;
        }
        my_file.close();
    }
}

float Players::MaxSalary(){
    int tempValue = salaries[0];
    for(int i =0; i< 50; i++){
        if(salaries[i]> tempValue){
            tempValue = salaries[i];
        }
    }
    return tempValue;
}

string Players :: MaxSalaryName(){
    int tempValue = salaries[0];
    int index = 0;
    for(int i =0; i< 50; i++){
        if(salaries[i]> salaries[index]){
            index = i;
        }
    }
    return names[index];
}

/**Algirithm:Create a class (named: Drawing) with a default constructor, a constructor with parameters for each data member, and the following private data members:
    * year, which is an integer value (initialize to 1800 in the default constructor).
    * title,  which is a string (initialize to empty string in the default constructor)
    * artist,  which is a string (initialize to empty string in the default constructor).
* Your second constructor should take all data member variables as input in the order they are specified above.
*/
//#8:DONE
class Drawing{
    private:
        int year;
        string title;
        string artist;
    public:
        Drawing(){
            year = 1800;
            title = "";
            artist = "";
        }
        Drawing(int y, string tit, string art){
            year = y;
            title = tit;
            artist = art;
        }
};

/**Algirithm:Create a class (named: Mural) with a default constructor, a constructor with parameters for each data member, and the following private data members:
        * building,  which is a string (initialize to empty string in the default constructor).
        * year, which is an integer value (initialize to 0 in the default constructor).
        * artist,  which is a string (initialize to empty string in the default constructor).
    * Your second constructor should take all data member variables as input in the order they are specified above.
*/
//#9:
class Mural{
    private:
        string building;
        int year;
        string artist;
    public:
        Mural(){
            building = "";
            year = 0;
            artist = "";
        }
        Mural(string b, int y, string a){
            building = b;
            year = y;
            artist = a;
        }
};

/**Algirithm:Create a class (named: Painting) with a default constructor, a constructor with parameters for each data member, and the following private data members:
        * value, which is a floating point value (initialize to 0 in the default constructor).
        * title,  which is a string (initialize to empty string in the default constructor).
        * artist,  which is a string (initialize to empty string in the default constructor)  
    * Your second constructor should take all data member variables as input in the order they are specified above.
*/
//#10:DONE
class Painting{
    private:
        float value;
        string title;
        string artist;
    public:
        Painting(){
            value = 0.0;
            title = "";
            artist = "";
        }
        Painting(float v, string tit, string art){
            value = v;
            title = tit;
            artist = art;
        }
};

/**Algirithm:Create a class (named: Sculpture) with a default constructor, a constructor with parameters for each data member, and the following private data members:
        * title,  which is a string (initialize to empty string in the default construtor).
        * value, which is a floating point value (initialize to 0 in the default constructor).
        * artist,  which is a string (initialize to empty string in the default constructor).
    * Your second constructor should take all data member variables as input in the order they are specified above.
*/
//#11:DONE
class Sculpture{
    private:
        string title;
        float value;
        string artist;
    public:
        Sculpture(){
            title = "";
            value = 0.0;
            artist = "";
        }
        Sculpture(string tit, float v, string art){
            title = tit;
            value = v;
            artist = art;
        }
};

/**Algirithm:For the given class definition below, make the following three modifications: 
    * 1) add a new public data member that is an array of 10 floating point values called radii
    * 2) add the initialization of the array values to -1.
    * 3) modify the method CalcAverage so that it returns the average of the radii.
    * Note: initialize all elements of the array, but only iterate over the number of elements being used in the array in the calculation method.
    * Start by copy-pasting the class definition below into your editing window.  
    * You only need to write the class definition and any code that is required for that class.  
    * Place all your code within the class definition.
class Star
{
  private: 
    int	numPlanets;    // number of values currently used in array
    
  public:
    Star()  {
        numPlanets = 0;
    }
    
    float CalcAverage() {
    	// <insert code here>
    }
};

*/
//#12:DONE
class Star{
  private: 
    int	numPlanets;    // number of values currently used in array
    float radii[10];
  public:
    Star(){
        numPlanets = 0;
        for(int i = 0; i < 10; i++){
            radii[i] = -1;
        }
    }
    float CalcAverage(){
    	float sum = 0.0;
    	for(int i = 0; i < numPlanets; i++){
    	    sum += radii[i];
    	}
    	return sum/numPlanets;
    }
};