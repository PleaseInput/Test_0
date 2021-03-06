// test_openssl.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/aes.h>

using namespace std;

int main()
{
	ofstream aes_c_txt("C:\\Users\\AnOwl\\Desktop\\aes128_c_vs.txt");
	ofstream aes_r_txt("C:\\Users\\AnOwl\\Desktop\\aes128_r_vs.txt");

	if (!aes_c_txt || !aes_r_txt) {
		cout << "cannot open file" << endl;
		return -1;
	}

	unsigned char aes_k[AES_BLOCK_SIZE];
	unsigned char aes_m[AES_BLOCK_SIZE];
	unsigned char aes_c[AES_BLOCK_SIZE];
	unsigned char aes_r[AES_BLOCK_SIZE];

	memset(aes_m, '0', sizeof(aes_m));
	//strcpy_s((char *)aes_m, AES_BLOCK_SIZE, "000000000000000");
	cout << "aes_m : " << aes_m << endl;

	memset(aes_k, '0', sizeof(aes_k));
	//strcpy_s((char *)aes_k, AES_BLOCK_SIZE, "000000000000000");
	cout << "aes_k : " << aes_k << endl;

	AES_KEY aes_key;
	AES_set_encrypt_key(aes_k, 128, &aes_key);
	AES_encrypt(aes_m, aes_c, &aes_key);
	//cout << "aes_c : " << aes_c << endl;
	aes_c_txt.write((const char*)aes_c, sizeof(aes_c));

	AES_set_decrypt_key(aes_k, 128, &aes_key);
	AES_decrypt(aes_c, aes_r, &aes_key);
	//cout << "aes_r : " << aes_r << endl;
	aes_r_txt.write((const char*)aes_r, sizeof(aes_r));

	/*ifstream fin_aes_key;
	string tmp;
	
	fin_aes_key.open("C:\\Users\\AnOwl\\Desktop\\aes_key.txt");
	
	if (!fin_aes_key)
		return -1;*/

	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
