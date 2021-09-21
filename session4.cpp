//
// Created by c2xu on 2021/9/17.
//

template <class T>
class MyNode{
public:

private:
    T data;
    MyNode<T>* nextptr;
};

template <class T>
class MyList{
public:
    MyList(){};
private:
MyNode<T> node;
};
int main(){

}