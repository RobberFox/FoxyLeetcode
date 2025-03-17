#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define dprint(expr) printf(#expr " = %d\n", expr)

int romanToInt(char* s);

struct map {
	int num;
	char str[3]; // "IV\0" account for the '\0' character
};

struct map_char {
	int num;
	char chr;
};

int main()
{
	char my_roman[MAXSIZE] = "MCMXCIV";

	int ans = romanToInt(my_roman);
	printf("%d", ans);
}


int romanToInt(char* s) {
	int roman_count = 7;
	int except_count = 6;
	int result;
	int indexed[MAXSIZE] = {0}; //"paired" roman numerals, that were 'stripped off' after the loop with `except`: MCMXCIV -> M

	struct map_char roman[roman_count];
	struct map except[except_count];

	roman[0].chr = 'I', roman[0].num = 1;
	roman[1].chr = 'V', roman[1].num = 5;
	roman[2].chr = 'X', roman[2].num = 10;
	roman[3].chr = 'L', roman[3].num = 50;
	roman[4].chr = 'C', roman[4].num = 100;
	roman[5].chr = 'D', roman[5].num = 500;
	roman[6].chr = 'M', roman[6].num = 1000;

	strcpy(except[0].str, "IV"), except[0].num = 4;
	strcpy(except[1].str, "IX"), except[1].num = 9;
	strcpy(except[2].str, "XL"), except[2].num = 40;
	strcpy(except[3].str, "XC"), except[3].num = 90;
	strcpy(except[4].str, "CD"), except[4].num = 400;
	strcpy(except[5].str, "CM"), except[5].num = 900;

	int i, k;
	for (i = 0; i < strlen(s)-1; ++i) {
		char substr[3] = { s[i], s[i+1], '\0' };
		for (k = 0; k < except_count; ++k) {
			if (strcmp(substr, except[k].str) == 0) {
				result += except[k].num;
				indexed[i] = 1;
				indexed[i+1] = 1;
			}
		}
	}

	for (i = 0; i < strlen(s); ++i) {
		if (indexed[i] == 0) {
			for (k = 0; k < roman_count; ++k) {
				if (s[i] == roman[k].chr) {
					result += roman[k].num;
				}
			}

		}
	}

	return result;
}
