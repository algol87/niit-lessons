#define SIZE 5

struct SYM
{ 
	unsigned char ch;
	float freq;
	char code[256];
	struct SYM *left;
	struct SYM *right; 
};

struct SYM* buildTree(struct SYM *psym[], int N) 
{ 
	// создаЄм временный узел 
	struct SYM *temp=(struct SYM*)malloc(sizeof(struct SYM)); 
	// в поле частоты записываетс€ сумма частот 
	// последнего и предпоследнего элементов массива psym
	temp->freq=psym[N-2]->freq+psym[N-1]->freq; 
	// св€зываем созданный узел с двум€ последними узлами 
	temp->left=psym[N-1]; 
	temp->right=psym[N-2]; 
	temp->code[0]=0; 
	if(N==2) // мы сформировали корневой элемент с частотой 1.0 
		return temp; 
	// добавл€ем temp в нужную позицию psym, 
	// сохран€€ пор€док убывани€ частоты 
	int i = 0;
	while (i<N && temp->freq > psym[N - i - 1]->freq)
	{
		psym[N - i] = psym[N - i-1];
		psym[N - i-1] = temp;
		i++;
	}

	return buildTree(psym,N-1); 
}

void makeCodes(struct SYM *root) 
{ 
	if (root->left) 
	{ 
		strcpy(root->left->code, root->code);
		strcat(root->left->code, "0");
		makeCodes(root->left);
	} 
	if (root->right) 
	{ 
		strcpy(root->right->code, root->code);
		strcat(root->right->code, "1");
		makeCodes(root->right); 
	} 
}





int  main()
{	
	struct SYM arr[SIZE];
	struct SYM* psym[SIZE];
	arr[0].ch = 'A';
	arr[0].freq = 0.3;
	arr[0].code[0] = '\0';
	arr[1].ch = 'B';
	arr[1].freq = 0.25;
	arr[1].code[0] = '\0';
	arr[2].ch = 'C';
	arr[2].freq = 0.2;
	arr[2].code[0] = '\0';
	arr[3].ch = 'D';
	arr[3].freq = 0.15;
	arr[3].code[0] = '\0';
	arr[4].ch = 'E';
	arr[4].freq = 0.1;
	arr[4].code[0] = '\0';
	for (int i = 0; i < SIZE; i++)
	{
		psym[i] = arr+i;
	}
	buildTree(psym, SIZE);

		


	return 0;
}