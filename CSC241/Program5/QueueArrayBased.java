public class QueueArrayBased
{
	private final int MAX_QUEUE = 50; // max size of queue
	private Object[] items;
	private int front, back, count;

	public QueueArrayBased()
	{
		items = new Object[MAX_QUEUE];
		front = 0;
		back = MAX_QUEUE-1;
		count = 0;
	}

	public boolean isEmpty()
	{
		return count == 0;
	}

	public boolean isFull()
	{
		return count == MAX_QUEUE;
	}

	public void enqueue(Object newItem)
	{
		if (!isFull())
		{
			back = (back+1) % MAX_QUEUE;
			items[back] = newItem;
			++count;
		}
	}

	public Object dequeue()
	{
		if (!isEmpty())
		{
			Object queueFront = items[front];
			front = (front+1) % MAX_QUEUE;
			--count;
			return queueFront;
		}
	}
