#pragma once
#include <string>

struct student
{
	std::string surname;
	std::string group;
	int mark{}; // 0.0-100
	bool status{}; // 0 - contract, 1 - budget
};
struct groups_list
{
	student	element;
	int mark = 0;
};
void show_array(const student *studs, int size);
void shaker_sort(student *studs, int size);
int distinct_count(const student *studs, int size);
void group_count(const student *studs, int size);
void bubble_sort(student *studs, int size);
void index_search(const std::string& key, const student* studs, const int size, std::string* index, const int step, groups_list *match_list);
void index_match_list(const int left, const student *studs, const int size, groups_list *match_list, const int step);
void rnd_fill(student *studs, int size);
void group_sort(student *studs, int size);
void name_sort(student *studs, int size);