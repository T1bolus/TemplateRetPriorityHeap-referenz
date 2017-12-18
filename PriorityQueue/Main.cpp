
#include "Includes.h"



int main()
{
	PrioQueue<int> schlange;
	PrioElement<int> ins;
	
	int bla = -3;
	ins.setData(bla);
	ins.set_priority(bla);
	schlange.insert(ins);

	bla = -2;
	ins.setData(bla);
	ins.set_priority(bla);
	schlange.insert(ins);


	bla = -6;
	ins.setData(bla);
	ins.set_priority(bla);
	schlange.insert(ins);


	bla = -1;
	ins.setData(bla);
	ins.set_priority(bla);
	schlange.insert(ins);


	cout << -schlange.extractMax().getData() << endl;
	cout << -schlange.extractMax().getData() << endl;
	cout << -schlange.extractMax().getData() << endl;
	cout << -schlange.extractMax().getData() << endl;
}
