//given few words to check in dictionary output all words which matches the prefix and if not add it to the dictionary
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* next[26];
    bool end;
    node(){
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
        end = false;
    }
};
class trie{
    node *root;
    public:
    trie(){
        root = new node();
    }
    void insert(string &s){
        node *it = root;
        for(auto c:s){
            if(!it->next[c-'a']){
                it->next[c-'a'] = new node();
            }
            it = it->next[c-'a'];
        }
        it->end = true;
    }
    void find(string &s){
        node *it = root;
        for(auto c:s){
            if(!it->next[c-'a']){
                cout<<"No Word"<<"\n";
                insert(s);
                return;
            }
            it = it->next[c-'a'];
        }
        vector<string> res;
        outputmatchingwords(it,s,res,"");
        for(auto c:res){
            cout<<s<<c<<"\n";
        }
    }
    void outputmatchingwords(node *it,string &s,vector<string>&res,string curr){
        if(it == NULL){
            return;
        }
        if(it->end){
            res.push_back(curr);
        }
        for(int i=0;i<26;i++){
            if(it->next[i]){
            outputmatchingwords(it->next[i],s,res,curr+char('a'+i));
        }
        }
    }
};
int main(){
    trie t;
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &i:a){
        cin>>i;
        t.insert(i);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        t.find(s);
    }
}