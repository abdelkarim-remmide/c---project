#include "cryptage.h"
#include<iostream>
#include <string>
using namespace std;
string crypter(string msg,string key){
        string t="";
		int j=0,m=key.length();
		for(int i=0,n=msg.length();i<n;i++){
			t+=msg.at(i)^key.at(j);
			j=(j+1)%m;
		}
		return t;
}

string decrypter(string msg,string key){
		return crypter(msg,key);
}
