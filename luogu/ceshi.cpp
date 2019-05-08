#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> V;
	for(int i = 1 ; i <= 5 ; ++ i){
		V.push_back(i);
	}
	for(int i = 0 ; i < V.size() ; ++ i){
		printf("%d ",V[i]);		//1 2 3 4 5
	}
	printf("\n");

	string str;
	char s[10] = {"abc"};
	str = "";
	str = "abc";
	str = string(s);
	str += str;
	str += "abc";
	str[0] = 's';
	printf("%d %s\n",str.length(),str.c_str());	//9 sbcabcabc 3
	printf("%d %d\n",str.find("abc"),str.find("cbc"));	//3 -1
	
	map<int,int> M1; map<string,int> M2;
	M1[1] = 1; M1[100000000] = 1;
	M2["abc"] ++; M2["ab"]++;
	M2.erase("ab");
	printf("%d\n",M2.find("ab")==M2.end());	//1
	printf("%d %d\n",M2["abc"],M2["ab"]);	//1 0

	set<int>S;
	S.insert(1); S.insert(2);
	S.erase(2);
	printf("%d %d\n",S.find(1)==S.end(),S.find(2)==S.end());
	//0 1

	int a[15];
	for(int i = 1 ; i <= 10 ; ++ i)a[i] = (10-i)/2;
	for(int i = 1 ; i <= 10 ; ++ i)printf("%d ",a[i]);
	printf("\n");
	//4 4 3 3 2 2 1 1 0 0
	nth_element(a+1,a+1+3,a+1+10);
	printf("%d\n",a[4]);
	//1
	sort(a+1,a+1+10);
	for(int i = 1 ; i <= 10 ; ++ i)printf("%d ",a[i]);
	printf("\n");
	//0 0 1 1 2 2 3 3 4 4
	int c = unique(a+1,a+1+10) - (a+1);
	for(int i = 1 ; i <= c ; ++ i)printf("%d ",a[i]);
	printf("\n");
	//0 1 2 3 4

	pair<int,int> pii;
	pii = make_pair(1,2);
	printf("%d %d\n",pii.first,pii.second);	//1 2

	return 0;
}
