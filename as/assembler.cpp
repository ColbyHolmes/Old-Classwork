/*Colby Holmes
Assembler Program*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

string rConvert(char type, string reg);
string binToHex(string temp);

int main()
{
	string choice, fcomm, r1, r2, r3, temp = "", output = "";
	char type;
	int lCount = 0, nLab = 0;
	string labels[10], hexAdd[10];
	int addresses[10];
	
	
	cout << "What is the name of the .asm file to convert (include \".asm\"): ";
	ifstream filedile;
	cin >> choice;
	filedile.open(choice.c_str());


	if (filedile.fail())
	{cout << "File path not opened.\n\n";}

	while (filedile.good())
	{

	
		getline(filedile, fcomm, ' ');

		if (fcomm.compare("add") == 0) //r type
		{
//add binary to temp, once full binary is in temp convert to hex
//opcode goes first
			temp += "000000"; //opcode 1
			type = 'r';			

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100000";//add to end
		}

		else if (fcomm.compare("addi") == 0) //i type
		{
			temp += "001000";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("addiu") == 0) //i type
		{
			temp += "001001";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("and") == 0) //r 
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100100";//funct
		}


		else if (fcomm.compare("andi") == 0) //i
		{
			temp += "001000";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("beq") == 0) //i
		{
			temp += "000100";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r2); //convert rt to binary
			
			//need to gather address from r3
			temp += rConvert(type, r3); 
		}


		else if (fcomm.compare("bne") == 0) //i
		{
			temp += "000101";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary

			//need to gather address from r3
			temp += rConvert(type, r3); 
		}
//**********************************************************************************************
		else if (fcomm.compare("j") == 0) //j
		{
			temp += "000010";

			temp += "00000000000000000000000000"; //temporary placeholder
			getline(filedile, r1, '\n');

/*			int i, num;
			for (i=0; i<nLab; i++)
			{
				if (r1.compare(labels[i]) == 0) //compare label with stored ***not working***
				{
					num = i+1;
					stringstream ss;
					ss << num;		//convert to string 
					string bleh = ss.str();
					temp += rConvert('j', bleh); //convert rd to binary
				}
				//else cry... (what about labels that occur after...)
			}*/			
		}


		else if (fcomm.compare("jal") == 0) //j
		{
			temp += "000011";

			temp += "00000000000000000000000000"; //temporary placeholder
			getline(filedile, r1, '\n');

/*			int i, num;
			for (i=0; i<nLab; i++)
			{
				if (r1.compare(labels[i]) == 0) //compare label with stored ***not working***
				{
					num = i+1;
					stringstream ss;
					ss << num;		//convert to string 
					string bleh = ss.str();
					temp += rConvert('j', bleh); //convert rd to binary
				}
				//else cry... (what about labels that occur after...)
			}*/
		}


		else if (fcomm.compare("jr") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000001000"; //funct
		}


		else if (fcomm.compare("lw") == 0) //i
		{
			temp += "100011";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();


			char c;
			filedile.get(c);	 //pickup offset
			filedile.ignore(1, '(');

			int num = (c - '0') * 4; //need to convert ofset to int then multiply by 4
						
			stringstream ss;
			ss << num;		//convert back to string and format the offset to correct # of bits  
			string oye = ss.str();

			num = strlen(oye.c_str());
			oye = string(16-num, '0').append(oye);
			
			

			getline(filedile, r3, ')');
			filedile.ignore(2, '\n');
			temp += rConvert(type, r3); //convert rs to binary
			temp += rConvert(type, r1); //convert rt to binary
			temp += oye; //add to the end
		}


		else if (fcomm.compare("nor") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100111";
		}


		else if (fcomm.compare("or") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100101";
		}


		else if (fcomm.compare("ori") == 0) //i
		{
			temp += "001101";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("slt") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000101010";
		}

		else if (fcomm.compare("slti") == 0) //i
		{
			temp += "001010";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("sltiu") == 0) //i
		{
			temp += "001011";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore();

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary
		}


		else if (fcomm.compare("sltu") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000101011";
		}


		else if (fcomm.compare("sll") == 0) //r
		{
			temp += "00000000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r1); //convert rs to binary
			temp += rConvert(type, r3); //convert rd to binary

			temp += "000000";
		}


		else if (fcomm.compare("srl") == 0) //r
		{
			temp += "00000000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "000010";
		}


		else if (fcomm.compare("sw") == 0) //i
		{
			temp += "101011";
			type = 'i';

			getline(filedile, r1, ',');
			filedile.ignore();


			char c;
			filedile.get(c);	 //pickup offset
			filedile.ignore(1, '(');

			int num = (c - '0') * 4; //need to convert ofset to int then multiply by 4
						
			stringstream ss;
			ss << num;		//convert back to string and format the offset to correct # of bits  
			string oye = ss.str();

			num = strlen(oye.c_str());
			oye = string(16-num, '0').append(oye);
			
			

			getline(filedile, r3, ')');
			filedile.ignore(2, '\n');
			temp += rConvert(type, r3); //convert rs to binary
			temp += rConvert(type, r1); //convert rt to binary
			temp += oye; //add to the end
		}

		else if (fcomm.compare("sub") == 0) //r
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100010";
		}


		else if (fcomm.compare("subu") == 0) //r 
		{
			temp += "000000"; //opcode 1
			type = 'r';

			getline(filedile, r1, ',');
			filedile.ignore();

			getline(filedile, r2, ',');
			filedile.ignore(1, ' ');

			getline(filedile, r3, '\n');

			temp += rConvert(type, r2); //convert rt to binary
			temp += rConvert(type, r3); //convert rd to binary
			temp += rConvert(type, r1); //convert rs to binary

			temp += "00000100011";
		}
		else 
		{
			
			int size = fcomm.size();
			fcomm.resize(size-1);
			labels[nLab] = fcomm;
			addresses[nLab] = lCount * 4;

			stringstream ss;	//convert to string
			ss << addresses[nLab];
			string bin = ss.str();
			
			bin = rConvert('a', bin); //convert to bin

			hexAdd[nLab] = binToHex(bin);

			nLab++;
			continue;
		}
		

