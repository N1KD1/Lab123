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

void shaker_sort(student *studs, const int size)
{
	int left=1;
	int right=size-1;
	do
	{
		for(int i =right;i>=left;i--)
		{
			if (studs[i - 1].mark < studs[i].mark)
			{
				student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		left++;
		for (int i = left; i <= right; i++)
		{
			if (studs[i - 1].mark < studs[i].mark)
			{
				student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		right--;
	}
	while (left<=right);
}

void group_count(student *studs, int size)
{

}

void bubble_sort(student *studs, const int size)
{
	bool swapped;
	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			
			if (studs[i].mark < studs[i + 1].mark)
			{
				swapped = true;
				student temp = studs[i];
				studs[i] = studs[i + 1];
				studs[i + 1] = temp;
			}
		}
	}
	while (swapped);
}

void index_search(student *studs, int size)
{
}

void rnd_fill(student *studs, int size)
{
	const string groups[5] = {"ABC","BSD","DOS","EUA","FAQ"};
	srand(time(nullptr));
	for(int i=0;i<size;i++)
	{
		student temp;
		string surname;
		string group;
		const int name = rand() % 6 + 4;
		for(int g = 0;g<name;g++)
		{
			surname.push_back(rand() % 26 + 97);
		}
		temp.group = groups[rand() % 5];
		temp.surname = surname;
		temp.mark = rand() % 60 + 40;
		temp.status = rand() % 2;
		studs[i] = temp;
	}
}

void fill_blank(student *studs, int size)
{
	srand(time(nullptr));
	const student temp = {"aaaa","bbbb",100,true};
	for(int i = 0;i<size;i++)
	{
		studs[i] = temp;
		
	}
}

void group_sort(student* studs, int size)
{
	int left = 1;
	int right = size - 1;
	do
	{
		for (int i = right; i >= left; i--)
		{
			if (studs[i - 1].group[0] > studs[i].group[0])
			{
				student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		left++;
		for (int i = left; i <= right; i++)
		{
			if (studs[i - 1].group[0] > studs[i].group[0])
			{
				student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		right--;
	} while (left <= right);

}

void name_sort(student* studs, int size)
{
		int left = 1;
		int right = size - 1;
		do
		{
			for (int i = right; i >= left; i--)
			{
				if (studs[i - 1].surname[0] > studs[i].surname[0])
				{
					student temp = studs[i];
					studs[i] = studs[i - 1];
					studs[i - 1] = temp;
				}
			}
			left++;
			for (int i = left; i <= right; i++)
			{
				if (studs[i - 1].surname[0] > studs[i].surname[0])
				{
					student temp = studs[i];
					studs[i] = studs[i - 1];
					studs[i - 1] = temp;
				}
			}
			right--;
		} while (left <= right);
}
