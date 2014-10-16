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
		
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "StackType.h"
string conv_to_post(string wholeline);
string postfix_to_assembly(string postfix);
int precedence(string n);

int main()
{
	ifstream infile;
	string wholeline;
	infile.open("cs316mp3.dat");
	infile >>wholeline;
	string postfix = conv_to_post(wholeline);
	cout << postfix <<endl;
	while(!infile.eof())
	{
		infile >>wholeline;
		string postfix = conv_to_post(wholeline);
		cout << "PostFix: " << postfix <<endl;
		string as_code = postfix_to_assembly(postfix);
		cout << as_code <<endl;
	}
	return 0;
}

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

