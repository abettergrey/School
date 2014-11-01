
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
class Task
{
	private:
		int priority;
		int job_id;
		int exe_time;
		int arive_time;
	public:
		Task(int pri, int id, int e_time, int a_time);
		int get_priority();
		int get_job_id();
		int get_exe_time();
		int get_arive_time();
};

Task::Task(int pri, int id, int e_time, int a_time)
{
	priority = pri;
	job_id = id;
	exe_time = e_time;
	arive_time = a_time;
}


int Task::get_priority()
{return priority;}
int Task::get_job_id()
{return job_id;}
int Task::get_exe_time()
{return exe_time;}
int Task::get_arive_time()
{return arive_time;}

struct CompareTask
{
	bool operator()(Task & t1, Task & t2)
	{
		if(t1.get_priority() < t2.get_priority()) 
			return true;
		if(t1.get_priority() == t2.get_priority() && t1.get_arive_time() < t2.get_arive_time())
			return true;
		return false;
	}
};