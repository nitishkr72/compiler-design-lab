#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 100
#define N 10

int main() {
	FILE * infile_dec, * infile_bin;
	char fname_dec[BUFF_SIZE], fname_bin[BUFF_SIZE];

	char sData[BUFF_SIZE];

	printf("Enter the filename(saving in text format): ");
	scanf("%s", fname_dec);
	if((infile_dec = fopen(fname_dec, "w")) == NULL)
		return 1;

	printf("Enter the filename(saving in binary format): ");
	scanf("%s", fname_bin);
	if((infile_bin = fopen(fname_bin, "wb")) == NULL)
		return 1;

	int i = 0;
	printf("Enter Name and roll Number eg.'>> Nitish CSB18040'\n");
	while(i <= N && fgets(sData, BUFF_SIZE, stdin)) {
		int k = sizeof(sData);
		sData[k++] = '\n';
		sData[k++] = '\0';
		fputs(sData, infile_dec);
		fwrite(sData, sizeof(sData), 1, infile_bin);
		i++;
	}

	fclose(infile_dec);
	fclose(infile_bin);

	return 0;
}
