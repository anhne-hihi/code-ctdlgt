#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node *child[10];
	bool endd;
	int d=0;

	node(){
		for(int i=0;i<10;i++){
		child[i]=nullptr;
		}
		endd=false;
	}
};
class trie{
	node *root;
	public:
	trie(){
		root =new node();
	}
	void them(string sdt){
		node *now=root;
		for(char x: sdt){
			if(now->child[x-'0']==nullptr){
				now->child[x-'0']=new node();
			}
			now= now->child[x-'0'];
			now->d++;
		}
		now->endd=true;
	}
	//
	int  prefix(string sdt){
		node *now=root;
		for(char x: sdt){
			if(now->child[x-'0']==nullptr){
				return 0;
			}
			now =now->child[x-'0'];
		}
		return now->d;
	}

};
int main(){
	int n,e=0;
	cout<<"nhap so luong so dien thoai: ";
	cin>>n;
	cin.ignore();
	trie tt;
	string s[n];
	for(int i=0;i<n;i++){
		getline(cin,s[i]);
		tt.them(s[i]);
	}
	for(int i=0;i<n;i++){
		if(tt.prefix(s[i])==n)
		{
			cout<<"ok sdt "<<s[i]<<" la tien to cua all sdt!";
			e++;
		}
	}
	if(e==0) cout<<" khong co so nao la tien to cua all sdt!";
	
}
