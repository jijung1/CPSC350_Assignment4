
template <typename E>
class List {
public:
List();
virtual ~List();
virtual int getSize();
virtual bool empty();

};

template <typename E>
List<E>::List() {}

template <typename E>
List<E>::~List() {}

template <typename E>
int List<E>::getSize() {}

template <typename E>
bool List<E>::empty() {}
