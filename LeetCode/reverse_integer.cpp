class Solution {
public:
    int reverse(int x) {
        vector<int> digits;

        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int leadingPowerOf10 = digits.size() - 1;
        int result = 0;

        for (int digit : digits) {
            try {
                if (result + pow(10, leadingPowerOf10) * digit > numeric_limits<int32_t>::max() || result + pow(10, leadingPowerOf10) * digit < numeric_limits<int32_t>::min()) {
                    throw out_of_range("Out of range");
                }
                result += pow(10, leadingPowerOf10) * digit;
                leadingPowerOf10--;
            } catch(...) {
                return 0;
            }
            
        }

        return result;
    }
};