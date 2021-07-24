//
//  main.cpp
//  ConvertBinaryToHexAndBack
//
//  Created by Satish Singhal on 3/10/19.
//  Copyright © 2019 Satish Singhal. All rights reserved.
//
/*
 This program would take user input for either binary number and
 convert to HEX or vice versa. Only strings and arrays and functions are
 allowed to be used.
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void BinaryToHex();
void HexToBinary();
void ConvertOneBinGroupToHex(const string & bin, string & Hex);
void PaddingFunction (const string & original, string & Padded);
void ConvertOneHexToBin(const string & OneHexDig, string & bin);
int main()
{
	char phrase[20] = "Hello World";
	cout << (*phrase[0]) << endl;
	/*
    bool done = false;
    
    while (!done) {
        cout<<"*******Main Menu**********"<<endl
        <<"1. Convert binary to Hex."<<endl
        <<"2. Convert Hex to binary."<<endl
        <<"3. Exit."<<endl;
        int choice;
        cin>>choice;
        
        if (choice == 1) {
            BinaryToHex();
        }
        else if (choice == 2) {
            HexToBinary();
        }
        else if(choice == 3){
            done = true;
        }
        else{
            cout<<"This choice is not yet implemented."<<endl;
        }
    }
	*/
	//loop
	system("pause");
    return 0;
}
void PaddingFunction (const string & original, string & Padded)
{
    size_t howMany =  4 - original.length() % 4;
    Padded = original;
    
    for (size_t i = 0; i<howMany; i++) {
        Padded = "0"+ Padded;
    }
}
void BinaryToHex()
{
    string binNumber;
    cout<<"Enter your binary number. There should be no leading zeros in the inputted number: ";
    cin>>binNumber;
    //1. Get size
    size_t len = binNumber.length();
    //2. If len is not exact multiple of 4, then we must
    // pad with leading zeros, until it becomes multiple of 4
    if (len%4 == 0) {
        //OK it is multiple of 4, so we can take groups of 4
        // digits and convert each to Hex
        // In each loop iteration, we would take 4 digits
        // at a time and convert each group to Hex
        //Thus number of iterations are
        string MyHex;
        size_t count = 0;
        
        while(count<len){
            string group = binNumber.substr(count, 4);
            //Need a function that can convert group to HEX
            // and return the string by reference.
            string tempHex;
            ConvertOneBinGroupToHex(group,tempHex);
            MyHex+=tempHex;
            count = count + 4;
        }//end of while
        cout<<"Bianry Number: "<<binNumber<<endl
        <<"Hex Equivalent: "<<MyHex<<endl;
    }// end of if
    else{
        // Need to pad with leading zeros until binNumber
        //becomes multiple of 4
        string Padded;
        PaddingFunction(binNumber,Padded);
        string MyHex;
        size_t count = 0;
        len = Padded.length();
        
        while(count<len){
            string group = Padded.substr(count, 4);
            //Need a function that can convert group to HEX
            // and return the string by reference.
            string tempHex;
            ConvertOneBinGroupToHex(group,tempHex);
            MyHex+=tempHex;
            count = count + 4;
        }//end of while
        cout<<"Bianry Number: "<<binNumber<<endl
        <<"Binary number after padding: "<<Padded<<endl
        <<"Hex Equivalent: "<<MyHex<<endl;
    }// else block
}// function
void ConvertOneBinGroupToHex(const string & bin, string & Hex)
{
    if (bin == "0000") {
        Hex = "0";
    }
    else if(bin == "0001")
    {
        Hex = "1";
    }
    else if(bin == "0010")
    {
        Hex = "2";
    }
    else if(bin =="0011")
    {
        Hex = "3";
    }
    else if(bin =="0100")
    {
        Hex = "4";
    }
    else if(bin == "0101")
    {
        Hex = "5";
    }
    else if(bin == "0110")
    {
        Hex = "6";
    }
    else if(bin == "0111")
    {
        Hex = "7";
    }
    else if(bin == "1000")
    {
        Hex = "8";
    }
    else if(bin == "1001")
    {
        Hex = "9";
    }
    else if(bin == "1010")
    {
        Hex = "A";
    }
    else if(bin == "1011")
    {
        Hex = "B";
    }
    else if(bin == "1100")
    {
        Hex = "C";
    }
    else if(bin == "1101")
    {
        Hex = "D";
    }
    else if(bin == "1110")
    {
        Hex = "E";
    }
    else if(bin == "1111")
    {
        Hex = "F";
    }
}// function

