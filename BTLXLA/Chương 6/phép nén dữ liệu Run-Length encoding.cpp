#include<iostream>
#include<string>
using namespace std;
int main(){
    string message;
    cin>>message;
    string encoded_message="";
	int i=0;
	while(i<=message.length()-1){
	    int count=1;
		char ch=message[i];
		int j=i;
		while(j<message.length()-1){
			if (message[j]==message[j+1]){
				count=count+1;
				j=j+1;
			}
			else break;
		}
		encoded_message=encoded_message+ch+to_string(count);
		i=j+1;
	}
	cout<<encoded_message<<endl;
}