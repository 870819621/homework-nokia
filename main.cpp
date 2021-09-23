//
// Created by c2xu on 2021/9/17.
//

template <class T>
class MyNode {
public:
    T data;
    MyNode* nextptr;

    MyNode(T data) {
        this->data = data;
    }

    bool operator==(const MyNode& d) {
        return data == d.data;
    }

    bool operator==(T d) {
        return data == d;
    }
};

template <class T>
class MyList {
public:
    MyList(T data) {
        head = new MyNode<T>(data);
        head->nextptr = nullptr;
    };

    ~MyList() {
        while (head) {
            if (head->nextptr)
            {
                auto tmp = head;
                head = head->nextptr;
                delete tmp;
            }
        }
    }

    void insert(T data) {
        auto node =  new MyNode<T>(data);
        node->nextptr = head->nextptr;
        head->nextptr = node;
    }

    void erase(T data) {
        
       //todo
    }

    bool isContain(T data) {
        auto tmp = head;
        where(tmp) {
            //todo
        }
    }
private:
    MyNode<T>* head;
};
int main() {

}