#pragma once
#include<vector>
template<class K>
struct SetKeyOfT
{
    const K& operator()(const K& key)
    {
        return key;
    }
};
namespace CLOSE_HASH
{
    enum State
    {
        EMPTY,
        EXIST,
        DELETE
    };

    template<class T>
    struct HashData
    {
        T _data;
        State _state;
    };

    template<class  K, class T, class KeyOfT>
    class HashTable
    {
        typedef HashData<T> HashData;
    public:
        bool insert(const T& d)
        {
            KeyOfT koft;
            //增加负载因子，增容

            //报错，——tables初始化为零，崩掉
            //if ( _tables.size()==0||_num * 10 / _tables.size() >= 7 )
            //{
            //    //开新表 遍历旧表 重新计算新表位置  释放旧表
            //    vector<HashData> newtable;
            //    size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
            //    newtable.resize(newsize);
            //    for (size_t i = 0; i < _tables.size(); ++i)
            //    {
            //        if (_tables[i]._state == EXIST)
            //        {
            //            size_t index = koft(_tables[i]._data) % _tables.size();
            //            while (newtable[index]._state == EXIST)
            //            {
            //                ++index;
            //                if (index == _tables.size())
            //                {
            //                    index = 0;
            //                }
            //            }
            //            newtable[index] = _tables[i];
            //        }
            //    }
            //    _tables.swap(newtable);
            //}


            if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)
            {
                //开新表 遍历旧表 重新计算新表位置  释放旧表
                HashTable<K, T, KeyOfT> newht;
                size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
                newht._tables.resize(newsize);
                for (size_t i = 0; i < _tables.size(); ++i)
                {
                    if (_tables[i]._state == EXIST)
                    {
                        newht.insert(_tables[i]._data);
                    }
                }
                _tables.swap(newht._tables);
            }

            size_t index = d % _tables.size();
            while (_tables[index]._state == EXIST)
            {
                if (koft(_tables[index]._data) == koft(d))
                    return false;
                ++index;
                if (index == _tables.size())
                    index = 0;
            }
            _tables[index]._data = d;
            _tables[index]._state = EXIST;
            ++_num;
        }

        HashData* Find(const K& key)
        {
            size_t index = key % _tables.size();
            while (_tables[index]._state != EMPTY)
            {
                if (_tables[index]._data == key)
                {
                    if (_tables[index]._state == EXIST)
                        return &_tables[index];
                    if (_tables[index]._state == DELETE)
                        return nullptr;
                }
                ++index;
                if (index == _tables.size())
                {
                    index = 0;
                }
            }
            return nullptr;
        }


        bool erase(const K& key)
        {
            HashData* ret = Find(key);
            if (ret)
            {
                ret._state = DELETE;
                --_num;
                return true;
            }
            else
                return false;

        }

    private:
        vector<HashData> _tables;
        size_t _num;
    };

    //template<class K>
    //struct MapKeyOfT
    //{
    //    const K& operator()(const pair<K, V>& key)
    //    {
    //        return key;
    //    }
    //};


    void testHash()
    {

        HashTable<int, int, SetKeyOfT<int>> ht;
        ht.insert(4);
        ht.insert(2);
        ht.insert(44);
        ht.insert(15);
        ht.insert(49);

    }
}

namespace OPEN_HASH
{
    template<class T> 
    struct HashNode
    {
        T _data;
        HashNode<T>* _next;

        HashNode(const T& data)
            :_data(data)
            ,_next(nullptr)
        {}
    };
    template<class K>
    struct _Hash
    {
        const K& operator()(const K& key)
        {
            return key;
        }
    };

    //特化，针对某种类型处理
    template<>
    struct _Hash<string>
    {
        size_t operator()(const string& key)
        {
            size_t hash = 0;
            for (size_t i = 0; i < key.size(); ++i)
            {
                //BKDR算法：可以尽量减少哈希冲突
                hash *= hash;
                hash += key[i];
            }
            return hash;
        }
    };
    //struct _Hashstring
    //{
    //    size_t operator()(const string& key)
    //    {
    //        size_t hash = 0;
    //        for (size_t i = 0; i < key.size(); ++i)
    //        {
    //            //BKDR算法：可以尽量减少哈希冲突
    //            hash *= hash;
    //            hash += key[i];
    //        }
    //        return hash;
    //    }
    //};

    template<class K,class T,class KOfT,class _Hash=_Hash<K>>
    class HashTable
    {
        typedef HashNode<T> Node;
    public:

        ~HashTable()
        {
            clear();
        }

        void clear()
        {
            for (size_t i = 0; i < _table.size(); ++i)
            {
                Node* cur = _table[i];
                while (cur)
                {
                    Node* next = cur->_next;
                    delete cur;
                    cur = next;
                }
                _table[i] = nullptr;
            }
        
        }

        size_t HashFunc(const K& key)
        {
            _Hash hash;
            return hash(key);
        }

        bool insert(const T& data)
        {
            KOfT koft;
            //负载因子，增容
            if (_num ==_table.size() )
            {
                vector<Node*> newtable;
                size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
                newtable.resize(newsize);
                for (size_t i = 0; i < _table.size(); ++i)
                {
                    Node* cur = _table[i];
                    while (cur)
                    {
                        Node* next = cur->_next;
                        size_t index2 = HashFunc(koft(cur->_data)) % newtable.size();
                        cur->_next = newtable[index2];
                        newtable[index2] = cur;
                        cur = next;
                        
                    }
                    _table[i] = nullptr;
                }
                _table.swap(newtable);
            }

            size_t index = HashFunc(koft(data)) % _table.size();

            Node* cur = _table[index];
            while (cur)
            {
                if (koft(cur->_data) == koft(data))
                {
                    return false;
                }
                else
                {
                    cur = cur->_next;
                }
            }
            Node* newnode = new Node(data);
            newnode->_next = _table[index];
            _table[index] = newnode;

            ++_num;
            return true;
        }

        Node* Find(const K& key)
        {
            KOfT koft;
            size_t index = HashFunc(key) % _table.size();
            Node* cur = _table[index];
            while (cur)
            {
                if (koft(cur->_data) == key)
                    return cur;
                else
                {
                    cur = cur->_next;
                }
            }
            return nullptr;
        }

        bool Erase(const K& key) 
        {
            KOfT koft;
            size_t index = HashFunc(key) % _table.size();
            Node* pre = nullptr;
            Node* cur = _table[index];
            while (cur)
            {
                if (koft(cur->_data) == key)
                {
                    if (pre == nullptr)
                    {
                        _table[index] = cur->_next;
                    }
                    else
                        pre->_next = cur->_next;

                    delete cur;

                    return true;
                }
                else
                {
                    pre = cur;
                    cur = cur->_next;
                }
            }
            return false;
        }

    private:
        vector<Node*> _table;
        size_t _num = 0;

    };

    //void testHash()
    //{ 

    //    HashTable<int, int, SetKeyOfT<int>> ht;
    //    ht.insert(4);
    //    ht.insert(2);
    //    ht.insert(44);
    //    ht.insert(15);
    //    ht.insert(49);
    //    ht.insert(19);
    //    ht.insert(29);
    //    ht.insert(21);
    //    ht.insert(22);
    //    ht.insert(39);
    //    ht.insert(8);
    //    ht.insert(18);


    //    cout << ht.Find(18)<< endl;
    //    cout << ht.Erase(18)<< endl;
    //    cout << ht.Erase(666)<< endl;
    //}


    void testHash2()
    {
        HashTable<string, string, SetKeyOfT<string>> ht;
        ht.insert("ahah");
    }
}