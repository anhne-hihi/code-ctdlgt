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
    bool prefix(string word) {
        node* now = root;

        for (char x : word) {
            if (now->child[x - 'a'] == nullptr) {
               
                return false;
            }
            now = now->child[x - 'a'];
        }
      
        return true;
    }
    void  inprefix(node* now, string s,int k) {
        for (int i = 0; i < 26; i++) {
            if (now->child[i] != nullptr) {
                char ch = 'a' + i;
                inprefix(now->child[i], s+ch,k);
            }
        }
         if (now->endd) {
           cout<<s.substr(k,s.size()-1)<<"  ";
        }
    }
};
int main(){
    trie tt;
	int n;
	string s;
	cout<<"nhap so luong xau: ";
	cin>>n;	
	for(int i=0;i<n;i++){
		cout<<"nhap xau thu "<<i+1<<" : ";
		cin>>s;tt.them(s);
	}	
	cout<<"\nnhap xau muon kiem tra :";
	cin >>s;
	int k=s.size();
	if(tt.prefix(s)) {
		cout<<"xau nay la tien to cua xau :";
		tt.inprefix(tt.root,s,k);
		
	}
	else cout<<"khong ton tai xau nao co tien to la xau can tim!";
	
	
	
}
