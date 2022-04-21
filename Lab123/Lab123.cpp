#include <iostream>
#include "student_array.h"

int main()
{
	constexpr int arr_size = 30;
	student all_students[arr_size];
	//fill_blank(all_students, arr_size);
	rnd_fill(all_students, arr_size);
	show_array(all_students, arr_size);
	name_sort(all_students, arr_size);
	show_array(all_students, arr_size);
	
	
}
