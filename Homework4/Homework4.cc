//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Homework 4: 

#include <iostream>
#include <string>
using namespace std;

/**
Algorithim: Finds the best match for a given dna genome and a given dna sequence
	1.The user inputs 3 genomes and a sequence until all of the genomes aren't empty and the sequence isn't longer than the genomes.
	2.This first goes to the best match function which finds the best match in the given genomes for that specific sequence by using the find similarity function.
	3.The best score for each genome is returned.
	4.The genome(s) with the highest similarity score are chosen.
Input paramters: 3 genomes and 1 sequence
Output: The genomes with the highest similarity score to the given sequence.
Return: The genomes with the highest similarity score to the given sequence.

Function 1: take two strings and find the similarity score between those strings. In the case of genomes
equal segments of the genome will be compared to the sequence that is the same length.
*/

//Problem1:
float findSimilarityScore(string sequence1, string sequence2){
	float sequence1length = sequence1.length();
	float sequence2legnth = sequence2.length();

	if (sequence1.length() != sequence2.length()){
		return 0;
	}

	float mismatches = 0.0;

	for (int i = 0; i < sequence1length; i++){
		if (!(sequence1[i] == sequence2[i])){
			mismatches++;
		}
	}
	return (sequence1length - mismatches) / sequence1length;
}

//takes a genome and a sequence and returns the similarity score of the best match found in the genome as a float.
//Problem2:
float findBestMatch(string longone, string two){
    string substring;
    float currentscore = 0;
    float finalscore = 0;
    
    if(longone.length()==0 || two.length()==0){
        return -1;
    }
    if(two.length()>longone.length()){
        return -2;
    }
    for(int i = 0; i < longone.length();i++){ //a counter to divide up the genome into segments that are long as the sequence
        substring = longone.substr(i,two.length());
        currentscore = findSimilarityScore(substring, two);
        if(currentscore > finalscore){
            finalscore = currentscore;
        }
    }
    return finalscore;
}



//Main function:
int main(){
    string genome1;
    string genome2;
    string genome3;
    string seq;

    cout << "Please enter genome 1:" << endl;//We enter the values for the sequence and the genomes here
    cin >> genome1;
    cout << "Please enter genome 2:" << endl;
    cin >> genome2;
    cout << "Please enter genome 3:" << endl;
    cin >> genome3;

    cout << "Please enter a sequence:" << endl;
    cin >> seq;

    if(genome1.length()== 0 || genome2.length()== 0 || genome3.length()== 0 || seq.length()==0)//we say that the genome and the sequence cannot be empty if anyone of them are
    {
        cout << "Genome and sequence cannot be empty." << endl;
    }
    else//if the previous error doesn't happen we check for the next error which is if the sequence length is more than any of the genomes and
    {
        while(seq.length() > genome1.length() || seq.length() > genome2.length() || seq.length() > genome3.length())
            {
                cout << "Sequence cannot be longer than genomes." << endl;
                cout << "Please enter a sequence:" << endl;
                cin >> seq;
            }
       //if it is we keep asking for it
    }


    //we find the best similarity score for each genome here
    float sim1 = findBestMatch(genome1, seq);
    float sim2 = findBestMatch(genome2, seq);
    cout << "";//The silver bullet from the debugging god
    float sim3 = findBestMatch(genome3, seq);
    
    if(sim1 > sim2 && sim1 > sim3){
        cout << "Genome 1 is the best match." << endl;
    }
    else if(sim2 > sim1 && sim2 > sim3){
        cout << "Genome 2 is the best match." << endl;
    }
    else if(sim3 > sim2 && sim3 > sim1){
        cout << "Genome 3 is the best match." << endl;
    }
    else if(sim1 == sim2 && sim1 > sim3){
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
    }
    else if(sim2 == sim3 && sim2 > sim1){
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    else if(sim1 == sim3 && sim1 > sim2){
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    
    else if(sim1==sim2 && sim1==sim3 && sim2==sim3 && genome1.length() > 0 && genome2.length() > 0 && genome3.length() > 0 && seq.length()>0){
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    return 0;
}