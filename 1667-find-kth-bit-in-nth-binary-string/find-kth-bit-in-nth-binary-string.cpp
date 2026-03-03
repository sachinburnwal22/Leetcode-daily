class Solution {
public:
    // Function to reverse the string
    void reverse(string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);  // Using swap for cleaner code
            i++;
            j--;
        }
    }
    
    // Function to invert the binary string
    string invert(string s) {
        string a = "";
        for (int i = 0; i < s.length(); i++) {
            a += (s[i] == '0') ? '1' : '0'; // Correctly invert bits
        }
        return a;
    }

    // Function to find the kth bit in Sn
    char findKthBit(int n, int k) {
        string s = "0"; // Initialize S1
        if (n == 1) return '0'; // Base case

        for (int i = 2; i <= n; i++) {
            string inverted = invert(s); // Invert current string
            reverse(inverted); // Reverse the inverted string
            s += '1' + inverted; // Build the new string Sn
        }

        return s[k - 1]; // Return the k-th bit (1-indexed)
    }
};
