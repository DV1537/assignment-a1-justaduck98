
#include <iostream>

#include <fstream>

#include <string>

#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int arraySize = 1;
    int counter = 0;
    ifstream inFile;
    inFile.open("inputNumbers.txt");
    if (inFile.fail())
    {
        printf("Error opening input file.\n");
        exit(1);
    }
    float *inputArray = new float[arraySize];
    float *copyArray = new float[arraySize+1];
    while (!inFile.eof())
    {
        inFile >> inputArray[counter];
        counter++;

        if (counter == arraySize)
        {
            arraySize++;
            for (int k = 0; k < arraySize-1; k++)
            {
                copyArray[k] = inputArray[k];
            }
            cout << endl;
            delete inputArray;
            inputArray = new float[arraySize];
            for (int k = 0; k < arraySize-1; k++)
            {
                inputArray[k] = copyArray[k];
            }
            cout << endl;
            delete copyArray;
            copyArray = new float[arraySize];
        }

    }
    float sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += inputArray[i];
    }
    sum = sum / counter;
    float average = sum;
    counter = 0;

    for (int j = 0; j < arraySize; j++)
    {
        if (inputArray[j] > sum)
        {
            if (counter == 0)
            {
                printf("These numbers are bigger than the average:\n");
            }
            printf("%.3f\n", inputArray[j]);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("There were no numbers bigger than the average. ");
    }
    return 0;
}
