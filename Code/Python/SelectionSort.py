def SelectionSort(arr):
    for i in range(len(arr)):
        minIndex = i
        for j in range(i+1, len(arr)):
            if arr[minIndex] > arr[j]:
                minIndex = j    
        arr[i], arr[minIndex] = arr[minIndex], arr[i]
    return arr

# Input Format: 4 5 6 2 3
numList = list(map(int, input("Enter elements of array: ").split()))

print("Sorted List: ", SelectionSort(numList))
