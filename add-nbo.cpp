#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

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

	uint32_t n1_hbo = ntohl(n1);
	uint32_t n2_hbo = ntohl(n2);
	uint32_t res = n1_hbo + n2_hbo;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", n1_hbo, n1_hbo, n2_hbo, n2_hbo, res, res); 

	fclose(fp1);
	fclose(fp2);

	return 0;

}

