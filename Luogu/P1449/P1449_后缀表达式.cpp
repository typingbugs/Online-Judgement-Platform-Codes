#include<bits/stdc++.h>
using namespace std;

queue<char> s;
int nums[51];
int i_n;

void culculate();

int main() {
    char input;
    bool num_mode = true;
    while ((input = getchar()) != '@') {
        if (input >= '0' && input <= '9') {
            if (num_mode == false) {
                culculate();
                num_mode = true;
            }
            nums[i_n] = nums[i_n] * 10 + input - '0';
        }
        else if (input == '.') {
            i_n++;
        }
        else {
            num_mode = false;
            s.push(input);
        }
    }
    culculate();
    cout << nums[0] << '\n';
    return 0;
}

void culculate() {
    i_n--;
    while (i_n) {
        char sign = s.front();
        s.pop();
        if (sign == '+') {
            nums[i_n - 1] += nums[i_n];
            nums[i_n--] = 0;
        }
        else if (sign == '-') {
            nums[i_n - 1] -= nums[i_n];
            nums[i_n--] = 0;
        }
        else if (sign == '*') {
            nums[i_n - 1] *= nums[i_n];
            nums[i_n--] = 0;
        }
        else if (sign == '/') {
            nums[i_n - 1] /= nums[i_n];
            nums[i_n--] = 0;
        }
    }
    i_n++;
}

