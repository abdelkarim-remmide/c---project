#include "cryptage.h"
#include<iostream>
#include <string>
using namespace std;
string crypter(string msg,string key){
        string t="";
		int j=0,m=key.length();
		for(int i=0,n=msg.length();i<n;i++){
			int nkey=(int)key.at(j);
			t+= ((char)(nkey+msg.at(i))%256);
			j=(j+1)%m;
		}
		return t;
}

string decrypter(string msg,string key){
    string t="";
		int j=0,m=key.length();
		for(int i=0,n=msg.length();i<n;i++){
			int nkey=(int)key.at(j);
			t+=((char)(msg.at(i)-nkey)%256);
			j=(j+1)%m;
		}
		return t;
}
