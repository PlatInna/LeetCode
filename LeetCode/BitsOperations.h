#pragma once

#include <iostream>
#include <bitset>

void printBitsOperations() {
	int reg = 0;
	int bit_mask = 8;
	int signed_var = -8;
	int unsigned_var = 6;
	std::bitset<8> r(reg);
	std::bitset<8> bm(bit_mask);
	std::cout << "register " << r << '\n';
	std::cout << "bit_mask " << bm << '\n';
	std::cout << "(r & bm) " << (r & bm) << '\n';
	std::cout << "(r | bm) " << (r | bm) << '\n';
	std::cout << "(r ^ bm) " << (r ^ bm) << " // XOR" << '\n';
	std::cout << "(~bm)    " << (~bm) << '\n' << '\n';
	std::cout << "================ Bits shifting =================" << '\n';
	std::cout << "bm << 1  " << (bm << 1) << '\n';
	std::cout << "bm >> 3  " << (bm >> 3) << '\n';
	std::cout << signed_var << " (signed_var >> 2)   - division by 4           " << (signed_var >> 2) << '\n';
	std::cout << ' ' << unsigned_var << " (unsigned_var << 1) - multiplication by 2 " << (unsigned_var << 1) << '\n' << '\n';
}