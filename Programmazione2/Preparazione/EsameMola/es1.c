#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

_Bool isPalindrome(const char *s, int first, int last){
	bool pal = true;
	//approccio di tipo while dato che abbiamo la prima e l' ultima lettera
	while (first < last && pal){
		if(s[first] != s[last]){
			pal = false;
		}
		first++;
		last--;
	}
	return pal;
}

int main(){
	char* s = "kooook";
	printf("%d", isPalindrome(s,0,strlen(s)-1));
	return 0;
}