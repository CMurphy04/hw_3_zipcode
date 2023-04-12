/**
 *  @file: zipcode.cc    
 *  @author: Collin Haggerty-Murphy
 *  @date: 3/2/22
 *  @brief get the code for a digit
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

string getDigitCode(char digit){
    int num = digit - '0';

    //case 1 covers digit 1, case 2 covers digit 2, etc.
    switch(num){
        case 1:
            return ":::||";
        case 2:
            return "::|:|";
        case 3:
            return "::||:";
        case 4:
            return ":|::|";
        case 5:
            return ":|:|:";
        case 6:
            return ":||::";
        case 7:
            return "|:::|";
        case 8:
            return "|::|:";
        case 9:
            return "|:|::";
        case 0:
            return "||:::";
    }
}

/**
 * @brief Get the check digit
 * 
 * @param sum sum of the zipcode
 * @return int check digit
 */
int getCheckDigitValue(int sum){
    sum = sum % 10;
    return 10 - sum;
}
 
/**
 * @brief Get the barcode of a zipcode
 * 
 * @param zip zipcode to be converted
 * @return string barcode of the encoded zipcode
 */
string getBarcode(string zip){ //assume the zipcode is valid
    string code = "|";
    int sum = 0;

    for(int i = 0; i < 5; i++){
        code += (getDigitCode(zip[i]) + " ");
        sum += zip[i] - '0';
    }

    code += getDigitCode(char(getCheckDigitValue(sum) + 48)) + "|"; //add the check digit to the end
    
    //code[code.length()-1] = '|'; //replaces the space at the end of the barcode with a "|" to end the barcode

    return code;
}

/**
 * @brief check if an input is a valid zipcode
 * 
 * @param zip input to be evaluated
 * @return true if valid
 * @return false if invalid
 */
bool checkValidZip(string zip){
    if(zip.length() > 5 || zip.length() < 5){
        cout << "Error: zip code must be 5 digits";
        return false;
    }
    for(int i = 0; i < 5; i++){
        if(zip[i] - '0' > 9 || zip[i] - '0' < 0){
            cout << "Error: code contains invalid characters";
            return false;
        }
    }
    return true;
}

int main(){

    bool cont = true;
    while(cont){

        string input;

        cout << "\nEnter a zip code: ";
        cin >> input;

        if(checkValidZip(input)){
            cout << "Code: " << getBarcode(input);
        }

        cout << "\nMore codes (y/n)? ";
        cin >> input;
        
        if(input == "n" || input == "N"){
            cont = false;
        }
    }

    cout << "\nGoodbye!" << endl << endl;
};