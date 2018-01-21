#include "countries.h"

int mkArray(struct COUNTRY **arr, FILE *fp)
{
	int count = 0, number = 0;
	struct COUNTRY *parr;
	char buf[256];
	while (fgets(buf, 256, fp))
		count++;
	parr = (struct COUNTRY*) calloc(count, sizeof(struct COUNTRY));
	rewind(fp);
	while (fgets(buf, 256, fp))
	{
		if (checkLine(buf))
		{
			setStruct(parr + number, buf);
			number++;
		}
	}
	*arr = parr;
	return number;
}


void setStruct(struct COUNTRY *country, char *line)
{
	char tmp[4];
	char *p = line;
	p = copySub(p,tmp); //id
	country->unid = atoi(tmp);
	p = copySub(p + 1, country->abr2);
	p = copySub(p + 1, country->abr3);
	p = copySub(p + 1, country->name);
	copySub(p + 1, country->capital);
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
	p = copySub(p+1, tmp); //AA
	if (strlen(tmp) != 2)
		return 0;
	p = copySub(p + 1, tmp); //AAA
	if (strlen(tmp) != 3)
		return 0;
	return 1;
}