/*
 * File:   main.c
 * Author: scamanderoffl
 *
 * Created on 18 March, 2022, 9:30 PM
 */
 
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string str)
{
    int n = str.size();
    int res = 0;  
    for (int i = 0; i < n; i++) {
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == true)
                break;
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
         visited[str[i]] = false;
    }
    return res;
}


int main() {
    char s[100];
    cin>>s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
