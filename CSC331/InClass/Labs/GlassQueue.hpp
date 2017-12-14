// -------------------------------------------
//      Class: Glass Queue
// Programmer: Charles Davis
//
// Queue data structure to hold glass colors.
//
// -------------------------------------------

#ifndef GLASSQUEUE_HPP
#define GLASSQUEUE_HPP

#include <iostream>

template <class Type>
class GlassQueue
{
	public:
		
		// ------------------------------
		//
		//	  Constructor and Destructor
		//
		// ------------------------------
		
		GlassQueue()
		{
			this->front = NULL;
			this->back = NULL;
		}

		~GlassQueue()
		{
			// Traverse queue, deleting items

			Node<Type>* tempNode = this->front;
			
			while (this->front != NULL)
			{
				this->front = this->front->next;

				delete tempNode;

				tempNode = this->front;
			}
		}

		// ------------------------------
		//
		//    Public Member Functions
		// 
		// ------------------------------

		// Check if queue has no items
		bool isEmpty()
		{
			return this->front == NULL;
		}

		// Add item to back of queue
		void enqueue(Type item)
		{
			// Create new node holding item
			Node<Type>* newNode = new Node<Type>(item);

			// If empty, add to front
			if (isEmpty())
			{
				// front and back pointers both point to only item
				this->front = newNode;
				this->back = newNode;
			}

			// Otherwise, add to back of queue
			this->back->next = newNode;
			this->back = newNode;
		}

		// Remove and retrieve item from front of queue
		Type dequeue()
		{
			// If empty, throw error message
			if (isEmpty())
			{
				throw "Queue is empty.\n";
			}

			// Create temporary Type variable to hold item
			Type temp = this->front->color;

			// Temporary node pointer for deletion
			Node<Type>* tempNode = this->front;

			// Move front pointer forward
			this->front = this->front->next;

			// Delete first item in queue
			delete tempNode;

			return temp;
		}

	private:

		// ------------------------------
		//
		//    Private Member Data
		// 
		// ------------------------------

		// Node used for each item in queue
		template <class C>
		struct Node
		{
			Node(C color)
			{
				this->color = color;
				this->next = NULL;
			}

			C color;
			Node* next;
		};

		// Pointer to front of queue
		Node<Type>* front;
		// Pointer to back of queue
		Node<Type>* back;
};

#endif // GLASSQUEUE_HPP
