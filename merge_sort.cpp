#include <iostream>

using std::cout;

const int ARRAY_LENGHT = 25;

int numbers[ARRAY_LENGHT];

int* sort_array(int* numbers, int length, int* result) {
    if (length < 2) {
        return numbers;
    }

    int* left_array = sort_array(((int*)numbers), length / 2, new int[length / 2]);
    int* right_array = sort_array(((int*)numbers) + (length / 2), length / 2 + (length % 2), new int[length / 2 + (length % 2)]);

    int i = 0;
    int j = 0;

    while (i < length / 2 && j < (length / 2 + (length % 2)))
    {
        if (left_array[i] < right_array[j]) {
            result[i + j] = left_array[i];
            i++;
        } else {
            result[i + j] = right_array[j];
            j++;
        }
    }

    while (i < length / 2) {
        result[i + j] = left_array[i];
        i++;
    }

    while (j < (length / 2 + (length % 2))) {
        result[i + j] = right_array[j];
        j++;
    }

    left_array = nullptr;
    right_array = nullptr;

    delete[] left_array;
    delete[] right_array;
    
    return result;
}

int* sort_array(int* numbers, int length) {
    return sort_array(numbers, length, new int[length]);
}

int main(int argc, char** argv) {
    for (int i = 0; i < ARRAY_LENGHT; i++) {
        numbers[i] = (ARRAY_LENGHT - i) * 2;
    }

    int* sorted_array = sort_array(numbers, ARRAY_LENGHT);

    for (int i = 0; i < ARRAY_LENGHT; i++) {
        cout << "[" << i << "]: " << sorted_array[i] << " - " << numbers[i] << "\n";
    }

    return 0;
}
