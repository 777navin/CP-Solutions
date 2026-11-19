class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            bool oddA = (a & 1) != 0;
            bool oddB = (b & 1) != 0;

            if (oddA != oddB) {
                return oddA; // Odd numbers come before even numbers
            }
            if (oddA) {
                return a > b; // Both odd: descending order
            }
            return a < b;     // Both even: ascending order
        });
    }
};