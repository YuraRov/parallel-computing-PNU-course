#include "MutexedList.h"

#include <algorithm>
#include <iostream>
#include <string>

void MutexedList::AddToList(int element)
{
	// Task 4
	mutex_for_data_.lock();

	data_.push_back(element);
	std::cout << "Element " << element << " was added to list\n";
	for (int i = 1; i < kCounterValue; i++)
	{
		data_.push_back(i);
		std::cout << "Element " << i << " was added to list\n";
	}

	// Task 4
	mutex_for_data_.unlock();
}

bool MutexedList::ListContains(int element)
{
	bool found = false;

	// Task 4
	mutex_for_data_.lock();
	for (int i = 0; i < kCounterValue; i++)
	{
		found = std::find(data_.begin(), data_.end(), element) != data_.end();
		std::string message = found ? "Element " + std::to_string(element) + " was found in list"
									: "Element " + std::to_string(element) + " wasn't found in list";
		std::cout << message << '\n';
	}

	// Task 4
	mutex_for_data_.unlock();
	return found;
}