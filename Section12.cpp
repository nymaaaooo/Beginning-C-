#include <iostream>

using namespace std;

// the function dynamically allocates a new array
int *apply_all(const int *const arr1, size_t s1, const int *const arr2, size_t s2){
	int *results{};
	results = new int[s1 * s2];
	int position{0};
	for(size_t i{0}; i < s1; i++){
		for(size_t j{0}; j < s2; j++){
			results[position] = arr1[i] * arr2[j];
			++position;
		}
	}
	return results;
}

// display all the integers in the array
void print(const int *const arrays, size_t size){
	cout << "[ ";
	for(size_t i{0}; i<size; ++i){
		cout << arrays[i] << " ";
	}
	cout << "]" << endl;
}

int main(){
	
	const size_t size1{5};
	const size_t size2{3};
	
	int array1[]{1, 2, 3, 4, 5};
	int array2[]{10, 20, 30};
	
	cout << "Array1: ";
	print(array1, size1);
	
	cout << "Array2: ";
	print(array2, size2);
	
	int *results = apply_all(array1, size1, array2, size2);
	constexpr size_t result_size{size1 * size2};
	
	cout << "Result: ";
	print(results, result_size);
		
	return 0;
}