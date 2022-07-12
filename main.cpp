#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class phone_directory
{
public:
    vector<string> names, emails, contacts;
    vector<vector<string>> ans;
    map<char, int> mp;
    phone_directory()
    {
        ifstream name1("Names.txt");
        ifstream email1("Emails.txt");
        ifstream contact1("Contact_no.txt");
        string a, b, c;
        while (getline(name1, a))
        {
            names.push_back(a);
        }
        while (getline(email1, b))
        {
            emails.push_back(b);
        }
        while (getline(contact1, c))
        {
            contacts.push_back(c);
        }

        for (int i = 0; i < 26; i++)
        {
            mp['a' + i] = i;
        }
        mp[' '] = 26;
    }

    struct node
    {
        vector<int> index;
        node *child[27];
        node()
        {
            for (int i = 0; i < 27; i++)
                child[i] = NULL;
        }
    } root;

    void insert(string &s, int ind)
    {
        node *curr = &root;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            char ch;
            ch = s[i];
            if (isalpha(ch))
                ch = tolower(ch);
            int x = mp[ch];
            if (curr->child[x] == NULL)
            {
                curr->child[x] = new node;
            }
            curr->child[x]->index.push_back(ind);
            curr = curr->child[x];
        }
    }

    void init()
    {
        for (int i = 0; i < 1000; i++)
        {
            insert(names[i], i);
        }
    }

    void find(string &s)
    {
        node *curr = &root;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            int x = mp[s[i]];
            if (curr != NULL && curr->child[x] != NULL)
            {
                curr = curr->child[x];
            }
            else
                curr = NULL;
        }

        if (curr != NULL)
        {
            for (auto x : curr->index)
            {
                ans.push_back({names[x], contacts[x], emails[x]});
            }
        }
    }

    void print(string s)
    {
        init();
        find(s);
        cout << "There are " << ans.size() << " results found related to your query\n";
        cout << "\n";
        int cnt=1;
        for (auto x : ans)
        {
            cout<<cnt++<<"."<<" "<<x[0] << "      " << x[1] << "      " << x[2] << "\n";
        }
    }
};
int main()
{
    string details;
    system("cls");
    getline(cin, details);
    transform(details.begin(), details.end(), details.begin(), ::tolower);
    phone_directory final;
    final.print(details);
}