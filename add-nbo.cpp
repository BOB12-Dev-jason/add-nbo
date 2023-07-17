#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUF_SIZE 256

int main(int argc, char **argv) {

	if(argc != 3) {
		puts("syntax : add-nbo <file1> <file2>");
		puts("sample : add-nbo a.bin b.bin");
		return 0;
	}

	FILE *fp1, *fp2;

	const char* filename1 = argv[1];
	const char* filename2 = argv[2];

	fp1 = fopen(filename1, "rb"); // 텍스트 모드로 open
	fp2 = fopen(filename2, "rb");
						 //

	if (!fp1 || !fp2){  
		puts("file open error\n");
		return 0;
	}

	uint32_t n1, n2;
	fread(&n1, sizeof(uint32_t), 1, fp1);
	fread(&n2, sizeof(uint32_t), 1, fp2);

	printf("%x\n", n1);
	printf("%x\n", n2);

	fclose(fp1);
	fclose(fp2);

	return 0;

}

