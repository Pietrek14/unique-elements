#include <iostream>
#include <fstream>

#define INPUT_FILE "dane.txt"

int main()
{
	// Read input file

	std::ifstream input(INPUT_FILE);

	if (!input.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku " << INPUT_FILE << std::endl;
		return 1;
	}

	int size1, size2;

	input >> size1 >> size2;

	int *arr1 = new int[size1];
	int *arr2 = new int[size2];

	for (int i = 0; i < size1; i++)
	{
		input >> arr1[i];
	}

	for (int i = 0; i < size2; i++)
	{
		input >> arr2[i];
	}

	input.close();

	// Find unique elements

	// There can't be any more unique elements than there are elements in both arrays
	int *result = new int[size1 + size2];
	int resultSize = 0;

	int i = 0, j = 0;

	// Until we go out of the bounds of any array
	while (i < size1 && j < size2)
	{
		// If the two values are equal...
		if (arr1[i] == arr2[j])
		{
			// ... and move to the next value in both arrays.
			i++;
			j++;
		}
		// If the arr1 value is bigger than arr2 value
		else if (arr1[i] > arr2[j])
		{
			// ...add arr2 value to the result array..
			result[resultSize++] = arr2[j];

			// ...move to the next value in arr2 to catch up with arr1
			j++;
		}
		// If the arr2 value is bigger than arr1 value
		else
		{
			// ...add arr1 value to the result array..
			result[resultSize++] = arr1[i];

			// ...move to the next value in arr1 to catch up with arr2
			i++;
		}
	}

	// Finish checking for the array that is not finished
	if (i < size1)
	{
		j--;

		for (int k = i; k < size1; k++)
		{
			result[resultSize++] = arr1[k];
		}
	}
	else if (j < size2)
	{
		i--;

		for (int k = j; k < size2; k++)
		{
			result[resultSize++] = arr2[k];
		}
	}

	// Print result
	for (int i = 0; i < resultSize; i++)
	{
		std::cout << result[i] << " ";
	}

	// Free memory
	delete[] result;
	delete[] arr1;
	delete[] arr2;

	// End me
	return 0;
}