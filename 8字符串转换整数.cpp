#include <climits>
#include <iostream>
#include <string>
#include <cctype>




class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.size();
        // 跳过前导空格
        while (i < n && isspace(s[i])) {
            i++;
        }

        // 检查符号
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 转换数字
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // 检查是否超出范围
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return result * sign;
    }
};