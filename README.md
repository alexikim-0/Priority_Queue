In this project a priority queue data structure will be implemented as a class named MyPriorityQueue. The implementation must be an array-based binary min-heap. The MyPriorityQueue class consists of the following functions which you are responsible for implementing and have been started for you in include/MyPriorityQueue.hpp:

MyPriorityQueue()


This is the constructor for the class. You should initialize any variables you add to the class here. Namely, you’ll want to consider what structure you’ll use to store the elements of your priority queue (hint: some kind of indexable array-like structure) and how it will be initialized.

~MyPriorityQueue()


This is the class destructor. You are responsible for freeing any allocated memory here. You will most likely be allocating memory to store the elements in the priority queue themselves. You are allowed to use std::vector in this project, which does allocate and free memory for you. If you decide to use a dynamically allocated array you will be responsible for freeing that yourself.

size_t size() const noexcept


This function returns the number of elements stored in the priority queue. It returns the count as a size_t. It is marked const (also known as a constant member function) because it should not modify any member variables that you’ve added to the class or call any function functions that are not marked const as well. The advantage of marking this function as const is that it can be called on constant MyPriorityQueue instances. It also allows the compiler to make additional optimizations since it can assume the object this function is called on is not changed. This is a fairly good StackOverflow answer that goes into additional detail.

bool isEmpty() const noexcept


This function simply returns whether or not the priority queue is empty, or in other words, if it does not contain any elements. Marked const because it should not change any member data. Marked noexcept because it should not throw any exceptions.

void insert(const Object & elem)


Insert an element of type Object into the priority queue. Recall from lecture that min-heaps have two properties:

They are a complete binary tree (not necessarily a binary search tree).
No parent has a value greater than either of its children.

We went over the insert procedure in the lecture. The key idea is to insert the element in the bottom-most, left-most empty position (hence violating min-heap property #2 above, but preserving tree completeness), and then “percolating” the element up until the min-heap property is restored. Note that this should happen in O(log n) time where n is the number of nodes.

const Object & min() const


Simply returns a constant reference to the minimum element in the priority queue. This should be pretty easy if you implemented the min-heap correctly. Note that this function is marked const because it should not modify any internal data of the MyPriorityQueue instance. Namely, it should not alter the structure of your heap. This function should run in O(1) time. Note: there is not a non-const version of min() for this project. If the queue is empty, this function should throw a PriorityQueueEmptyException.

void extractMin()


Removes the minimum element from the priority queue. This interface is similar to the C++ container interface where top() is used to get the top-most element, and pop() is used to remove it, but pop() does not actually return the element itself. Just replace top() with min() and pop() with extractMin() conceptually. Note that because the heap invariants must be maintained, this function should also “fix” the heap after the minimum element has been removed. We went over this “fix” procedure as well in lecture. The key ideas are to replace the removed node with the bottom-most, rightmost filled node (preserves tree completeness property), and the “push down” this node until it’s in a spot that no longer violates the min-heap property. A “push-down” involves a swap with the smallest child (value-wise, not height-wise). This function should run in O(log n) time. If the queue is empty, this function should throw a PriorityQueueEmptyException.


Part 2: Word Ladder 


std::vector<std::string> convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)


This function will return the conversion between s1 and s2, according to the lowest Lewis Carroll distance. The first element of the vector should be s1, the last s2, and each consecutive should be one letter apart. Each element should be a valid word. If there are two or more equally least Lewis Carroll distance ways to convert between the two words, you may return any of them.


If there is no path between s1 and s2,  or if they are the same string, return an empty vector. 

When we want to look for the next word to process, we are going to select the node with the smallest sum of two values:  the first is the Lewis Carroll distance from the start and the second is the number of letters in the word that still differ from s2. In other words, we will be using the following heuristic equation:

H(s1, current, s2) = LCD(s1, current) + LetterDelta(current, s2)


Where:
LCD(x, y) is the Lewis Carroll distance between word x and word y.
LetterDelta(x, y) is the number of letters which are different between x and y.
   

Example:

WordLadder and → art:

H(and, ant, art) = LCD(and, ant) + LetterDelta(ant, art) = 1 + 1 = 2

Thus, for a search from and to art the word ant would be given a heuristic value of 2.

You must be able to insert 1,000,000 integers into your PriorityQueue in 5 seconds on OpenLab.
You must be able to call extractMin() 1,000,000 times on a PriorityQueue starting with 1,000,000 integers in 5 seconds.
The convert tests will be given time proportional to the ladder length. Though, they should run extremely quickly. To be concrete, the “BankingToBrewing” test will be given 1 second to run.
