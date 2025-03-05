#include <vector>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <list>

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// ---------------- PARTIE 1 ----------------

bool is_primary(int n)
{
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// ---------------- PARTIE 3 ----------------

constexpr int turns_nb = 3;

void container_race(vector<int> &primes)
{
    int N = primes.size();

    // Non-associatives :
    vector<int> vec;
    vec.insert(vec.begin(), primes.begin(), primes.end());

    for (int n = 0; n < turns_nb; n++)
    {
        // Stack
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            st.push(vec.back());
            vec.pop_back();
        }

        // List
        list<int> li;
        for (int i = 0; i < N; i++)
        {
            li.push_back(st.top());
            st.pop();
        }

        // Queue
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            q.push(li.front());
            li.pop_front();
        }

        // Vector
        for (int i = 0; i < N; i++)
        {
            vec.push_back(q.front());
            q.pop();
        }
    }

    // Associatives
    set<int> st;
    st.insert(primes.begin(), primes.end());

    for(int n = 0; n < turns_nb; n++) {
        // Multiset
        multiset<int> ms;
        for (int i = 0; i < N; i++)
        {
            ms.begin();
        }
    }
}

// ---------------- MAIN --------------------

const int max_nb = 1000;

int main(int argc, char const *argv[])
{
    array<int, 200> primes;

    cout << "Primary numbers between 1 and " << max_nb << " :" << endl;

    int nb_primes = 0;
    for (int n = 2; n < max_nb; n++)
    {
        if (is_primary(n))
        {
            cout << " - " << n << endl;
            primes[nb_primes] = n;
            nb_primes++;
        }
    }

    cout << "Total number of primes : " << nb_primes << endl;
    return 0;
}
