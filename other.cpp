#include "ccstream.h"





template <class Tmplt, class Tmplt2>
bool IsIncluded(Tmplt2 Elemento, Tmplt First, Tmplt Second, int Type)
{
	switch (Type)
	{
	case 0:
		if (Elemento >= First && Elemento <= Second)
			return true;
		break;
	case 1:
		if (Elemento <= First && Elemento >= Second)
			return true;
		break;
	}

	return false;
}