// convert the binary sequence to hex and store in output
		output += "0x";
  		output += binToHex(temp);		
		output += "\n";

		lCount++;
		temp = "";
	}

	filedile.close();
//include labels and addresses in output***


//****TEMPORARY PRINT
	cout << output;

	int i;
	
	cout << "\nLabel\t\tAddress\n";
	for (i=0; i<nLab; i++)
	{
		cout << labels[i] << "\t\t0x" << hexAdd[i] << endl;
	}



//save output to file****
	ofstream aftura;
	aftura.open("output.txt");
	aftura << output << "\nLabel\t\tAddress\n";	
	for (i=0; i<nLab; i++)
	{
		aftura << labels[i] << "\t\t0x" << hexAdd[i] << endl;
	}

	return 0; //exit success
}



//function to convert the registers and immediates to binary
string rConvert(char type, string reg)
{
	string tem;

	if (reg.compare("$t0") == 0)
	{
		tem = "01000";
	}

	else if (reg.compare("$t1") == 0)
	{
		tem = "01001";	
	}

	else if (reg.compare("$t2") == 0)
	{
		tem = "01010";
	}

	else if (reg.compare("$t3") == 0)
	{
		tem = "01011";
	}

	else if (reg.compare("$t4") == 0)
	{
		tem = "01100";
	}

	else if (reg.compare("$t5") == 0)
	{
		tem = "01101";
	}

	else if (reg.compare("$t6") == 0)
	{
		tem = "01110";
	}

	else if (reg.compare("$t7") == 0)
	{
		tem = "01111";
	}

	else if (reg.compare("$s0") == 0)
	{
		tem = "10000";
	}

	else if (reg.compare("$s1") == 0)
	{
		tem = "10001";
	}

	else if (reg.compare("$s2") == 0)
	{
		tem = "10010";
	}

	else if (reg.compare("$s3") == 0)
	{
		tem = "10011";
	}

	else if (reg.compare("$s4") == 0)
	{
		tem = "10100";
	}

	else if (reg.compare("$s5") == 0)
	{
		tem = "10101";
	}

	else if (reg.compare("$s6") == 0)
	{
		tem = "10110";
	}

	else if (reg.compare("$s7") == 0)
	{
		tem = "10111";
	}

	else if (reg.compare("$zero") == 0)
	{
		tem = "00000";
	}

	else //if it is an immediate (convert to decimal, then to binary)
	{
		int num;
		stringstream ss;
		ss << reg;
		ss >> num;
	 	string out;
		while(num!=0) {out=(num%2==0 ?"0":"1")+out; num/=2;}

//need to make sure immediate is the correct number of bits first***
		num = strlen(out.c_str());
		
		if (type == 'r')
		{
			out = string(5-num, '0').append(out); 
		}
		else if (type == 'i')
		{
			out = string(16-num, '0').append(out); 		
		}
		else if (type == 'a')
		{
			out = string(32-num, '0').append(out);
		}
		else if (type == 'j')
		{
			out = string(26-num, '0').append(out);
		}

		tem = out;
 
	}

	return tem;
}

string binToHex(string temp)
{
	int i, j;
	string four = "", output = "";

	for (i = 0; i < 8; i++)
	{
		
		for (j = 0; j < 4; j++)
		{	
			four += temp[j + (i*4)];
		}

		if (four == "1111")
		{

			output += 'F'; //15
		}

		else if (four == "1110")
		{
			output += 'E';	//14
		}

		else if (four == "1101")
		{
			output += 'D'; //13
		}

		else if (four == "1100")
		{
			output += 'C';	//12
		}				

		else if (four == "1011")
		{
			output += 'B'; //11
		}

		else if (four == "1010")
		{
			output += 'A';	//10
		}

		else if (four == "1001")
		{
			output += '9';
		}

		else if (four == "1000")
		{
			output += '8';
		}				

		else if (four == "0111")
		{
			output += '7'; 
		}

		else if	(four == "0110")
		{
			output += '6';	
		}

		else if (four == "0101")
		{
			output += '5'; 
		}

		else if (four == "0100")
		{
			output += '4';
		}				

		else if (four == "0011")
		{
			output += '3';
		}

		else if (four == "0010")
		{
			output += '2';	
		}

		else if (four == "0001")
		{
			output += '1';
		}
		else
		{
			output += '0';
		}				

		four = "";
	}

	return output;
}