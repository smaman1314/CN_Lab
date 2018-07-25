#include<iostream>
using namespace std;
#define MAX 20
class Hamming{
	int n;
	int m,r;
	int t[MAX];
	int data[MAX];
	int pbi[MAX];	//parity bits .
public:
	Hamming(){
		n=m=0;
		r=0;
	}
	void get(){
		cout<<"Enter the no. of data bits : ";
		cin>>m;
		cout<<"Enter the data : ";
		for(int i=1;i<=m;i++)
			cin>>data[i];

		//finding 'r' i.e. no. of redundant bits:

		int p=1;
		int N=m+r+1;
		while(p<=N){
			r++;
			for(int i=0;i<r;i++)
				p = p * 2;
			N = m+r+1;
		}
		r = r +1 ;
		cout<<"\n\r is : "<<r<<endl;
		//Now inserting data bits in total array with power : 2^r
		for(int i=1;i<=r;i++){
			int p=1;
			for(int j=1;j<i;j++)
				p = p * 2;
			pbi[i] = p;
			cout<<"\n p = "<<p;
		}
		cout<<endl;
	}
	void solve(){
		//Now , for hamming code  :
		int total=m+r+1;
		int k=1;
		int j=1;
		for(int i=1;i<=total;i++){
			if(i!=pbi[k]){
				t[i] = data[j];
				j++;
			}
			else{
				t[i]=0;
				k++;
			}
		}
		cout<<"\n\n\nTotal array is : ";
		for(int i=1;i<=total;i++)
			cout<<t[i];
	}
};
int main(){
	Hamming h;
	h.get();
	h.solve();
	return 0;
}


