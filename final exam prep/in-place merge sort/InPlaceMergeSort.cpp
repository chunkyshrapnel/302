/*
Implement Merge Sort i.e. standard implementation keeping the sorting algorithm as in-place.
In-place means it does not occupy extra memory for merge operation as in standard case.


    Maintain two pointers which point to first of the segments which have to be merged.
    Compare the elements at which the pointers are present.
    If element1 < element2 then element1 is at right position, simply increase pointer1.
    Else place element2 in its right position and all the elements at the right of element2 will be shifted right by one position. Increment all the pointers by 1.
    
    Standaard merge sort	=	O(nLogn)
    In-place merge sort	=	O(n^2)
*/

template <class ItemType>
void merge(ItemType arr[], int first, int mid, int last) 
{ 

	if (arr[mid] <= arr[first2])
	{ 
		return; 
	} 
    
	int first2 = mid + 1; 
	  
	while (first <= mid && first2 <= last)
	{ 
		  

		if (arr[first] <= arr[first2])
		{ 
			first++; 
		} 
		else 
		{ 
			ItemType temp = arr[first2]; 
			int i = first2; 
			  

			while (i != first) 
			{ 
				arr[i] = arr[i - 1]; 
				i--; 
			} 
			arr[first] = temp; 
			  
			 
			first++; 
			mid++; 
			first2++; 
		} 
	} 
} 
  
template <class ItemType>
void mergeSort(int arr[], int Left, int Right) 
{ 
	if (Left < Right)
	{
		int Middle = (l + r) / 2,;  
		mergeSort(arr, Left, Middle); 
		mergeSort(arr, Middle + 1, Right);   
		merge(arr, Left, Middle, Right); 
	} 
} 

