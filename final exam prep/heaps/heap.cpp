//

/*
std::make_heap
std::push_heap
std::pop_heap
std::sort_heap
std::is_heap
std::is_heap_until
std::reverse
*/

#include <iostream>
#include <algorithm>

using namespace stad;

void randGen(vector<int> &heap)
{
	int temp;
	srand (time(nullptr));
	for(int c = 0; c < 100; c++)
	{
		temp = rand() % (1000) + 1;heap.push_back(temp);
	}
}

#include <vector>
int heapmean(vector<int> &heap)
{
	int total = 0;
	for(auto i = heap.begin(); i != heap.end(); ++i)
	{
		total += *i;
	}
	total = total/100;
	return total;
}

int main()
{
	vector<int> heap1;
	
	randGen(heap1);//At this point it is not a heap but a normal vector
	
	
/*
////////here is where we would output the vector
cout << "Our Vector of 100 random integers" << endl;
for(auto i = heap1.begin() ; i != heap1.end(); ++i){
cout << *i << " ";
}
*/
	make_heap(heap1.begin(), heap1.end());

/*
cout << endl << endl << "The Original Heap" << endl << endl;
for(auto i = heap1.begin() ; i != heap1.end(); ++i){
cout << *i << " ";
}
*/
	int mean = heapmean(heap1);
	
	heap1.push_back(mean);	//adds as vector
	push_heap(heap1.begin(), heap1.end()); //turns back into a heap
	
	
/*
Example of using std::pop_heap​-
Pop element from heap range: Rearranges the elements in the heap range[first,last) in such a way that the part considereda heap is shortened by one: The element with the highest value is moved to (last-1)
*/
	pop_heap(heap1.begin(), heap1.end());//max of heap is deleted
	heap1.pop_back();//this decreases the vector size by 1
	
	make_heap(heap1.begin(); i != heap1.end(); ++i)
	
}
