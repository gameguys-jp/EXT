#include "function.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <psxgpu.h>
#include <string.h>


#define SIN_TABLE_SIZE 91

static const int sin_table[SIN_TABLE_SIZE] = {
	    0, 2, 4, 7, 9, 11, 13, 15, 18, 20, 22, 24, 26, 29, 31, 33, 35,
    37, 39, 41, 43, 46, 48, 50, 52, 54, 56, 58, 60, 62, 63, 65,
    67, 69, 71, 73, 75, 76, 78, 80, 82, 83, 85, 87, 88, 90, 91,
    93, 94, 96, 97, 99, 100, 101, 103, 104, 105, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 119, 120,
    121, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126,
    126, 127, 127, 127, 127, 127, 127
};

int sin_lookup(int angle) {
	angle %= 360;
	if (angle < 0) {
		angle += 360;
	}
	
	int value;
	if (angle < 90) {
		value = sin_table[angle];
	} 
	else if (angle < 180) {
		value = sin_table[180 - angle];
	} 
	else if (angle < 270) {
		value = -sin_table[angle - 180];
	} 
	else if (angle < 360) {
		value = -sin_table[360 - angle];
	}
	
	return value;
}

