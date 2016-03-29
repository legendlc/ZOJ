#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n > 0)
    {
        string seq;
        cin >> seq;
        set<char> inSalon; //people still in the saloon
        set<char> hasCome; //people who has come before
        int count = 0; // number of people who are inside
        int nLefts = 0; // number of people left
        for(unsigned int i = 0; i < seq.length(); i++)
        {
            char p = seq[i];
            set<char>::iterator pos = inSalon.find(p);
            if(pos == inSalon.end())
            {
                if(count < n)
                {
                    count++;
                    inSalon.insert(p);
                }
                else
                {
                    set<char>::iterator j = hasCome.find(p);
                    if(j == hasCome.end())
                    {
                        hasCome.insert(p);
                        nLefts++;
                    }
                }
            }
            else
            {
                inSalon.erase(p);
                count--;
            }
        }
        if(nLefts == 0)
            cout << "All customers tanned successfully.\n";
        else
            cout << nLefts << " customer(s) walked away.\n";

        cin >> n;
    }

}
