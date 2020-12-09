/*
uses postorder
*/
template<class ItemType>
void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if(subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr.reset();
	}

}	

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////


	
/////THis is based of the pseudocode so double check	
template<class ItemType>
virtual auto removeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)	
{
	if(subTreePtr->isLeaf())
	{
	///????? smart pointer deletion?
		return nullptr;
	}
	else if (	//the following code outputs xor
			(	(subTreePtr->getRightChildPtr() == nullptr) && 
			(subTreePtr->getLeftChildPtr() != nullptr)	)
			||
			(	(subTreePtr->getRightChildPtr() != nullptr) && 
			(subTreePtr->getLeftChildPtr() == nullptr)	)
		)
	{
		if(subTreePtr->getRightChildPtr() == nullptr)
		{
			auto nodeToConnectPtr = nodePtr->getLeftChldPtr();
		}
		else
		{
			auto nodeToConnectPtr = nodePtr->getRightChldPtr();
		}
		return nodeToConnectPtr;
	}
	else
	{
		auto tempValue;	
		auto tempPtr = removeLeftMostNode(subTreePtr->getRightChildPtr(), tempValue);
		subTreePtr->setItem(tempValue); 
		return subTreePtr;
	}
}	

template<class ItemType>
virtual auto removeLeftMostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
	ItemType& inOrderSuccessor)
{
	if(subTreePtr->getLeftChildPtr() ==nullptr)
	{
		inOrderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);	///remove node uses findSUccessorNode
	}
	else
	{
		auto tempPtr = removeLeftMostNode(subTreePtr->getLeftChildPtr(), 
			inOrderSuccessor);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;				
	}
}	

template<class ItemType>
virtual auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
	const ItemType target, bool& isSuccessful)
{
	if (subTreePtr == nullptr)
	{
		isSuccessful = false;
	}
	else if(subTreePtr->getItem() == target)
	{
		subTreePtr = removeNode(subTreePtr);///remove node uses findSUccessorNode
		isSuccessful = true;
	}
	else if(subTreePtr->getItem() > target)
	{
		tempPtr = removeValue(subTreePtr->getLeftChildPtr(),
			target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);	
	}
	else
	{
		tempPtr = removeValue(subTreePtr->getRightChildPtr(),
			target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);		
	}
	return subTreePtr;
}	

template<class ItemType>
bool remove(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)	
{
	bool isSusccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////
/*
•The method findNodeis designed to be utilized by a method getEntry.•The operation getEntrymust return the data item with the desired value if it exists; otherwise it must throw an exception NotFoundException. •The method, therefore, calls findNode and checks its return value.•If the desired target is found, getEntryreturns it.•If findNodereturns nullptr, getEntrythrows an exception.

*/
template<class ItemType>
virtual auto findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
	const ItemType& target, bool& isSuccessful) const
{
	if(subTreePtr == nullptr)
	{
		return nullptr;
	}
	else if(subTreePtr->getItem() == target)
	{
		return subTreePtr;
	}
	else if(subTreePtr->getItem() > target)
	{
		return findNode(subTreePtr->getLeftChildPtr(), target);
	}
	else
	{
		return findNode(subTreePtr->getRightChildPtr(), target);
	}		
}	

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////	

//uses preorder
template<class ItemType>
virtual auto copyTree(std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
	
	if(oldTreeRootPtr !=nullptr)
	{
		newTreePtr = std::make_shared<BinaryNode<ItemType>>
			(oldTreeRootPtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));	
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));		
	}
	return newTreePtr;
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////

template<class ItemType>
auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if (	getHeightHelper(getLeftChildPtr()) > getHeightHelper(getRightChildPtr())	)
	{
		subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
		subTreePtr->setLeftChildPtr(moveValuesUpTree(getLeftChildPtr());
		//subTreePtr->setLeftChildPtr(leftPtr);//do i need his line? no not really
		return subTreePtr;
	}
	else if (subTreePtr->getRightChildPtr() != nullptr)
	{
		
		subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
		subTreePtr->setRightChildPtr(moveValuesUpTree(getRightChildPtr());       
		////
		return subTreePtr;
	}
	else 
	{
		return nullptr;
	}  
}















