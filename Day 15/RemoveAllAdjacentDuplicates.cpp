#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string &str){

	int i=0;
	while(str[i] != '\0')//  OR we can use ->  while( i<str.length() )
	{
		if(str[i] == str[i+1])
		{
			str.erase(i,2);//removing 2 values together
			i--;	// Decrementing i to check previous pair i.e 'aa' from 'aaca' after deleting 'bb' from 'abbaca'.  
		}
		else
		{
			i++;			
		}		
	}
	return str;
}

int main() {

    string s = "abbaca";

    cout << removeDuplicates(s);

    return 0;
}
