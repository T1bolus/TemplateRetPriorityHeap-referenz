
template<class T>
class PrioQueue
{
public:
	PrioQueue(int lenght = 1000);
	virtual ~PrioQueue();
	PrioElement<T>& maximum() const;
	PrioElement<T>& extractMax();
	void update(int,int);
	void insert(const PrioElement<T> &element);
	void remove(int);
	const unsigned int getSize() { return n; }

private:
	void upHeap(unsigned int);
	void downHeap(unsigned int pos);
	void swap(unsigned a, unsigned b);
	unsigned int getPosReferenz(unsigned int id);

	unsigned int n;
	unsigned int lenght;
	unsigned int fortlaufendeId;
	PrioElement<T> **field;
	unsigned int *nReferenz;
};

template<class T>
inline PrioQueue<T>::PrioQueue(int lenght = 1000)
{
	nReferenz = new unsigned int[lenght];

	this->lenght = lenght + 1;
	n = 0; 
	fortlaufendeId = 0;
	field = new PrioElement<T>*[this->lenght];
	field[0] = NULL;
	for (size_t i = 1; i < this->lenght; i++)
	{
		field[i] = NULL;
	}
}

template<class T>
inline PrioQueue<T>::~PrioQueue()
{
	for (size_t i = 0; i < lenght; i++)
	{
		if(field[i] != NULL)
			delete[] field[i];
	}
}

template<class T>
PrioElement<T> & PrioQueue<T>::maximum() const
{
	return *field[lenght];
}

template<class T>
PrioElement<T>& PrioQueue<T>::extractMax()
{
	if (n == 0) return *field[0];
	swap(1, n);
	n--;
	downHeap(1);
	return *field[n+1];
}

template<class T>
void PrioQueue<T>::insert(const PrioElement<T> &element)
{
	field[++n] = new PrioElement<T>(element);
	field[n]->setId(fortlaufendeId);
	nReferenz[fortlaufendeId++] = n;
	upHeap(n);
}

template<class T>
void PrioQueue<T>::upHeap(unsigned int pos)
{	
	while (pos > 1 && *field[pos / 2] < *field[pos]) 
	{
		swap(pos, pos / 2); 
		pos = pos / 2; 
    }
}

template<class T>
void PrioQueue<T>::downHeap(unsigned int pos)
{
	while (true)
	{

		if (pos * 2 <= n && *field[pos] < *field[pos * 2] && (n > pos * 2 + 1 ? *field[pos * 2] > *field[pos * 2 + 1] : true))
		{
			swap(pos, pos * 2);
			pos = pos * 2;
		}
		else if (pos * 2 + 1 <= n && *field[pos] < *field[pos * 2 + 1])
		{
			swap(pos, pos * 2 + 1);
			pos = pos * 2 + 1;
		}
		else
			break;
	}
}

/*
void PrioQueue::downHeap(unsigned int pos)
{
	while(2*pos <= n)
	{
		unsigned int j = 2*pos;
		if(j < n && *field[j] < *field[j+1])
			j++;
		if(*field[pos] < *field[j])
			break;
		swap(pos,j);
		pos = j;
	}
}
*/


template<class T>
inline void PrioQueue<T>::swap(unsigned a, unsigned b)
{
	PrioElement<T>* buf;
	buf = field[a];
	field[a] = field[b];
	field[b] = buf;

	nReferenz[a] = field[a]->getId();
	nReferenz[b] = field[b]->getId();
}

template<class T>
inline void PrioQueue<T>::update(int id, int d)
{
	unsigned int pos = getPosReferenz(id);
	if (pos == 0) return;


	field[pos]->set_priority(field[pos]->priority() + d);

	if (d > 0)
		upHeap(pos);
	else
		downHeap(pos);
}

template<class T>
inline void PrioQueue<T>::remove(int id)
{
	usigned int pos = getPosReferenz(id);
	if (pos == 0) return;

	nReferenz[id] = 0;

	swap(pos, n);
	n--;
	downHeap(pos);
}


template<class T>
inline unsigned int PrioQueue<T>::getPosReferenz(unsigned int id)
{
	return nReferenz[id];
}
