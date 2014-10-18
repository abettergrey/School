//************************************
//Programer: Brett Yeager
//Course Title: CS316
//Assignment no: MP3
//Instructor: Dr. Tai-Chi Lee
//************************************
//Program Definition:
//	This program is broken into three parts:
//		1. Read in a infix equation and converts it into postfix
//		2. Take postfix equation and create assembly code
//		3. Take assembly code and create binary code
//*************************************
//
// NO GLOBAL VAR USED
//*************************************
/* Developmet History
	10/8/2014:
		Started. Created stack and conversion to post.
        Need to fix bug where inproper infix causes
        segmentation fault.
    10/13/2014
    	Fixed bug. Inproper infix now regected.
    10/14/2014
    	Started turning postfix into assembly code.
	10/15/2014
		Finished convertion to assembly code.
	10/18/2014
		Created a function to convert assembly
		to binary. 
		
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "StackType.h"
string conv_to_post(string wholeline);
string postfix_to_assembly(string postfix);
int precedence(string n);
string assembly_to_binary(string assem_code);

int main()
{
	ifstream infile;
	string wholeline;
	infile.open("cs316mp3.dat");
	infile >>wholeline;
	string postfix = conv_to_post(wholeline);
	cout << postfix <<endl;
	cout << "PostFix: " << postfix <<endl;
	if(postfix != "INPROPER INFIX!")
	{
		cout << "Assembly Code:" <<endl;
		string as_code = postfix_to_assembly(postfix);
		cout << as_code <<endl;
		cout << "Binary Code:" <<endl;
		string bin_code = assembly_to_binary(as_code);
		cout << bin_code <<endl;
	}
	else
	{
		cout << "Cannot convert to Postfix. Skipping convertions." << endl <<endl; 
	}
	cout << "-----------------------------------" <<endl;
	while(!infile.eof())
	{
		infile >>wholeline;
		string postfix = conv_to_post(wholeline);
		cout << "PostFix: " << postfix <<endl;
		if(postfix != "INPROPER INFIX!")
		{
			cout << "Assembly Code:" <<endl;
			string as_code = postfix_to_assembly(postfix);
			cout << as_code <<endl;
			cout << "Binary Code:" <<endl;
			string bin_code = assembly_to_binary(as_code);
			cout << bin_code <<endl;
		}
		else
		{
			cout << "Cannot convert to Postfix. Skipping convertions." << endl <<endl; 
		}
		cout << "-----------------------------------" <<endl;
	}
	return 0;
}

//converts a infix expression to a postfix
string conv_to_post(string wholeline) 
{
	StackType<string> infix(30);

	string curr;
	string post="";
	string temp;
	string top;
	int count=0;
	bool bad_infix = false;

	
		//printing infix
		cout<<"Infix: "<<wholeline<<endl;

		//looping until postfix is done
		while(count < wholeline.length())
		{
			//curr is the focus point
			curr= wholeline.substr(count, 1);
			if(infix.isEmpty() ==false)
				top= infix.observe();
	
			count++;
		
			//appending if varible
			if(curr >= "A" && curr <="Z")
				post=post+curr;

			if(curr== "*" || curr =="/" || 
				curr =="+" || curr =="-")
			{
				while(top != "(" &&
					precedence(top) >= precedence(curr) &&
					infix.isEmpty()==false)
				{
					post=post+ infix.pop();
				}
				infix.push(curr);
			}

			if(curr=="(")
				infix.push(curr);
	
			if(curr== ")")
			{
				while(!bad_infix && infix.observe()!= "(")
				{
					post=post + infix.pop();
					if(infix.isEmpty())
						bad_infix = true;
				}
				if(!bad_infix)
					temp= infix.pop();
			}
		}

		//dumping the stack
		while(!infix.isEmpty() && !bad_infix)
			post= post + infix.pop();
		if(bad_infix)
			post = "INPROPER INFIX!";
	return post;
}

//assigns precedence for operators 
int precedence(string n)
{
	int the_r = 0;

	if(n == "+" || n =="-")
		the_r= 1;
	else if(n == "*" || n== "/")
	{
		the_r=2;
	}

	return the_r;

}

//converts postfix to assembly
string postfix_to_assembly(string postfix) 
{
	string assembly = "";
	int temp_count = 0;
	StackType<string> stack(30);
	for(int i =0; i < postfix.length(); i++)
	{
		string curr = postfix.substr(i,1);
		if(curr >= "A" && curr <="Z")
			stack.push(curr);
		else
		{
			string op2 = stack.pop();
			if(stack.isEmpty())
				return "Not sufficient values in the expression";
			else
			{
				string op1 = stack.pop();
				assembly = assembly + "LD " + op1 + "\n";
				if(curr == "+")
					assembly = assembly + "AD " + op2 + "\n";
				else if(curr == "-")
					assembly = assembly + "SB " + op2 + "\n";
				else if(curr == "*")
					assembly = assembly + "ML " + op2 + "\n";
				else
					assembly = assembly + "DV " + op2 + "\n"; 
				temp_count++;
				assembly = assembly + "ST TEMP" + to_string(temp_count) + "\n";
				stack.push("TEMP" + to_string(temp_count));
			}
		}
	}
	return assembly;
}

//converts assembly to binary code
string assembly_to_binary(string assem_code)
{
	string memery[30] = {"00000110", "00000111", "00001000", "00001001",
						"00001010", "00001011", "00001100", "00001101",
						"00001110", "00001111", "00010000", "00010001",
						"00010010", "00010011", "00010100", "00010101",
						"00010110", "00010111", "00011000", "00011001",
						"00011010", "00011011", "00011100", "00011101",
						"00011110", "00011111", "00100000", "00100001"};
	string output = "";
	int curr_mem = 0;
	int curr_pos = 0;
	while ((curr_pos = assem_code.find(" ")) != std::string::npos)
	{
		string code_in = assem_code.substr(0, curr_pos);

		if(code_in == "LD")
			output += "0000";
		else if(code_in == "ST")
			output += "0001";
		else if(code_in == "AD")
			output += "0010";
		else if(code_in == "SB")
			output += "0011";
		else if(code_in == "ML")
			output += "0100";
		else if(code_in == "DV")
			output += "0101";
		else
		{
			output += memery[curr_mem];
			curr_mem++;
		}
		assem_code.erase(0, curr_pos + 1);
	}
	return output;
	
}

