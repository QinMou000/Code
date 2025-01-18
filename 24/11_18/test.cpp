#include<iostream>
#include<memory>
#include<functional>
#include<atomic>
using namespace std;
namespace Qin
{
    template<class T>
    class Share_ptr
    {
    public:
        Share_ptr(T* ptr)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
        {
            cout << "Share_ptr(T* ptr)" << endl;
        }
        template<class D>
        Share_ptr(T* ptr, D del)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
            , _del(del)
        {
            cout << "Share_ptr(T* ptr, D del)" << endl;
        }
        ~Share_ptr()
        {
            if (--(*_pcount) == 0)
            {
                //delete _ptr;
                _del(_ptr);
                // 这里因为ptr指向的可能是由new[]创建，也有可能是
                // 文件指针，所以需要一个定制删除器，以保证正确删除
                delete _pcount;
            }
            cout << "~Share_ptr()" << endl;

        }
        Share_ptr(const Share_ptr<T>& sp)
            : _ptr(sp._ptr)
            , _pcount(sp._pcount)
        {
            (*_pcount)++;
            cout << "Share_ptr(const Share_ptr<T>& sp)" << endl;

        }
        Share_ptr<T>& operator=(const Share_ptr<T>& sp)
        {
            if (_ptr != sp._ptr)
            {
                if (--(*_pcount) == 0)
                {
                    delete _ptr;
                    delete _pcount;
                }
                _pcount = sp._pcount;
                _ptr = sp._ptr;
                (*_pcount)++;
            }
            return *this;
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
        int use_count()
        {
            return *_pcount;
        }
    private:
        T* _ptr;
        atomic<int>* _pcount;  // 原子操作
        function<void(T*)> _del = [](T* ptr) {delete ptr; };
        // 这里因为ptr指向的可能是由new[]创建，也有可能是文件指针
        // ，所以需要一个定制删除器，以保证正确删除
    };
};

int main()
{
    string s = "ssss";
    Qin::Share_ptr<string> sptr1(new string("1111"));
    Qin::Share_ptr<string> sptr2 = sptr1;
    Qin::Share_ptr<string> sptr3 = sptr1;
    Qin::Share_ptr<string> sptr4 = sptr1;

    cout << sptr4->c_str() << endl;
    
    return 0;
}
