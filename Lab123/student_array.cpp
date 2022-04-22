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

void index_search(const std::string& key, const student *studs, const int size, std::string *index, const int step, groups_list *match_list) // index sequential search
{
	int found_word = 0;
	int found_key = size/step;
	const int accuracy = 4; // key.size() for ideal search or length of smallest word for comfort/fast search
	index[0] = studs[0].surname;
	for (int i = 1; i < size / step; i++)
	{
		const int next = (i * step)-1;
		index[i] = studs[next].surname;
	}
	for (int i = 0; i < size / step; i++)
	{
		if (key[0] < index[i][0])
		{
			found_key = i;
			break;
		}
	}
	index_match_list(found_key-1,studs,size,match_list,step);
	int success = 0; // counts how many chars matched
	const int right = (found_key == size / step) ? (found_key * step) - 1 : found_key * step;
	const int left = (found_key == 5) ? found_key * step : (found_key - 1) * step;
	for (int s = 0; s < key.size(); s++)
	{
		for (int i = 0; i < step; i++)
		{
			if(match_list[i].element.surname.size()>=key.size())
			{
				if (key[s] == match_list[i].element.surname[s])
				{
					++match_list[i].mark;
				}
			}
		}
		// if (success >= accuracy)
		// {
		// 	cout << found_word + 1 << ' ' << studs[found_word].surname << " was found.\n";
		// 	break;
		// }
	}
	bool swapped;
	do
	{
		swapped = false;
		for (int i = 0; i < step - 1; i++)
		{
			if (match_list[i].mark < match_list[i + 1].mark)
			{
				swapped = true;
				const groups_list temp = match_list[i];
				match_list[i] = match_list[i + 1];
				match_list[i + 1] = temp;
			}
		}
	} while (swapped);
	if(accuracy<=match_list[0].mark)
	{
		cout << match_list[0].element.surname <<" found!\n";
	}
	else
	{
		cout << key << " not found.\n";
	}
	for(int i =0;i<step;i++)
	{
		cout << match_list[i].element.surname << ' ' << match_list[i].mark << endl;
	}
}

void index_match_list(const int left, const student *studs, const int size, groups_list *match_list, const int step)
{
	if(left ==0)
	{
		for (int i = 0; i < step; i++)
		{
			match_list[i] = { studs[left * step + i] };
		}
	}
	else
	{
		for (int i = 0; i < step; i++)
		{
			match_list[i] = { studs[left * step + i - 1] };
		}
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
