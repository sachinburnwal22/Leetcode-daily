class Solution {
public:
    bool primeNumber(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int i = left; i <= right; i++) {
            if (primeNumber(i)) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int minDiff = INT_MAX;
        int a = -1, b = -1;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];

            if (diff < minDiff) {
                minDiff = diff;
                a = primes[i - 1];
                b = primes[i];
            }
        }

        return {a, b};
    }
};