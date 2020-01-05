// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.27 HE
// Date (Modified): 12020.01.05 HE
// License: apache-2.0

#include "equah/sblint.h"

// [>] Bytes To Integer
// [i] Converts an SBLInt char array to an integer.
// [P] {unsigned char *} b => Char array to read SBLInt from.
// [P] {size_t} b_len => Available space to read SBLInt from char rray.
// [P] {equah_sbsint__DEFAULT_INT_TYPE *} i => Integer to store SBLInt value.
// [R] {size_t} => Amount of bytes read for SBLInt.
size_t equah_sblint__bytes_to_int(unsigned char *b, size_t b_len, equah_sblint__DEFAULT_INT_TYPE *i) {
	
	equah_sbsint__DEFAULT_INT_TYPE sblint_len;
	size_t pos = equah_sbsint__bytes_to_int(b, b_len, &sblint_len);
	*i = 0;
	
	while (sblint_len >= 1) {
		*i += b[pos] << (8 * (sblint_len - 1));
		sblint_len--;
		pos++;
	}
	
	return pos;
}

// [>] Integer To Bytes
// [i] Converts an integer to SBLInt char array.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to convert to SBLInt bytes.
// [P] {unsigned char *} b => Char buffer to write SBLInt.
// [P] {size_t} b_len => Amount of available space in buffer.
// [R] {size_t} => Amount of bytes written for SBLInt.
size_t equah_sblint__int_to_bytes(equah_sblint__DEFAULT_INT_TYPE i, unsigned char *b, size_t b_len) {
	
	size_t size = equah_sblint__required_int_bytes(i);
	size_t shift = size;
	
	size_t pos = equah_sbsint__int_to_bytes(size, b, b_len);
	
	while (shift > 0) {
		b[pos] = (i >> (8 * (shift - 1))) & 0xFF;
		pos++;
		shift--;
	}
	
	return size;
}

// [>] Required Bytes
// [i] Calculates the total amount of required bytes for a given number.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to get required size of.
// [R] {size_t} => Required array length to store given integer.
size_t equah_sblint__required_bytes(equah_sblint__DEFAULT_INT_TYPE i) {
	
	size_t size = equah_sblint__required_int_bytes(i);
	size += equah_sbsint__required_bytes(size);
	
	return size;
}

// [>] Required Integer Bytes
// [i] Computes the amount of required bytes to represent the integer itself.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to get required size of.
// [R] {size_t} => Required array length to store given integer.
size_t equah_sblint__required_int_bytes(equah_sblint__DEFAULT_INT_TYPE i) {
	
	size_t size = 0;
	equah_sblint__DEFAULT_INT_TYPE compare = 0;
	
	while (i > compare) {
		compare = compare + (0xFF << (8 * size));
		size++;
	}
	
	return size;
}
