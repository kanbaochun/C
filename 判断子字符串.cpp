#include <iostream>
#include <string>
using namespace std; 

int str_str(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int len_temp;
	int len;

	string min_str;
	string print_str;
	string max_str;

	if (len2>len1)
		{len = len2-len1;
		len_temp=len1;
		print_str = "str1是str2的字串";
		min_str=str1;
		max_str=str2;}
	else
		{len_temp = len2;
		len = len1 - len2;
		print_str = "str2是str1的子串";
		min_str=str2;
		max_str=str1;}

	for(int i = 0;i<=len;i++)
	{
		string str3(max_str,i,len_temp);
		if (str3 == min_str)
			{cout<<print_str<<endl;
				break;}
		if (i == len)
			cout<<"不存在子串关系"<<endl;
	}
	
}

int main()
{
	string str1 = "真帅";
	string str2 = "阚保春真帅";
	str_str(str1,str2);
    return 0;
}