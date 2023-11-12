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
	bool empty(){
		for(int i=0;i<26;i++){
			if(root->child[i]) {
				cout<<"cay khong rong!\n";
				return false;
			}
		}
		cout<<"cay rong!\n";
		return true;
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
	void xoa(node* now, const string& word, int index) {
    if (index == word.length() - 1) {
        if (now->child[word[index] - 'a'] != nullptr) {
            node* child = now->child[word[index] - 'a'];
            now->child[word[index] - 'a'] = nullptr;
            delete child;
        }
        return;
    }

    if (now->child[word[index] - 'a'] != nullptr) {
        xoa(now->child[word[index] - 'a'], word, index + 1);
    }

    // Ki?m tra xem node hi?n t?i có n?m trên du?ng di t?i node lá khác không
    bool hasChild = false;
    for (int i = 0; i < 26; i++) {
        if (now->child[i] != nullptr) {
            hasChild = true;
            break;
        }
    }

    // N?u node hi?n t?i không có con và không ph?i node lá thì xóa node dó
    if (!hasChild) {
        delete now;
        now = nullptr;
    }
}

void xoatu(const string word) {
	if(!search(word)) cout<<"tu do khong co trong cay!\n";
    else {
    	xoa(root, word, 0);
    	cout<<"da xoa thanh cong!\n";	
	}
}
};
int main() {
    trie tt;
    int n; 
    	cout<<"day la cay trie:\n";
    while(true){    
	    cout<<"\n1.Them tu vao cay \n";
	    cout<<"2.Xoa tu trong cay\n";
	    cout<<"3.Tim kiem tu trong cay\n";
	    cout<<"4.Kiem tra tu co phai tien to khong\n";
	    cout<<"5.Kiem tra cay co rong khong\n";
	    cout<<"6.end\n";
	    cin>>n;cin.ignore();
	    switch(n){
	    	case 1:{
	    		string s;
	    		cout<<"nhap tu muon them: ";cin>>s;
	    		tt.them(s);
	    		cout<<"da them thanh cong!\n";
	    		
				break;
			}
			case 2:{
				string s;
				cout<<"nhap tu muon xoa: ";cin>>s;
				tt.xoatu(s);
				break;
			}
			case 3:{
				string s;
				cout<<"nhap tu muon tim kiem: " ;cin>>s;
				if(	tt.search(s)) cout<<"tu do da co trong cay\n";
				else cout<<"tu do khong co trong cay!\n";
				
				break;
			}
			case 4:{
				string s;
				cout<<"nhap tu muon kiem tra tien to: ";cin>>s;
				if(tt.prefix(s)) cout<<"cay co 1 tien to nhu vay!\n";
				else cout<<"cay khong co tien to do!\n";
				break;
			}
			case 5:{
				tt.empty();
				break;
			}
			case 6:{
				return 0;
			}
		}
	}
}


