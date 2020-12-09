template<class ItemType>
 auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
 	std::shared_ptr<BinaryNode<ItemType>> newNodePtr)	
 {
 	if(subTreePtr == nullptr)
 	{
 		return newNodePtr;
 	}
 	else
 	{
 		auto leftPtr = subTreePtr->getLeftChildPtr();
 		auto rightPtr = subTreePtr->getRightChildPtr();
 		
 		if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
 		{
 			rightPtr = balancedAdd(rightPtr, newNodePtr);
 			subTreePtr->getRightChildPtr(rightPtr);
 		}
 		else
 		{
 			leftPtr = balancedAdd(leftPtr, newNodePtr);
 			subTreePtr->setLeftChild(leftPtr);
 		}
 		return subTreePtr;
 	}
 }	
 

 
template<class ItemType>
bool add(const ItemType& newData)
{
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>> newData;
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
} 	
	
 		
