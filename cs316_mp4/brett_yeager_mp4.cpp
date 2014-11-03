//************************************
//Programer: Brett Yeager
//Course Title: CS316
//Assignment no: MP4
//Instructor: Dr. Tai-Chi Lee
//************************************
//Program Definition:
//	This programs purpose is to show the use
//	of a priority queue. It is broken into
//	three phases:
//		1. Read in 10 taskts and put them in the 
//			queue.
//		2. Loop through the pop's of the 
//			queue and simpulate a cpu's
//			clock cycle
//*************************************
//
// NO GLOBAL VAR USED
//*************************************
/* Developmet History
	11/1/2014
		Started project
		Created task object
		Create an overloader for the queue 
			comparison
		Created phase one
		Created phase two
*/

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "Header.h"
using namespace std;

int main()
{
	int clock_time = 0, total_exe = 0, ave_wait = 0, ave_turnaround = 0;
	priority_queue<Task, vector<Task>,CompareTask> my_queue;
	ifstream infile;
	int pri, id, in_time;
	infile.open("cs316mp4.dat");
	for(int i = 0; i < 10; i++)
	{
		infile >>pri >> id >> in_time;
		cout <<"Input Read: "<<pri<<" "<< id <<" "<<in_time<<endl;
		my_queue.push(Task(pri, id, in_time, 0));
	}
	while(!my_queue.empty())
	{
		Task current_task = my_queue.top();
		cout <<"Process Scheduled: pid = " <<current_task.get_job_id();
		cout <<", priority = " <<current_task.get_priority();
		cout <<", waiting time = " << clock_time - current_task.get_arive_time();
		cout <<", turnaround time = " <<(clock_time - current_task.get_arive_time()) +current_task.get_exe_time() <<endl <<endl;

		total_exe++;
		ave_wait += clock_time - current_task.get_arive_time();
		ave_turnaround += (clock_time - current_task.get_arive_time()) +current_task.get_exe_time();

      	my_queue.pop();
		if(!infile.eof())
		{
			infile >>pri >> id >> in_time;
			cout <<"Input Read: "<<pri<<" "<< id <<" "<<in_time<<endl <<endl;
			my_queue.push(Task(pri, id, in_time, clock_time));
		}

		clock_time += current_task.get_exe_time() +1;
	}
	infile.close();
	cout <<"The total number of jobs executed = " <<total_exe <<endl;
	cout <<"The total execution time = " <<clock_time<<endl;
	cout <<"The average waiting time = " << ave_wait / total_exe <<endl;
	cout <<"The average turnaround time = " <<ave_turnaround / total_exe <<endl;
	cout <<"The system throughtput = " <<(total_exe + .0) / (clock_time + .0) <<endl;
	return 0;
}