def merge_sort(arr):
    if len(arr) == 1:
        return 
    mid = len(arr)//2
    
    # First Splitting
    L = arr[:mid]
    R = arr[mid:]

    # Splitte All (pre-order for splitting, post-order for merging) 
    merge_sort(L)
    merge_sort(R)

    # After all are splitteed: Merging!
    len_L, len_R = len(L), len(R)
    i, j, k = 0, 0, 0
    while i < len_L and j < len_R:
        if L[i]<= R[j]:
            arr[k]=L[i]
            i += 1
        else:
            arr[k]=R[j]
            j += 1
        k +=1

    while i < len_L:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len_R:
        arr[k] = R[j]
        j += 1
        k += 1

