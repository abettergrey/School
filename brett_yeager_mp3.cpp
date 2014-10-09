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
		Started. 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "StackType.h"
string conv_to_post();
int precedence(string n);

int main()
{
	string postfix = conv_to_post();
	cout << postfix <<endl;
	return 0;
}

string conv_to_post() 
{
	StackType<string> infix(30);
	ifstream infile;
	string wholeline;
	string curr;
	string post="";
	string temp;
	string top;
	int count=0;

	//opening and reading file
	infile.open("cs316mp3.dat");

	infile >>wholeline;
	
	
	//while(!infile.eof())
	//{
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
				while(infix.observe()!= "(")
					post=post + infix.pop();
				temp= infix.pop();
			}
		}

		//dumping the stack
		while(!infix.isEmpty())
			post= post + infix.pop();
	//}
	return post;
}

int precedence(string n)
{
	int the_r;


	if(n == "+" || n =="-")
		the_r= 1;
	else if(n == "*" || n== "/")
	{
		the_r=2;
	}

	return the_r;

}


