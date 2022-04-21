#include "student_array.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;	

void show_array(const student *studs, int size)
{
	cout <<setw(3) <<left << "#" << setw(10) << "SURNAME" << setw(10) << "GROUP" << setw(6) <<left<< "MARK" << setw(7) << right<< "STATUS\n";
	for(int i =0;i<size;i++)
	{
		cout << setw(3) << left << i + 1 << setw(10) << studs[i].surname << setw(10) << studs[i].group << setw(6)<<left << studs[i].mark << setw(7)<<right;
		if(!studs[i].status)
		{
			cout << "Contract\n";
		}
		else
		{
			cout << "Budget\n";
		}
	}
}


void shaker_sort(student *studs, int size)
{
}

void group_count(student *studs, int size)
{
}

void bubble_sort(student *studs, int size)
{
}

void index_search(student *studs, int size)
{
}

void rnd_fill(student *studs, int size)
{
}

void fill_blank(student *studs, int size)
{
	student temp = {"aaaa","bbbb",100,true};
	for(int i = 0;i<size;i++)
	{
		studs[i] = temp;
	}
}
