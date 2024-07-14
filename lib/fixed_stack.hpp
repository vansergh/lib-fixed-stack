#ifndef SSL_HPP
#define SSL_HPP

////////////////////////////////////
// FixedStack declaration
//////////////////////////////////  

template <class DataType>
class FixedStack {
public:
    FixedStack() = delete;
    FixedStack(const FixedStack<DataType>&) = delete;
    FixedStack(size_t capacity);
    ~FixedStack();

    void Push(const DataType& data);
    void Pop();
    DataType Top();
    
    size_t Size();
    bool IsEmpty();
private:
    DataType* data_;
    size_t capacity_;
    size_t size_;
};

////////////////////////////////////
// FixedStack defenition
//////////////////////////////////  

template<class DataType>
inline FixedStack<DataType>::FixedStack(size_t capacity) :
    data_{ new DataType[capacity] },
    capacity_{ capacity },
    size_{0}
{
    // Default constructor
}

template<class DataType>
inline FixedStack<DataType>::~FixedStack() {
    delete[] data_;
}

template<class DataType>
inline void FixedStack<DataType>::Push(const DataType& data) {
    if (size_ < capacity_) {
        data_[size_] = DataType(data);
        ++size_;            
    }
}

template<class DataType>
inline void FixedStack<DataType>::Pop() {
    if (!IsEmpty()) {
        --size_;
        data_[size_].~DataType();
    }
}

template<class DataType>
inline DataType FixedStack<DataType>::Top() {
    return data_[size_-1];
}

template<class DataType>
inline size_t FixedStack<DataType>::Size() {
    return size_;
}

template<class DataType>
inline bool FixedStack<DataType>::IsEmpty() {
    return size_ == 0;
}

#endif // SSL_HPP