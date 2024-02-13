#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

//bool AuditCorect1(char str[]) {
//	int open = 0, close = 0, index = 0;
//	for (int i = 0; i < strlen(str); i++) {
//		if (str[i] == '(') {
//			open++;			
//			index++;
//		}		
//		if (str[i] == ')') {
//			close++;
//			if (index == 0) {
//				return false;
//			}			
//			index--;
//		}
//	}
//	if ((open + close) % 2 != 0) {
//		return false;
//	}	return true;
//}

bool AuditCorect2(char str[]) {
	int open1 = 0, close1 = 0, open2 = 0, close2 = 0;	
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			open1++;
		}		
		if (str[i] == '[') {
			open2++;
		}		
		if (str[i] == ')') {
			close1++;			
			if (open1 == 0) {
				return false;
			}
		}		if (str[i] == ']') {
			close2++;			
			if (open2 == 0) {
				return false;
			}
		}
	}
	if ((open1 + close1) % 2 != 0) {
		return false;
	}
	if ((open2 + close2) % 2 != 0) {
		return false;
	}
	int couple = 0, a = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			for (int j = i + 1; j < strlen(str); j++) {
				if (str[j] == '(') {
					a++;					
					couple++;
				}				
				if (str[j] == ')') {
					if (a == 0) {
						break;
					}					
					a--;
					couple++;
				}
				if (str[j] == '[' || str[j] == ']') {
					couple++;
				}
			}
			if (couple % 2 != 0) {
				return false;
			}
		}
		couple = 0; a = 0;
		if (str[i] == '[') {
			for (int j = i + 1; j < strlen(str); j++) {
				if (str[j] == '[') {
					a++;
					couple++;
				}
				if (str[j] == ']') {
					if (a == 0) {
						break;
					}
					a--;					
					couple++;
				}				
				if (str[j] == '(' || str[j] == ')') {
					couple++;
				}
			}
			if (couple % 2 != 0) {
				return false;
			}
		}
	}	return true;
}

int main()
{
	char arr[50]; 
	cin.getline(arr, 50);
	bool a = AuditCorect2(arr); 
	cout << a;

}