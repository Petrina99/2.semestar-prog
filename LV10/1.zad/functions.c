#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int izracunajSumu(int n) {

	if (n == 0) {
		return 0;
	}

	return (n % 10 + izracunajSumu(n / 10));

}
