/* Exercise 4-14
 * Define a macro swap(t,x,y) that interchanges
 * two arguments of type t.
 */

#define swap(t,x,y) { t temp; \
                    temp = x; \
                    x = y; \
                    y = temp; }


int main()
{


	int x = 5;
	int y = 10;

	printf("x = %d, y = %d\n", x, y);

	swap(int, x, y);

	printf("x = %d, y = %d\n", x, y);

	return 0;
}

void reverse(char s[], int lim) {
	reverse_s(s, lim, 0);
}

void reverse_s(char s[], int lim, int i) {
	char currentchar;
	if (i < lim) {
		reverse_s(s, lim - 1, i + 1);
		currentchar = s[i];
		s[i] = s[lim - 1];
		s[lim - 1] = currentchar;
	}
}
