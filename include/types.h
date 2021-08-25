#ifndef _TYPES_H
#define _TYPES_H

class IValue {
public:
    IValue() {}
    virtual ~IValue() {}


};

class IntValue : public IValue
{
private:
    int val;
public:
    IntValue(/* args */);
    IntValue& operator=(const IntValue& other) {}
};

IntValue::IntValue(/* args */)
{
}


class StringValue : public IValue
{
private:
    /* data */
public:
    StringValue(/* args */);
    ~StringValue();
};

StringValue::StringValue(/* args */)
{
}

StringValue::~StringValue()
{
}



class NullValue
{
};

extern NullValue NULLVAL;

#endif
