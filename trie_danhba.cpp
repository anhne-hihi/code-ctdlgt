#include<bits/stdc++.h>
using namespace std;
class node {
public:
    node* child[26];
    bool endd;
	int d=0;
    node() {
        endd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        // phai gan all con tro child thanh null het thì ve sau 
        // no moi bt dau la null dau la co rui 
    }
};
class trie{
public:
	node *root;
    trie() {
         root = new node;
    }

    void them(const string word) {
        node* now = root;

        for (char x : word) {
            if (now->child[x - 'a'] == nullptr) {
                now->child[x - 'a'] = new node();
            }
            now = now->child[x - 'a'];
            now->d++;
        }
        now->endd = true;
    }
     bool search(string word) {
        node* now = root;

        for (char x : word) {
            if (now->child[x - 'a'] == nullptr) {
                return false;
            }
            now = now->child[x - 'a'];
        }
    	if (now->endd) {
		
			return true;
		} else {
		
			return false;
		}
    }
    int  prefix(string word) {
        node* now = root;

        for (char x : word) {
            if (now->child[x - 'a'] == nullptr) {
               
                return 0;
            }
            now = now->child[x - 'a'];
        }
      
        return now->d;
    }
};
int main(){
	trie tt;
	int n;cin>>n;cin.ignore();
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1=="add"){
			tt.them(s2);
		}
		else cout<<tt.prefix(s2)<<endl;
		
	}
}

