#include <iostream>
#include <stack>
using namespace std;
int nge(int* arr,int n){
	stack<int> s;
//	s.push(arr[0]);
	for(int i = 0 ;i <n ;++i ){
		//cout << "i is " << i << endl;
		if(s.empty())
			s.push(arr[i]);
		else{
			while(!s.empty() &&  s.top() < arr[i]){
				cout << "NGE of " << s.top() << ": " << arr[i] << endl;
				s.pop();
			}
			s.push(arr[i]);
		}
	}
	

}
int main(void){
	int arr[7] = {40,50,11,32,55,68,75};
	nge(arr,7);	
}
