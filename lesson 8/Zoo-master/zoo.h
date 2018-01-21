

struct Animal
{
	char type[64]; // что за животное
	char name[64]; // кличка
	int age;   // возраст
	int danger;  // опасно ли?
	struct Animal *next; // след. элемент списка
};

typedef struct Animal TAnimal;

// создание списка
TAnimal* create();
void     addTail(TAnimal *head);
void     printList(TAnimal *head);
int      searchAnimal(TAnimal *head, char* type);