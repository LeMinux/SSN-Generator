#include <stdio.h>

#define MAX_SSN 999999999
#define SSN_SIZE 12

int main(void){
	//base to keep count
	unsigned int ssnBase = 0;
	for(;ssnBase <= MAX_SSN; ++ssnBase){
		char ssnString [SSN_SIZE]; //XXX-XX-XXXX
		unsigned int ssnDigits = ssnBase;
		int index = SSN_SIZE - 2;
		while(ssnDigits > 0 && index >= 0){
			switch(index){
				case 3: case 6:
					ssnString[index] = '-';
				break;

				default:
					//set the char value of '0' as an offset
					//since this is dealing with digits there can't be a +10
					ssnString[index] = ssnDigits % 10 + '0';
					ssnDigits /= 10;
				break;
			}
			--index;
		}

		//pad with zeros
		while(index >= 0){
			switch(index){
				case 3: case 6: ssnString[index] = '-'; break;
				default: ssnString[index] = '0'; break;
			}
			--index;
		}
		ssnString[SSN_SIZE - 1] = '\0';
		printf("%s\n", ssnString);
	}
}
