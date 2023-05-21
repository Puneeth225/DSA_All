#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i=0;i<26;i++){
                next[i] = NULL;
            }
        }
    };
    node *trie;
    Trie(){
        trie = new node();
    }
    void insert(string word){
        int i=0;
        node* it = trie;
        insert(" ");
        while(i<word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                it->next[word[i]-'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word){
        int i=0;
        node* it = trie;
        insert("");
        while(i<word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};
int main(){
    Trie* myt1 = new Trie();
    myt1->insert(" ");
    vector<string> words = {"Raju","Shyam"};
    
    for(auto w : words){
       // myt1->insert("");
        myt1->insert(w);
    }
    cout<<"JKL";
    if(myt1->search("Raju")){
        cout<<"Found"<<"\n";
    }
    else{
        cout<<"Not found"<<"\n";
    }
    
}
//compiler not supporting