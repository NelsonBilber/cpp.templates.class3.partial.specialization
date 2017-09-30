#include <iostream>
#include <vector>

using namespace std;

//Partial specialization
template<typename T, int colums>
class PrettyPrinter
{
    T * m_pData;
public:
    PrettyPrinter(T* data): m_pData(data)
    {}
    
    void Print()
    {
        cout << "Colums: " << colums << endl;
        cout << "{" << *m_pData << "}" << endl;
    }
  
    T * GetData(){
        return m_pData;
    }
    
};

template<typename T>
class SmartPointer
{
    T *m_ptr;
public:
    SmartPointer(T *ptr): m_ptr(ptr){}
    
    ~SmartPointer() {
        cout << "~SmartPointer1" << endl;
        delete m_ptr;
    }
    
    T* operator ->(){
        cout << "-> operator" << endl;
        return m_ptr;
    }
    
    T& operator*() {
        cout << "* operator" << endl;
        return *m_ptr;
    }
    
};


//Specialization for array points
template<typename T>
class SmartPointer<T[]>
{
    T *m_ptr;
public:
    SmartPointer(T *ptr): m_ptr(ptr){}
    
    ~SmartPointer() {
        cout << "~SmartPointer2" << endl;
        delete [] m_ptr;
    }
    
    T& operator[](int index)
    {
        cout << "[] operator" << endl;
        return m_ptr[index];
    }
    
};


int main()
{
    int data = 800;
    PrettyPrinter<int, 40> p{&data};
    p.Print();
    
    SmartPointer<int> s1 {new int(3)};
    cout << *s1 << endl;
    
    SmartPointer<int[]> s2 {new int[3]};
    s2[0]=5;
    cout << s2[0] << endl;
    

 	return 0;
}
