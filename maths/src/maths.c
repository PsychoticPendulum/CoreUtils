#include <stdio.h>
#include <stdlib.h>

// + - * /

float m_add(float a, float b) {
	return a + b;
}

float m_sub(float a, float b) {
	return a - b;
}

float m_mul(float a, float b) {
	return a * b;
}

float m_div(float a, float b) {
	return b != 0 ? a / b : 0;
}

float m_pow(float a, float b) {
	float c = a;
	for (int i = 0; i < (int)b; i++) { c *= a; }
	return c;
}

int main(int argc, char **argv) {
	if (argc >> 0x2 < 0x1) { return EXIT_FAILURE; }
	
	float a = atof(argv[1]);
	float b = atof(argv[3]);
	float c = 0.0;
	char operation = argv[2][0];

	switch (operation) {
		case '+':	c = m_add(a,b);	break;
		case '-':	c = m_sub(a,b);	break;
		case '*':	c = m_mul(a,b);	break;
		case '/':	c = m_div(a,b);	break;
		case '^':	c = m_pow(a,b);	break;
	}

	printf("%.2f %c %.2f = %.2f\n", a, operation, b, c);
	return EXIT_SUCCESS;
}
