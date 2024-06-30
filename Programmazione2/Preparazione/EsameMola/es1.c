#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

_Bool isPalindrome(const char *s, int first, int last){
	if(s == NULL) return false;
	
	while(first < last){
		if(s[first] != s[last]){
			return false;
		}
		first++;
		last--;
	}
	return true;
}

int main(){
	char* s = "koopok";
	printf("%d", isPalindrome(s,0,strlen(s)-1));
	return 0;
}