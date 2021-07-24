//
//  main.cpp
//  InsertingIntoArrayInSortedOrder
//
//  Created by Satish Singhal on 4/23/19.
//  Copyright © 2019 Satish Singhal. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const size_t MAX = 100;
const int LOWER_BOUND = 0;
const int COUNT = 50;

size_t insertInOrder(int Arr[], int value, size_t current);
void print(int arr[], size_t logical);
int main(int argc, const char * argv[]) {
    int nums[MAX];
    /*
     63    9    99    52    77
     95    2    3    100    14
     */
    size_t len = insertInOrder(nums, 63, 0);
    size_t len1 = insertInOrder(nums, 9, len);
    size_t len2 = insertInOrder(nums, 99, len1);
    size_t len3 = insertInOrder(nums, 52, len2);
    size_t len4 = insertInOrder(nums, 77, len3);
    size_t len5 = insertInOrder(nums, 95, len4);
    size_t len6 = insertInOrder(nums, 2, len5);
    size_t len7 = insertInOrder(nums, 3, len6);
    size_t len8 = insertInOrder(nums, 100, len7);
    size_t len9 = insertInOrder(nums, 14, len8);
    size_t len10 = insertInOrder(nums, 500, len9);

    cout<<"Number of elements in the array: "<<len10<<endl;

    print(nums, len10);
    cout<<"Now adding 50 random numbers and maintaining ascending order"<<endl;
    cout<<"-----------------------"<<endl;
    
    srand((unsigned)time(NULL));    //Seeds the random number generator
    for(int index = LOWER_BOUND; index<COUNT; index++)
    {
        insertInOrder(nums, rand()%100, index);
    }

    print(nums,COUNT);
    return 0;
    /* Note: Rndom number output will be different each time.
     Number of elements in the array: 11
     2  3  9  14  52  63  77  95  99  100  500
     Now adding 50 random numbers and maintaining ascending order
     -----------------------
     1  2  2  5  8  12  13  13  13  14  17  19  25  26  26
     29  32  33  35  35  42  46  48  48  50  53  53  55
     60  61  62  64  66  69  69  73  75  75  75  77  77
     80  83  84  85  86  87  94  94  95
     */
}

size_t insertInOrder(int Arr[], int value, size_t current)
{
    size_t len = 0;
    
    if(current == 0)
    {
        Arr[0] = value;
        len = 1;
    }
    else if(current == 1)
    {
        if(value>= Arr[0])
        {
            Arr[1] = value;
        }
        else
        {
            Arr[1] = Arr[0];
            Arr[0] = value;
        }
        len = 2;
    }
    else
    {
        //find the index to add
        
        size_t i = 0;
        
        while ( i<current && i<MAX)
        {
            if (value>Arr[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        //Case that value is larger than all elements currently in the array
        // Add as last element in the array
        if (i == current && current<MAX)
        {
            Arr[i] = value;
            len = current + 1;
        }
        
        else
        {
            
             if (current == MAX)
             {
                throw "There is no more room in the array.";
            }
            // Below is the case that Arr[i] is in the middle of array somewhere
            // then
            //1. All elements from i to <current index must be moved by one
            //index over
            //2. After that add value to location i
            //3. len = curent++
            
            if(i<current)
            {
                for (size_t j = current; j>i; )
                {
                    Arr[j] = Arr[j-1];
                    --j;
                    if (j == i) {
                        break;
                    }
                }
                Arr[i] = value;
                len = current + 1;
            }
        }
    }
    
    return len;
}

void print(int arr[], size_t logical)
{
    for (size_t i = 0; i<logical; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
