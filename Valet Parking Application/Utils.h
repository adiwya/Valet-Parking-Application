// Name: Aparajeeta Diwya

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds
{
	int strlen(const char* str);
	void strcpy(char* des, const char* src, int len = -1);
	int strcmp(const char* s1, const char* s2);

	const char* toUpperCase(char* string);
}
#endif // !
