#include <cctype>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <stack>
#include <list>
using namespace std;



void solve() {

    string s; cin >> s;
    int n = s.size();

    // min  
    list<int> unknownPos;
    // max 
    stack<int> stillOpen;


    int currOpen = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            currOpen++;
            stillOpen.push(i);
        }
        else if (s[i] == ')') {
            currOpen--;
            if (!stillOpen.empty()) stillOpen.pop();
            else if (currOpen < 0) {
                // gotta find something to match this against 
                if (unknownPos.empty()) {
                    cout << "NO" << endl;
                    return;
                }

                // put ( at the latest available ?
                s[unknownPos.front()] = '(';
                unknownPos.pop_front();
                currOpen++; 
            }
        }
        else {
            // this is still unknown 
            unknownPos.push_back(i);

            if (currOpen == 0) {
                // if we are at the end nevermind
                if (i == n - 1) continue;
                
                // gotta open at the first ? 
                if (unknownPos.empty()) {
                    cout << "NO" << endl;
                    return;
                }

                s[unknownPos.front()] = '(';
                stillOpen.push(unknownPos.front());
                unknownPos.pop_front();
                currOpen++;
            }
        }
    }

    // I have some stillOpen and I have some unknowns 
    // still opens are the lowest positions 
    // unknowns are the max positions 
    // lets see if I can close all the open ones first 


    while(!stillOpen.empty()) {
        // see if there is some ? to put a ) there
        if (unknownPos.empty()) {
            cout << "NO" << endl;
            return;
        }

        // try to make a match
        if (stillOpen.top() < unknownPos.back()) {
            s[unknownPos.back()] = ')';
            stillOpen.pop();
            unknownPos.pop_back();
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if ((unknownPos.size() % 2) || unknownPos.size() > 2) {
        cout << "NO" << endl;
        return;
    }

    if (unknownPos.empty()) {
        cout << "YES" << endl;
        return;
    }

    
    // there are only two ?s remaining 
    // we can obviously put ... (   ..... ) ....
    // lets try puting ..... ) .. .... ( ....
    // and see if we an have the second version as balanced too 
    s[unknownPos.front()] = ')'; 
    s[unknownPos.back()] = '('; 

    // check if the second string is balanced 
    
    int open = 0;
    for (auto x : s) {
        if (x == '(') open++;
        else open--;
        // second string is invalidated, there is unique RBS
        if (open < 0) {
            cout << "YES" << endl;
            return;
        }
    }

    // second string is invalidated, there is unique RBS
    if (open < 0) {
            cout << "YES" << endl;
            return;
    }

    cout << "NO" << endl;
    
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

}
