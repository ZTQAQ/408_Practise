#дһ�ο�������Ĵ���


def quick_sort(lists, left, right):

    if left >= right:
        return lists
    key = lists[left]
    low = left
    high = right
    while left < right:
        while left < right and lists[right] >= key:
            right -= 1
        lists[left] = lists[right]
        while left < right and lists[left] <= key:
            left += 1
        lists[right] = lists[left]
    lists[right] = key
    quick_sort(lists, low, left - 1)
    quick_sort(lists, left + 1, high)
    return lists

#дһ�β��Դ���
if __name__ == '__main__':
    lists = [3, 4, 2, 8, 9, 5, 1]
    print(quick_sort(lists, 0, len(lists) - 1))


