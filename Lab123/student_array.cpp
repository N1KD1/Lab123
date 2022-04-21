#include "student_array.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;	

void show_array(const student *studs, const int size)  //typing array as a table
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

void shaker_sort(student *studs, const int size) //shaker sort
{
	int left=1;
	int right=size-1;
	do
	{
		for(int i =right;i>=left;i--)
		{
			if (studs[i - 1].mark < studs[i].mark)
			{
				const student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		left++;
		for (int i = left; i <= right; i++)
		{
			if (studs[i - 1].mark < studs[i].mark)
			{
				const student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		right--;
	}
	while (left<=right);
}

int distinct_count(const student *studs, const int size) //counts how many groups in array
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		while (i < size - 1 && studs[i].group == studs[i + 1].group) {
			i++;
		}
		count++;
	}
	return count;
}

void group_count(const student *studs, int size) //counts students in every group
{
	const int amount = distinct_count(studs, size);
	int left = 0;
	for(int g = 0;g<= amount;g++)
	{
		
		if (g == amount)
		{
			cout << "In " << studs[left].group << " is ";
			cout << size-left << " students\n";
			break;
		}
		string temp;
		int counter=0;
		for (int i = left; i < size; i++)
		{
			if(studs[left].group == studs[i].group)
			{
				++counter;
			}
			else
			{
				cout << "In " << studs[left].group << " is ";
				cout << counter << " students\n";
				left = i;
				break;
			}
		}
	}
}

void bubble_sort(student *studs, const int size) //bubble sort
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
				const student temp = studs[i];
				studs[i] = studs[i + 1];
				studs[i + 1] = temp;
			}
		}
	}
	while (swapped);
}

void index_search(const std::string& key, const student* studs, const int size, std::string* index, const int step) // index sequential search
{
	int found_word = 0;
	int found_key = 0;
	constexpr int accuracy = 4; // key.size() for ideal search or length of smallest word for comfort/fast search 
	for (int i = 0; i < size / step; i++)
	{
		index[i] = studs[i * step].surname;
	}
	for (int i = 0; i < size / step; i++)
	{
		if (key[0] < index[i][0])
		{
			found_key = i - 1;
			break;
		}
	}
	int success = 0; // counts how many chars matched
	for (int s = 0; s < key.size(); s++)
	{

		for (int i = found_key * step; i <= (found_key + 1) * step; i++)
		{
			if(studs[i].surname.size()>=key.size())
			{
				if (key[s] == studs[i].surname[s])
				{
					found_word = i;
					++success;
				}
			}
		}
	}
	if (success >= accuracy) 
	{
		cout << found_word +1 << ' ' << studs[found_word].surname  << " was found.\n";
	}
	else
	{
		cout << key << " not found.\n";
	}

}

void rnd_fill(student *studs, const int size) //fills array quickly
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

void group_sort(student* studs, const int size) //sorts by groups(shaker sort used)
{
	int left = 1;
	int right = size - 1;
	do
	{
		for (int i = right; i >= left; i--)
		{
			if (studs[i - 1].group[0] > studs[i].group[0])
			{
				const student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		left++;
		for (int i = left; i <= right; i++)
		{
			if (studs[i - 1].group[0] > studs[i].group[0])
			{
				const student temp = studs[i];
				studs[i] = studs[i - 1];
				studs[i - 1] = temp;
			}
		}
		right--;
	} while (left <= right);

}

void name_sort(student* studs, const int size) // sorts by surnames(shaker sort used)
{
		int left = 1;
		int right = size - 1;
		do
		{
			for (int i = right; i >= left; i--)
			{
				if (studs[i - 1].surname[0] > studs[i].surname[0])
				{
					const student temp = studs[i];
					studs[i] = studs[i - 1];
					studs[i - 1] = temp;
				}
			}
			left++;
			for (int i = left; i <= right; i++)
			{
				if (studs[i - 1].surname[0] > studs[i].surname[0])
				{
					const student temp = studs[i];
					studs[i] = studs[i - 1];
					studs[i - 1] = temp;
				}
			}
			right--;
		} while (left <= right);
}
