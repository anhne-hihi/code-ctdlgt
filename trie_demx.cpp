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
	string s;int n;
	cout<<"nhap so luong xau: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"nhap xau thu "<<i+1<<" : ";
		cin>>s;
		tt.them(s);
	}
	cout<<"\nnhap xau muon kiem tra :";
	cin >>s;
	cout<<"xau nay la tien to cua: "<<tt.prefix(s)<<" xau!";
}
