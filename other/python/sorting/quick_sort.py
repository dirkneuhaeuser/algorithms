def quick_sort(self, arr, low, high):
    if low < high:
        pi = self.partition(arr, low, high)

        self.quick_sort(arr, low, pi-1)
        self.quick_sort(arr, pi+1, high)


def partition(self, arr, low, high):
    pivot = arr[high]
    j = low
    for i in range(low, high):
        if arr[i]<= pivot:
            arr[j], arr[i] = arr[i], arr[j]
            j +=1

    arr[high], arr[j] = arr[j], arr[high]
    return j

