
template<class T>
class PrioElement
{
public:
	PrioElement() {}
	int priority() const { return prio; }
	void set_priority(int p) { this->prio = p; }
	bool operator<(const PrioElement& e) const { return prio < e.prio; }
	operator int() { return prio; }
	int getId() { return id; }
	inline void setId(int newId) { id = newId; }
	T getData() { return data; }
	void setData(T &data) { this->data = data; }
private:
	int prio;
	int id;
	T data;
};
