#include <iostream>
#include "student_array.h"

int main()
{
	constexpr int arr_size = 30;
	student all_students[arr_size];
	fill_blank(all_students, arr_size);
	show_array(all_students, arr_size);
}
