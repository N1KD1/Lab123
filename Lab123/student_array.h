#pragma once
#include <string>

using namespace std;

struct student
{
	string surname;
	string group;
	int mark; // 0.0-100
	bool status; // 0 - contract, 1 - budget
};

struct groups_amount
{
	string group;
	int amount;
};

void show_array(const student *studs, int size);
void shaker_sort(student *studs, int size);
void group_count(student *studs, int size);
void bubble_sort(student *studs, int size);
void index_search(student *studs, int size);
void rnd_fill(student *studs, int size);
void fill_blank(student *studs, int size);
void group_sort(student *studs, int size);
void name_sort(student *studs, int size);