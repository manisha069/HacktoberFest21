/*
    Solution Added By: Anish Kumar
    Github Profile: https://github.com/KmrAnish04

    Question: Beautiful Triplets | Hackerrank
    Question Link: https://www.hackerrank.com/challenges/beautiful-triplets/problem

    Complexity Analysis:
    Time Complexity: O(N)
    Space Complexity: O(N)

    Optimized Approach

    Algorithm:
    1. In this approach, we will firstly hash all the elements and will increment the frequencies (frequency = no. of times an element repeating in the given array)
       of given array elements in an unordered map.
    
    2. Now, We will start iterating through the given array. Here, the elements which we will get during the iteration, can be our "a[i]" element 
       (i.e first element of the Beautiful Triplet) of the required triplet if the oter two elements of the triplet is also present in the array.
       Let say, this is our "a[i]" element it means we got our first element of the beautiful triplet and with the help of this "a[i]" element
       and given condition in the problem statement that is "arr[j]-arr[i] = arr[k]-arr[j] = d" we can easily find the other two required "a[j]" and
       "a[k]" elements of the triplet.
       
       **If you still didn't got the idea that how we can find "a[j]" and "a[k]" elements of triplet then take a look at this:
       Given condition is :  arr[j]-arr[i] = arr[k]-arr[j] = d , so we can also write this formula as "a[j]-a[i] = d , as we already know the a[i] and "d"
       from this formula, it means we can easily find a[j] (i.e a[j] = a[i] + d)  and similarly, when we get a[j], we will use a[j] in "a[k] = a[j] + d" 
       to find a[k].
    
    3. Now, we got the required second and third elements of the triplet for current a[i] element. Now, We are sure that a[i] element is present
       in the array but not sure about the required a[j] and a[k] elements which are important for making triplet with the current a[i] element. So,
       Now we can check about the presence of a[j] and a[k] element from the map that we created in very first step. If the frequency of the a[j] and a[k]
       element in the map is greater than or equal to 1, it means a[j] and a[k] elements are present in the array. So, This triplet is a beatuful
       triplet we can say for sure. And whenever we found a beautiful triplet, we will increament the counter by one and will return that as our final answer.
  
*/


int beautifulTriplets(int d, vector<int> arr) {
    int size=arr.size();
    unordered_map<int, int> map;
    int count=0;
    
    for(int i=0; i<size; i++){
        map[arr[i]]++;
    }
    
    for(int i=0; i<=size-3; i++){
        int tplt1 = arr[i]+d;
        int tplt2 = tplt1+d;
        if(map[tplt1]>=1 && map[tplt2]>=1) count++;
    }
    
    return count;
}

