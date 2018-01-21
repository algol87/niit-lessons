#include "country.h"


struct COUNTRY* mklist(FILE *fp)
{
	struct COUNTRY *item=NULL;
	char buf[256];

	while (fgets(buf, 256, fp))
	{
		if (item == NULL)
		{
			if (checkLine(buf))
			{
				item = create(buf);
			}
		}
		else
		if (checkLine(buf))
		{
			addTail(item,buf);
		}
	}
	return item;
}


void addTail(struct COUNTRY* head, char* line)

{

	while (head->next)

		head = head->next;

	head->next = create(line);

}

struct COUNTRY* create(char *line)
{
	struct COUNTRY *item;
	item = (struct COUNTRY*) calloc(1, sizeof(struct COUNTRY));
	char tmp[4];
	char *p = line;
	p = copySub(p, tmp); //id
	item->unid = atoi(tmp);
	p = copySub(p + 1, item->abr2);
	p = copySub(p + 1, item->abr3);
	p = copySub(p + 1, item->name);
	copySub(p + 1, item->capital);
	item->next = NULL;
	return item;
}

char* copySub(char *where, char *to)
{
	while (*where != ',' && *where != '\n' && *where != '\0')
		*to++ = *where++;
	*to = '\0';
	return where;
}


int checkLine(char *line)
{
	char tmp[256];
	char *p = line;
	p = copySub(p, tmp); //id
	if (strlen(tmp) != 3)
		return 0;
	if (atoi(tmp) == 0)
		return 0;
	p = copySub(p + 1, tmp); //AA
	if (strlen(tmp) != 2)
		return 0;
	p = copySub(p + 1, tmp); //AAA
	if (strlen(tmp) != 3)
		return 0;
	return 1;
}