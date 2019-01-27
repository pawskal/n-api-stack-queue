template <class T>
class Base {
  public: 
    int size;
    T* array;
    void fill();
    void print();
  protected: 
    Base(int);
    void resize(int);
};