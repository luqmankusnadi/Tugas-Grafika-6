#include "matrix.h"

bool freeMatrix [768][1024];

void initMatrix() {
	for (int i = 0; i < 768; i++) {
		for (int j = 0; j < 1024; j++) {
			freeMatrix[i][j] = true;
		}
	}
}
