#include <iostream>
#include <fstream>
using namespace std;

class Stack
{
	enum { EMPTY = -1 };
	int size;
	int* arr;
	int top;
public:
	Stack() = delete;

	Stack(int size) :size(size)//-20
	{
		if(size<0)throw invalid_argument("Size is less than 0");
		arr = new int[size];//20
		top = EMPTY;
	}
	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(int element)
	{
		if (IsFull())Resize();
		if (!IsFull())
		{
			arr[++top] = element;
			return true;
		}
		else {
			throw exception("Stack is full");
		}
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
			return arr[top--];
		else {
			throw exception("Stack is empty");
		}
	}
	int Peek()const
	{
		if (!IsEmpty())
			return arr[top];
		else {
			throw exception("Stack is empty");
		}
	}
	int GetCount()
	{
		return top + 1;
	}
	void Clear()
	{
		top = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack()
	{
		delete[]arr;
	}
	void Resize()
	{
		size *= 2;
		int* temp = new int[size];
		for (int i = 0; i <= top; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
	}
};

int main()
{
	try {
		Stack st(3);
		st.Push(1);
		st.Push(2);
		st.Push(3);
		//st.Print();
		#pragma region Binary Mode
		ofstream fileOut("binary.bin", ios_base::out | ios_base::binary);
		fileOut.write((char*)&st, sizeof(st));
		fileOut.close();
		//st.Clear();
		//st.Pop();
		//st.Peek();
		//Stack st1(-3);
		ifstream fileIn("binary.bin", ios_base::in | ios_base::binary);
		Stack stackIn(st.GetCount());
		fileIn.read((char*)&stackIn, sizeof(stackIn));
		fileIn.close();
		cout << "stackIn: " ;
		stackIn.Print();
		#pragma endregion
		system("pause");
	}
	catch(invalid_argument& e){
		cout << e.what() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}
