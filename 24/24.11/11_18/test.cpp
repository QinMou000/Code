#define _CRT_SECURE_NO_WARNINGS 1
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
                // ������Ϊptrָ��Ŀ�������new[]������Ҳ�п�����
                // �ļ�ָ�룬������Ҫһ������ɾ�������Ա�֤��ȷɾ��
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
        atomic<int>* _pcount;  // ԭ�Ӳ���
        function<void(T*)> _del = [](T* ptr) {delete ptr; };
        // ������Ϊptrָ��Ŀ�������new[]������Ҳ�п������ļ�ָ��
        // ��������Ҫһ������ɾ�������Ա�֤��ȷɾ��
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