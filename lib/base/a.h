template <typename T>
class Base {
  public: 
    int size;
    T** array;
    void fill();
    void print();
  protected: 
    Base(int);
    ~Base();
    void resize(int);
};