void ConvertOneHexToBin(const string & OneHexDig, string & bin)
{
    if (OneHexDig == "0") {
        bin = "0000";
    }
    else if(OneHexDig == "1") {
        bin = "0001";
    }
    else if(OneHexDig == "2") {
        bin = "0010";
    }
    else if(OneHexDig == "3") {
        bin = "0011";
    }
    else if(OneHexDig == "4") {
        bin = "0100";
    }
    else if(OneHexDig == "5") {
        bin = "0101";
    }
    else if(OneHexDig == "6") {
        bin = "0110";
    }
    else if(OneHexDig == "7") {
        bin = "0111";
    }
    else if(OneHexDig == "8") {
        bin = "1000";
    }
    else if(OneHexDig == "9") {
        bin = "1001";
    }
    else if(OneHexDig == "A") {
        bin = "1010";
    }
    else if(OneHexDig == "B") {
        bin = "1011";
    }
    else if(OneHexDig == "C") {
        bin = "1100";
    }
    else if(OneHexDig == "D") {
        bin = "1101";
    }
    else if(OneHexDig == "E") {
        bin = "1110";
    }
    else if(OneHexDig == "F") {
        bin = "1111";
    }
}//Function
void HexToBinary()
{
    string MyHex;
    cout<<"Enter Hex number without leading zeros: ";
    cin>>MyHex;
    string bin;
    for (size_t i = 0; i<MyHex.length(); i++) {
        string str = "";
        
        if(isalpha(MyHex[i]))
        {
            MyHex[i] = toupper(MyHex[i]);
        }
        str = str + MyHex[i];
        string tempBin;
        ConvertOneHexToBin(str,tempBin);
        bin+=tempBin;
    }
    cout<<"Hexadecimal number: "<<MyHex<<endl
    <<"Binary Equivalent: "<<bin<<endl;
}
    /**
     output
     Enter a Hex number:
     dead
     The binary form of Hex number DEAD
     = 1101111010101101
     ***************************************
     Enter a Hex number:
     BEEF
     The binary form of Hex number BEEF
     = 1011111011101111
     **************************************
     Enter a Hex number:
     bee
     The binary form of Hex number BEE
     = 101111101110
     ....................................
     Enter a Hex number:
     fee
     The binary form of Hex number FEE
     = 1111 1110 1110
     ***********************************
     Enter a Hex number:
     DAD1
     The binary form of Hex number DAD1
     = 1101 1010 1101 0001
     ************************************
     Enter a Hex number:
     1dad
     The binary form of Hex number 1DAD
     = 0001 1101 1010 1101
     ************************************
     Enter a Hex number:
     dada
     The binary form of Hex number DADA
     = 1101 1010 1101 1010
     *********************************
     Enter a Hex number:
     deaf
     The binary form of Hex number DEAF
     = 1101 1110 1010 1111
     ************************************
     Enter a Hex number:
     bead
     The binary form of Hex number BEAD
     = 1011 1110 1010 1101
     ************************************
     */

    /**
     Enter a valid binary number, with no more than 32 digits.
     1111111
     01111111
     
     Hex of binary 1111111
     = 7F
     ************************************
     Enter a valid binary number, with no more than 32 digits.
     1001111
     01001111
     
     Hex of binary 1001111
     = 4F
     ****************************************
     Enter a valid binary number, with no more than 32 digits.
     101111
     00101111
     
     Hex of binary 101111
     = 2F
     *************************************************
     Enter a valid binary number, with no more than 32 digits.
     11111
     00011111
     
     Hex of binary 11111
     = 1F
     ***************************************************
     Enter a valid binary number, with no more than 32 digits.
     100101
     00100101
     
     Hex of binary 100101
     = 25
     ********************************************************
     Enter a valid binary number, with no more than 32 digits.
     1000111100011111
     1000111100011111
     
     Hex of binary 1000111100011111
     = 8F1F
     **************************************************
     Enter a valid binary number, with no more than 32 digits.
     100011110001111
     0100011110001111
     
     Hex of binary 100011110001111
     = 478F
     **********************************************
     Enter a valid binary number, with no more than 32 digits.
     10001111000111
     0010001111000111
     
     Hex of binary 10001111000111
     = 23C7
     ***********************************************
     Enter a valid binary number, with no more than 32 digits.
     1000111100011
     0001000111100011
     
     Hex of binary 1000111100011
     = 11E3
     **********************************************
     Enter a valid binary number, with no more than 32 digits.
     100011110001
     100011110001
     
     Hex of binary 100011110001
     = 8F1
     **********************************
     Enter a valid binary number, with no more than 32 digits.
     10001111000
     010001111000
     
     Hex of binary 10001111000
     = 478
     ********************************
     Enter a valid binary number, with no more than 32 digits.
     1000111100
     001000111100
     
     Hex of binary 1000111100
     = 23C
     */

    /**
     output example
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     4
     Enter an Octal number:
     17
     The binary form of Octal number 17
     = 001 111
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     
     4
     Enter an Octal number:
     12
     The binary form of Octal number 12
     = 001 010
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     4
     Enter an Octal number:
     71
     The binary form of Octal number 71
     = 111 001
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     4
     Enter an Octal number:
     43
     The binary form of Octal number 43
     = 100 011
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     4
     Enter an Octal number:
     51
     The binary form of Octal number 51
     = 101 001
     ******Main Menu******
     1. Convert binary to hexadecimal.
     2. Convert hexadecimal to binary.
     3. Convert binary to Octal.
     4. Convert octal to binary.
     5. Convert Octal to Hexadecimal.
     6. Convert Hexadecimal to Octal.
     7. Exit.
     4
     Enter an Octal number:
     67123
     The binary form of Octal number 67123
     = 110 111 001 010 011
     */

