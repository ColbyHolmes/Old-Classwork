/*Colby Holmes
Float Multiplication Program*/
/*When I entered the example input into a binary calculator, it gave me a 
different result than the example. (Mine matches up to the result of the calculator.)
Please check this. Also, I recoded it several times before I checked it because it
didn't turn out like the example... Please fix it so in the future, students don't
waste hours of their time trying to break something that is correct.*/ 

//lots of included header files
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <string.h>
#include <cmath>
using namespace std;


//lots of functions
string hex2bin(string h);
string sepbits(string b, int code);
string addBitStrings(string first, string second);
string twosComp(string bin);
string DecToBin(long number);
int BinToDec(string number);
string mult(string bin1, string bin2);
string norm(string yeah, int* one);
char sign(char sign1, char sign2);


//main function
int main()
{
//declare variables
	string hex1, hex2, bin1, bin2, exp1, exp2, expRes;
	string expFin, sig1, sig2, sigRes, sigResN,  product = "", form = "";
	char sign1, sign2, signRes;
	int offset = 0;

//send startup message and catch user input
	cout << "Colby Holmes - Assignment 2\n\nEnter a single precision floating point (in hex): ";
	cin >> hex1;

	cout << "\nEnter another single precision floating point (in hex): ";
	cin >> hex2;


	cout << "\n\n**********************************";
//convert to binary
	bin1 = hex2bin(hex1);
	bin2 = hex2bin(hex2);

//pull sign bits
	sign1 = bin1[0];
	sign2 = bin2[0];

//pull exponents	
	exp1 = sepbits(bin1, 0);
	exp2 = sepbits(bin2, 0);

//pull significants
	sig1 = sepbits(bin1, 1);
	sig2 = sepbits(bin2, 1);

//add exponents
	expRes = addBitStrings(exp1, exp2);
	expRes = twosComp(expRes);
//exp -127
	expRes = addBitStrings(expRes, "10000001");


	cout << "\n\n\tStep 1 - Add the exponents\n\tResult (in binary): " << expRes;
//multiply sigs
	sigRes = mult(sig1, sig2);

	cout << "\n\n\tStep 2 - Multiply the significands\n\tResult (in binary): " << sigRes;

//Normalize significand
	sigResN = norm(sigRes, &offset);
	expFin = DecToBin((long) offset);

//bandaid to fix offset length
	if( expFin.length() < 8)
	{
		int diff = 8 - expFin.length();
		int i;
		for (i=0; i<diff; i++)
		{
			form += "0";
		}
		form += expFin;
	}

	expFin = addBitStrings(expRes, form);

	cout << "\n\n\tStep 3 - Normalize the significand\n\tResult of fraction (in binary): ";
	cout << sigResN << "\n\tResult of exponent (in binary): " << expFin;

//Sign
	signRes = sign(sign1, sign2);
	cout << "\n\n\tStep 4 - Determine the sign\n\tResult (in binary): " << signRes;

//product
	product += signRes;
	product += expFin;
	product += sigResN;

	cout << "\n\n\tProduct (in hex): ";
    	bitset<32> set(product);  
    	cout << hex << set.to_ulong() << "\n\n\n********************************\n";
		
	return 0;
}



//convert hex input to binary
string hex2bin(string h)
{
//stringstream and bitset make this conversion easy
	stringstream ss;
    	ss << hex << h;
    	unsigned n;
    	ss >> n;
    	bitset<32> b(n);
	
	return b.to_string();

}



//separate the bits into their respective parts
string sepbits(string b, int code)
{
	int i;
	string sect = "";
//if pulling exponents
	if(code == 0)
	{
		for(i=1; i<9; i++)
		{
			sect += b[i];
		}

	}	
//if pulling significants
	else
	{
		for(i=9; i<33; i++)
		{
			sect += b[i];
		}

	}

	return sect;
}



//adds two bit sequences and returns the sum
string addBitStrings(string first, string second)
{
    	string result;  // To store the sum bits
    	int length = 8;
 
    	int carry = 0;  // Initialize carry
 
// Add all bits one by one
    	for (int i = length-1 ; i >= 0 ; i--)
    	{
        	int firstBit = first.at(i) - '0';
        	int secondBit = second.at(i) - '0';
 
// boolean expression for sum of 3 bits
        	int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        	result = (char)sum + result;
 
// boolean expression for 3-bit addition
        	carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    	}
 
    	return result;
}


//twos complement conversion
string twosComp(string bin)
{
	bitset <8> bset(bin);
	bset.flip();
	for (int i = 0; i < bset.size(); i ++) 
	{
    		if (bset[i])
        		bset[i] = 0;
    		else 
		{
        		bset[i] = true;
        		break;
    		}
	}

	return bset.to_string();
}


//converts decimal to binary
string DecToBin(long number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}


//converts binary to decimal
int BinToDec(string number)
{
    	int result = 0, pow = 1, counter;

  	for(counter = 0; counter < number.size(); counter++)
    		if(number.c_str()[counter] == '1')
//BUG in version of C++ requires "std" before pow function
      			result += std::pow(2, counter);

    	return result;
}


//multiplies binary strings
string mult(string bin1, string bin2)
{
	string result;
	long dec1, dec2, res;

//convert to decimal to make easy
	dec1 = BinToDec(bin1);
	dec2 = BinToDec(bin2);

	res = dec1 * dec2;

//convert back to binary
	result = DecToBin(res);
//format the length
	while( result.length() < 48)
	{
		result += "0";
	}

	
	return result;
}


//normalize the significand
string norm(string yeah, int* one)
{
	int i, j;
	string yah = "                             ";
//find first '1'
	for (i=0; i<=32; i++)
	{
		if (yeah[i] == '1')
		{
//update offset
			*one = i+1;
//normalize
			for (j=0; j<23; j++)
			{
				if(yeah[i+j+1] != '\0')
				{
					yah[j] = yeah[i+j+1];
				}
				else
					yah += '0';
			}
			return yah;
		}
	}
	cout << "Error Normalizing";
	return "Error";
}



//find result sign
char sign(char sign1, char sign2)
{
	if( (sign1 == '0' && sign2 == '0') || (sign1 == '1' && sign2 == '1') )
	{
		return '0';
	}
	else
		return '1';
}



/*This program was made vastly more difficult because the CSE Machines are grossly
outdated. PLEASE talk to someone about at least updating to a newer build of C++.
There are many library functions that make life easier for everyone, and in real
world scenarios, companies definitely don't want me reinventing the wheel when
I don't need to.*/