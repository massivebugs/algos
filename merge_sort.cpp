#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

void print_vector(std::vector<int> &to_print)
{
    for (std::size_t i=0; i < to_print.size(); i++)
    {
        std::cout << to_print[i] << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int> &l_vect, std::vector<int> &r_vect, std::vector<int> &merged)
{
    std::size_t merged_idx = 0;
    std::size_t l_size = l_vect.size();
    std::size_t r_size = r_vect.size();
    std::size_t l_idx = 0;
    std::size_t r_idx = 0;

    for(merged_idx; merged_idx < merged.size(); merged_idx++)
    {
        if (l_idx == l_size) {
            merged[merged_idx] = r_vect[r_idx];
            r_idx++;
            continue;
        } else if (r_idx == r_size) {
            merged[merged_idx] = l_vect[l_idx];
            l_idx++;
            continue;
        }

        // compare and add the smaller value to merged
        if (l_vect[l_idx] <= r_vect[r_idx]) {
            merged[merged_idx] = l_vect[l_idx];
            l_idx++;
        } else {
            merged[merged_idx] = r_vect[r_idx];
            r_idx++;
        }
    }
}
void merge_sort(std::vector<int> &to_sort)
{
    if (to_sort.size() == 1)
        return;

    std::size_t half_idx = std::ceil((float)to_sort.size() / 2);

    // The iterator pointing to the half element of the vector
    std::vector<int>::iterator half_iter = to_sort.end() - (to_sort.size() - half_idx);

    // Iterators in C++ by The Cherno https://www.youtube.com/watch?v=SgcHcbQ0RCQ
    std::vector<int> l_half(to_sort.begin(), half_iter);
    std::vector<int> r_half(half_iter, to_sort.end());

    merge_sort(l_half);
    merge_sort(r_half);

    merge(l_half, r_half, to_sort);
}

int main()
{
    std::vector<int> to_sort;

    // Initialize random seed
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        // Generate a random int with range 0~99
        int rand_int = rand() % 100;
        to_sort.push_back(rand_int);
    }

    merge_sort(to_sort);
    std::cout << "main() \n";
    print_vector(to_sort);
}