import math
import random

def merge_sort(to_sort):

    # base case to exit recursive loop
    if len(to_sort) == 1:
        return to_sort
    
    # the point to divide the list in half (ceil to accompany for odd length lists)
    half_idx = math.ceil(len(to_sort) / 2)

    l_half = to_sort[:half_idx]
    r_half = to_sort[half_idx:]

    sorted_l_half = merge_sort(l_half)
    sorted_r_half = merge_sort(r_half)
    return merge(sorted_l_half, sorted_r_half)

def merge(l_arr, r_arr):
    # print(f'Merging {l_arr} and {r_arr}', end=' ')

    merged = []

    while len(l_arr) > 0 or len(r_arr) > 0:

        if len(l_arr) == 0:
            merged.append(r_arr.pop(0))
            continue
        elif len(r_arr) == 0:
            merged.append(l_arr.pop(0))
            continue

        # compare and add the smaller value to merged
        if l_arr[0] <= r_arr[0]:
            merged.append(l_arr.pop(0))
        else:
            merged.append(r_arr.pop(0))

    # print(f'resulted in {merged}')
    return merged 

# generate list with 100 random integers and sort it
to_sort = [random.randint(0, 100) for x in range(100)] 
sorted_arr = merge_sort(to_sort)
print(to_sort, end='\n\n')
print(sorted_arr)

#answer = [1, 2, 4, 5, 7, 9, 18]
#print(f'New array {sorted_arr} vs Answer {answer}')
#print(sorted_arr == answer)
