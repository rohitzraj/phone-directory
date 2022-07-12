#include<bits/stdc++.h>
using namespace std;
#define int long long int
#include <fstream>
void solve(){
    ifstream namevar("Names.txt");
    string a;
    vector<string>names;
    while (getline(namevar, a))
    {
        names.push_back(a);
    }
    for(int i=0;i<1200;i++){
        string var1 = names[i];
        string s1="";
        string s2="";
        int flag = 0;
        for(int j=0;j<var1.size();j++){
            if(var1[j] == ' '){
                flag = 1;
                continue;
            }
            if(flag==0){
                s1+=var1[j];
            }
            else{
                s2+=var1[j];
            }
        }
        s1+=s2;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        if(i%3 == 0){
            s1+="@gmail.com";
        }
        else if(i%3 == 1){
            s1+= "@hotmail.com";
        }
        else{
            s1+="@outlook.com";
        }
        cout<<s1<<endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}