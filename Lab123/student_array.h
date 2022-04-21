#pragma once
#include <string>


struct student
{
	std::string surname;
	std::string group;
	int mark{}; // 0.0-100
	bool status{}; // 0 - contract, 1 - budget
};

struct groups_amount
{
	std::string group;
	int amount;
};

void show_array(const student *studs, int size);
void shaker_sort(student *studs, int size);
void group_count(student *studs, int size);
void bubble_sort(student *studs, int size);
void index_search(const std::string& key, const student* studs, const int size, std::string* index, const int step);
void rnd_fill(student *studs, int size);
void fill_blank(student *studs, int size);
void group_sort(student *studs, int size);
void name_sort(student *studs, int size);