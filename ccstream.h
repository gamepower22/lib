#pragma once
#ifndef cstream_h_included
#define ccstream_h_included

class Get
{
public:
	
	void str(char * s, int dim);

	int num(int dim);



};


template <class Tmplt, class Tmplt2>
bool IsIncluded(Tmplt2 Elemento, Tmplt First, Tmplt Second, int Type);
#endif //ccstream
