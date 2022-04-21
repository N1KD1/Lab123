#include <iostream>
#include "student_array.h"

int main()
{
	constexpr int arr_size = 30;
	constexpr int step = 5;
	constexpr  int index_size = arr_size / step;
	std::string index[index_size];
	student all_students[arr_size];
	groups_amount all_groups[arr_size];
	rnd_fill(all_students, arr_size);
	shaker_sort(all_students,arr_size);
	group_sort(all_students, arr_size);
	group_count(all_students, arr_size);
	std::cout << std::endl;
	std::cout << "Nested sort:\n";
	show_array(all_students, arr_size);
	name_sort(all_students, arr_size);
	std::cout << "Alphabetical sort:\n";
	show_array(all_students, arr_size);
	while(true)
	{
		std::string key;
		std::cout << ">>>\n";
		std::cin >> key;
		name_sort(all_students, arr_size);
		index_search(key,all_students,arr_size,index,step);
		shaker_sort(all_students, arr_size);
	}
	
}
