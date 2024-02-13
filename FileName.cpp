#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

bool AuditCorect1(char str[]) {
	int open = 0, close = 0, index = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			open++;			index++;
		}		if (str[i] == ')') {
			close++;
			if (index == 0) {
				return false;
			}			index--;
		}
	}
	if ((open + close) % 2 != 0) {
		return false;
	}	return true;
}

int main()
{
	char arr[50]; cin >> arr;
	bool a = AuditCorect1(arr); 
	cout << a;

}