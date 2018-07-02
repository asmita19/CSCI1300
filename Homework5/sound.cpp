//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 7

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/**
   Processes the sound samples. Modify this function to change
   the way the sound is processed.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void process(int samples[], int size) {
    // Here, we make the sound three times as loud

   for (int i = 0; i < size; i++){
      samples[i] = 3 * samples[i];
   }
}

// your function reverse() goes here
/**Algorithm: Processes the sound samples. 
 * Reverses the values in the samples array.
 * @param samples the sound samples in the sound file
 * @param size the number of samples
*/

void reverse(int samples[], int size){
    int newSam[size];//declares new array 
    for(int i = 0; i < size; i++){//loop to copy samples array to newSam array
        newSam[i] = samples[i];
    }
    for(int i = 0; i < size; i++){//loo to reverse the array using newArrays variables
        samples[i] = newSam[size - (i + 1)];//replacing 0th index of samples array with (size -1)st index of newSam array
    }
}

/**Algorithm:/**
   Processes the sound samples. Adds an echo to the samples array: 
   Take a sample and replace it by the sum of its original value and 
   another value, from "delay" seconds earlier.  
   @param samples the sound samples in the sound file
   @param size the number of samples
   @param sample_rate the number of samples per second
   @param delay the number of seconds echo delay
*/
//Problem2:
void add_echo(int samples[], int size, int sample_rate, double delay){
    int newSam[size];
    for(int i = 0; i < size; i++){//for loop to make the newSam array variable equal to smaples array variable
        newSam[i] = samples[i];
    }
    for(int j = (sample_rate * delay); j < size; j++){
        samples[j] = newSam[j] + newSam[j - (int)(sample_rate * delay)];
    }
}


/**Algorithm:take two parameters: array samples of int type and the size of this array in this order
1. It does not return anything
2. it must be named normalize
3. Normalizing the sound samples array is a two step process.

Finds the maximum (highest) value in the samples array.

Multiplys all values in the samples array by 36773 and divide by the maximum value. 
*/
//Problem3:
void normalize(int samples[], int size){
   int maxVal = 0;
   for(int i = 0; i < size; i++){
      if(samples[i] > maxVal)
      {
          maxVal = samples[i];
      }
   }
  for(int i = 0; i < size; i++){
      samples[i] = (samples[i]*36773)/maxVal;
  }
}

/*
  The code below processes a file in the WAV format.
  You can use this program to manipulate sound files without 
  reading or understanding the code below. 

  The code uses C++ features that are introduced in chapters 7 and 8, 
  as well as the internals of the WAV format 
  (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/)
*/

/**Gets an unsigned 4-byte integer from a binary stream.
   @param stream the stream
   @return the integer 
*/ 
int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

/**
   Gets an unsigned 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}

/**
   Gets a signed 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}

/**
   Puts a signed 2-byte integer to a binary stream.
   @param stream the stream
   @param value the integer to put
*/
void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   // Process sound data
   process(samples, data_size);

   // Replace "Process sound data" and the call to the process 
   // function with option A or option B below

   // A. Reverse
   // 1. Call the reverse function

   // B. Add echo
   // 1. Declare and initialize variable for echo delay
   // 2. Call the add_echo function
   // 3. Call the normalize function

   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}
