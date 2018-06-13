Templated-List class


// list.h

// A templated list ADT, stores a list of itemType
// Will support the following operations:
/*	default constructor
	copy constructor
	destructor
	assignment (=)
	insert, only at tail of list, maintains list unordered
	print list, each item separated by 1 space
	length
	clear list
*/
	
#ifndef _list_h
#define _list_h

#include <iostream.h>

template<class itemType>
class list
{
	public:
		list();			// default constructor
		list(const list &);	// copy constructor
		~list();			// destructor
		void insert(const itemType&);		// insert item at end of list
		void print() const;			// print list
		int length() const;			// returns length of list
		const list& operator= (const list&);  // assignment operator
		void clear();			// clear list
	private:
		struct listNode
		{
			itemType  myItem;
			listNode  *next;
			
			listNode (itemType tempItem, listNode *tempNext)
				: myItem(tempItem), next(tempNext)
			{
			}
		};
				
		typedef listNode * listPtr;
		listPtr myFront, myTail;
};

template <class itemType>
list<itemType>::list()
{
	myFront = NULL;
}

 
template <class itemType>
list<itemType>::list(const list &oldList)	// copy constructor
// makes new list as a copy of old list
// I solved the overloaded operator= below, so I simply called the operator= function.
{
	if (this != &oldList)
	{
		myFront = NULL;		// necessary as (=) will check for empty list
		*this = oldList;
	}
}

template <class itemType>
list<itemType>::~list()
{
	clear();
}

template<class itemType>
void
list<itemType>::insert(const itemType &item)
// inserts the new item at the tail of the list
{
	if (myFront == NULL)
		myFront = myTail = new listNode (item, NULL);
	else
	{
		myTail->next = new listNode (item,  NULL);  
		myTail = myTail->next;
	}
}

template<class itemType>
void
list<itemType>::print()  const
{
	listPtr temp = myFront;
	while (temp != NULL)
	{
		cout << temp->myItem << "  ";
		temp = temp->next;
	}
}

template <class itemType>
int
list<itemType>::length()  const
{
	int n = 0;
	listPtr temp = myFront;
	
	while (temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	return n;
}

 
template<class itemType>
const list& 
list<itemType>::operator= (const list &otherList)
// Creates a duplicate copy of otherList
{
	listPtr temp;
	
	if (this != &otherList)
	{
		clear();		// destroy any existing list
		// myFront = NULL at this point	
		temp = otherList.myFront;
		if (temp != NULL)		// start the list
		{
			myFront = myTail = new listNode (temp->myItem, NULL);
			temp = temp->next;
		}
		while (temp != NULL)  // finish off the list
		{
			myTail->next = new listNode (temp->myItem, NULL);
			myTail = myTail->next;
			temp = temp->next;
		}
	}
	return *this;
}

template<class itemType>
void
list<itemType>::clear()
{
	listPtr temp = myFront;
	
	while (myFront != NULL)
	{
		myFront = myFront->next;
		delete temp;
		temp = myFront;
	}
}
			
#endif
