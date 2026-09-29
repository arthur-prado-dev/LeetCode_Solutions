class Solution {
public:
    bool isPalindrome(int x) {
        int xCopy = x;
        long palindrome = 0;

        while(x > 0){
            palindrome = palindrome * 10 + (x % 10);
            x /= 10;
        }

        return (int)palindrome == xCopy;
    }
};