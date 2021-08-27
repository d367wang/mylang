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
    IntValue(int val) : val(val) {}
};

class StringValue : public IValue
{
private:
    std::string val;
public:
    StringValue(const char* str) : val(str) {}
};


class NullValue
{
};

extern NullValue NULLVAL;

#endif
