#include<bits/stdc++.h>
using namespace std; 
#define pb push_back 
int cnt; 
map<string,int> mp,dp;
bool check(string s)
{
    if(s=="") return true;
    string tmp;
    string dupli=s;
    if(dp[s]==1)
    return true;
    if(dp[s]==-1)
    return false;
    for(int j=s.length()-1;j>=0;j--)
    {
        tmp=s[j]+tmp;
        s.pop_back();
        if(mp[tmp]==1)
        {
            if(check(s))
            {
                dp[dupli]=1;
                return true;
            }
            else if(mp[s]==1){
                dp[dupli]=1;
                return true;
            }
        }
    }
    dp[dupli]=-1;
    return false;
}
string find(vector<pair<int,string>> &str)
{
    for(int j=cnt;j>=0;j--)
    {
        mp[str[j].second]=0;
        if(check(str[j].second))
        {
            cnt=j-1;
            mp[str[j].second]=1;
            return str[j].second;
        }
        mp[str[j].second]=1;
    }
    return "";
}
int main()
{
    ifstream fin;
    // ofstream fout;
    dp.clear();
    vector<pair<int,string>> str;
    string tmp;
    mp.clear();
    //reads input from file.
    fin.open("input_01.txt");
    while(fin)
    {
        getline(fin,tmp);
//        if(tmp.length()==0) break;
        mp[tmp]=1;
        str.pb({tmp.length(),tmp});
    }
    str.pop_back();
    fin.close();
    //sorting the input strings but their length
    sort(str.begin(),str.end());
    // ofstream fout;
    // fout.open("output1.txt");
    
    string longest,secondLongest;
    cnt=str.size()-1;
    longest=find(str);
    mp[longest]=0;
    secondLongest=find(str);
    cout<<longest<<"\n"<<secondLongest;
    // fout.close();
//    for(int i=0; i<str.size(); i++){
//        cout<<str[i].second<<" ";
//    }
    return 0;
}