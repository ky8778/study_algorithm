def bubble_sort(array):
    for i in range(len(array)-1, 0, -1):    # 아래의 loop가 끝났을 때, index가 i 인 원소는 최종위치입니다.
        for j in range(i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array

print(bubble_sort([4,3,1,2,6,10,9]))


def selection_sort(array):
    for i in range(len(array)-1):
        min_idx = i
        for j in range(i+1, len(array)):
            if array[min_idx] > array[j]:
                min_idx = j
        if i != min_idx:
            array[i], array[min_idx] = array[min_idx], array[i]
    return array

print(selection_sort([4,3,1,2,6,10,9]))


def insertion_sort(array):
    for i in range(1,len(array)):
        key = array[i]
        for j in range(i-1, -1, -1):
            if array[j] > key:
                array[j], array[j+1] = array[j+1], array[j]
    return array

print(insertion_sort([4,3,1,2,6,10,9]))


def merge(left_arr, right_arr):
    result = []
    left_idx = 0
    right_idx = 0
    while left_idx < len(left_arr) or right_idx < len(right_arr):
        if left_idx >= len(left_arr):
            result.extend(right_arr)
            break
        if right_idx >= len(right_arr):
            result.extend(left_arr)
            break
        if left_arr[left_idx] <= right_arr[right_idx]:
            result.append(left_arr[left_idx])
            left_idx += 1
        else:
            result.append(right_arr[right_idx])
            right_idx += 1
    return result


def merge_sort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr)//2
    left_arr = arr[:mid]
    right_arr = arr[mid:]
    left_arr = merge_sort(left_arr)
    right_arr = merge_sort(right_arr)
    return merge(left_arr,right_arr)


def quick_sort(arr, left, right):
    l = left
    r = right
    pivot = arr[(left+right)//2]

    while l<=r :
        print(l,r)
        while arr[l] < pivot:
            l += 1
        while arr[r] > pivot:
            r -= 1
        if l <= r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
    if l < right:
        quick_sort(arr,l,right)
    if r > left:
        quick_sort(arr, left, r)

    return arr