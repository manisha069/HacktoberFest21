class Solution {
  public:
    int noOfOpenDoors(long long n) {
        return sqrt(n);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
} 