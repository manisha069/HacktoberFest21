def BubbleSort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr

# Input Format: 4 5 6 2 3
numList = list(map(int, input("Enter elements of array: ").split()))

print("Sorted List: ", BubbleSort(numList))
