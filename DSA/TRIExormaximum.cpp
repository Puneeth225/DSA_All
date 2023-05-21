//given an array find maximum XOR value of any two numbers in array
// #include<bits/stdc++.h>
// using namespace std;
// class trienode{
//     public:
//     trienode* next[2]; //as a node points two other nodes
//     trienode(){
//         next[0] = NULL;
//         next[1] = NULL;
//     }
// };
// trienode* buildtrie(vector<int> &a){
//     trienode* root = new trienode();
//     int n = a.size();
//     for(int i=0;i<n;i++){
//         int num = a[i];
//         trienode* curr = new trienode();
//         for(int i=31;i>=0;i--){
//             int bit = (num>>i)&1;
//             if(curr->next[bit] == NULL){
//                 curr->next[bit] = new trienode();
//             }
//             curr = curr->next[bit];
//         }
//     }
//     return root;
// }
// int maxor(trienode* root, vector<int> &a){
//     int ans = 0;
//     for(int i=0;i<a.size();i++){
//         int num = a[i];
//         trienode* it = root;
//         int cur_max = 0;
//         for(int i=31;i>=0;i--){
//             int bit = ((num>>i)&1)?0:1;
//             if(it->next[bit]){
//                 cur_max<<=1;
//                 cur_max|=1;
//                 it = it->next[bit];
//             }
//             else{
//                 cur_max<<=1;
//                 cur_max|=0;
//                 it = it->next[bit xor 1];
//             }
//         }
//         ans = max(ans,cur_max);
//     }
//     return ans;
// }
// int main(){
//     vector<int> a = {3,10,5,15,2};
//     trienode* root = buildtrie(a);
//     int ans = maxor(root,a);
//     cout<<ans<<"\n";
// }






#include<iostream>
#include<utility>
#include<vector>
using namespace std;

const static int SIZE = 2;
const static int MSB = 30;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[SIZE];
        TrieNode(){
            for(int i = 0; i < SIZE; ++i) {
                children[i] = nullptr;
            }
        }
        ~TrieNode() {
            for(int i = 0; i < SIZE; ++i) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    Trie(): root(new TrieNode()) {}
    
    ~Trie() {
        delete root;
        root = nullptr;
    }

    void insert(int key) {
        TrieNode* curr = root;

        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    int query(int key, int& otherKey) {

        int XOR = 0;
        TrieNode *curr = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(curr->children[!bit]) {
                curr = curr->children[!bit];
                XOR |= (1 << i);
                if(!bit) { otherKey |= (1 << i); }
                else { otherKey &= ~(1 << i);}
            }
            else{
                if(bit) { otherKey |= (1 << i); }
                else { otherKey &= ~(1 << i); }
                curr = curr->children[bit];
            }
        }
        return XOR;
    }
};

pair<int, int> findMaximumXorElements(vector<int>& A) {
    int n = A.size();
    int maximumXOR = 0;
    pair<int, int> result; 
    if(n < 2) return result;

    Trie trie;
    trie.insert(0);
    for(int i = 0; i < n; ++i) {
        int elem = 0;
        int curr = trie.query(A[i], elem);

        if(curr > maximumXOR) {
            maximumXOR = curr;
            result = make_pair(A[i], elem);
        }
        trie.insert(A[i]);
    }

    return result;
}

int main()
{
    vector<int> v({13,18,19,12});
    pair<int,int> s = findMaximumXorElements(v);
    cout << s.first << ", " << s.second << endl;
    // possible solutions: (13,18), (12,19)

    return 0;
}

