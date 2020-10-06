#ifndef INTERFACE_CXX
#define INTERFACE_CXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif

namespace Interface
{
#line 314 "../../src/Com/Interface.fog"
    Text::String Format(Text::String pattern, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
#line 315
        static const int MAX_ARGS = 8;
        Value * v[MAX_ARGS] = 
        {
            &v0,
            &v1,
            &v2,
            &v3,
            &v4,
            &v5,
            &v6,
            &v7
        };
#line 318
        if (pattern.IsEmpty())
#line 318
            return "";
#line 320
        int arg = 0;
        Text::String out;
        const char * it = pattern.Begin();
        const char * end = pattern.End();
        while (it != end)
            {
#line 325
                int chr = *it ++ ;
#line 328
                if (chr == 92 && *it == 37)
                {
#line 329
                    chr = *it ++ ;
                    out.Cat(chr);
                }
                else 
                if (chr == 37)
                {
#line 334
                    int state = FMT_MAIN_SWITCH;
                    int type = FMT_TYPE_INVALID;
                    while (it != end)
                        {
#line 337
                            chr = *it ++ ;
                            if (state == FMT_MAIN_SWITCH)
                            {
#line 339
                                if (chr == 'v')
                                {
#line 340
                                    type = FMT_TYPE_VALUE;
                                    break;
                                
                                }
                                else
#line 343
                                    break;
                            
                            }
                            else
#line 345
                                break;
                        
                        }
#line 347
                    if (type == FMT_TYPE_INVALID)
                        out << "<invalid>";
                    else 
#line 349
                    if (type == FMT_TYPE_VALUE)
                    {
#line 350
                        if (arg < MAX_ARGS)
                            out << v[arg ++ ] -> AsString();
                        else
                            out << "<arg overflow " << arg ++ << ">";
                    }
                }
                else
                {
#line 357
                    out.Cat(chr);
                }
            }
        return out;
    };
    
#line 248
    Text::String GetValueTreeString(const Value& v, Text::String key, int indent)
    {
#line 249
        static thread_local Container::Index < void * > visited;
        if (!indent)
            visited.Clear();
#line 253
        Text::String s;
        for (int i = 0; i < indent; i ++ )
            s.Cat('\t');
        s << key;
#line 258
        void * obj = v.GetObject();
        if (obj)
        {
#line 260
            if (visited.Find(obj) >= 0)
                return s + ": <recursive>\n";
            visited.Add(obj);
        }
#line 265
        if (v.IsMap())
        {
#line 266
            s.Cat('\n');
            const ValueMap & map = v.Get < ValueMap > ();
            for (int i = 0; i < map.GetCount(); i ++ )
                {
#line 269
                    Text::String key = map.GetKey(i);
                    const Value & v0 = map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 274
        if (v.IsArray())
        {
#line 275
            s.Cat('\n');
            const ValueArray & arr = v.Get < ValueArray > ();
            for (int i = 0; i < arr.GetCount(); i ++ )
                {
#line 278
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 283
        if (v.IsArrayMapComb())
        {
#line 284
            s.Cat('\n');
            const ValueArrayMapComb & comb = v.Get < ValueArrayMapComb > ();
            for (int i = 0; i < comb.map.GetCount(); i ++ )
                {
#line 287
                    Text::String key = comb.map.GetKey(i);
                    const Value & v0 = comb.map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
            for (int i = 0; i < comb.arr.GetCount(); i ++ )
                {
#line 292
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = comb.arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else
        {
#line 298
            s << ": " << v.AsString() << "\n";
        }
#line 301
        if (obj)
            visited.RemoveLast();
#line 304
        return s;
    };
    
#line 93
    Value::Value(const char *str)
    {
#line 93
        Text::String & s = Create < Text::String > ();
#line 93
        s = str;
    };
    
#line 120
    template < class _1 >
    Value::operator _1 & () const
    {
#line 121
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return *(_1 * ) obj -> Get();
        throw Text::Exc("Unexpected value type");
    };
    
#line 97
    template < class _1 >
    _1& Value::Create()
    {
#line 97
        ValueTemplate < _1 > * o = new ValueTemplate < _1 > ;
#line 97
        _1 * t = (_1 * ) o -> Get();
#line 97
        obj.WrapObject(o);
#line 97
        return *t;
    };
    
#line 98
    template < class _1 >
    _1& Value::Create1(const _1& arg)
    {
#line 98
        ValueTemplate < _1 > * o = new ValueTemplate < _1 > (arg);
#line 98
        _1 * t = (_1 * ) o -> Get();
#line 98
        obj.WrapObject(o);
#line 98
        return *t;
    };
    
#line 125
    template < class _1 >
    _1& Value::Get() const
    {
#line 126
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return *(_1 * ) obj -> Get();
        throw Text::Exc("Unexpected value type");
    };
    
#line 112
    template < class _1 >
    bool Value::Is() const
    {
#line 112
        if (obj)
#line 112
            return obj -> GetType() == ValueTypeNo < _1 > (0);
#line 112
        return false;
    };
    
#line 148
    bool Value::IsInt() const
    {
#line 148
        return !obj.IsEmpty() && obj -> GetType() == INT_V;
    };
    
#line 149
    bool Value::IsInt64() const
    {
#line 149
        return !obj.IsEmpty() && obj -> GetType() == INT64_V;
    };
    
#line 147
    bool Value::IsString() const
    {
#line 147
        return !obj.IsEmpty() && obj -> GetType() == STRING_V;
    };
    
#line 143
    bool Value::IsVoid() const
    {
#line 143
        if (obj)
#line 143
            return obj -> GetType() == VOID_V;
#line 143
        return true;
    };
    
#line 113
    template < class _1 >
    _1 *Value::Try() const
    {
#line 114
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return(_1 * ) obj -> Get();
        return 0;
    };
    
#line 179
    Text::String ValueArray::AsString() const
    {
#line 179
        Text::String s;
#line 179
        s << "ValueArray(" << values.GetCount() << ")";
#line 179
        return s;
    };
    
#line 232
    void ValueArrayMapComb::operator= (const ValueArrayMapComb& v)
    {
#line 232
        arr = v.arr;
#line 232
        map = v.map;
    };
    
#line 237
    Text::String ValueArrayMapComb::AsString() const
    {
#line 237
        Text::String s;
#line 237
        s << "ValueArrayMapComb(" << arr.GetCount() << ", " << map.GetCount() << ")";
#line 237
        return s;
    };
    
#line 235
    void ValueArrayMapComb::Clear()
    {
#line 235
        arr.Clear();
#line 235
        map.Clear();
    };
    
#line 236
    int ValueArrayMapComb::GetTotal() const
    {
#line 236
        return arr.GetCount() + map.GetCount();
    };
    
#line 199
    void ValueMap::operator= (const ValueMap& m)
    {
#line 199
        keys <<= m.keys;
#line 199
        values <<= m.values;
    };
    
    Value& ValueMap::Add(Text::String key)
    {
#line 202
        keys.Add(key);
#line 202
        return values.Add();
    };
    
#line 201
    Value& ValueMap::Add(Text::String key, Value v)
    {
#line 201
        keys.Add(key);
#line 201
        return values.Add(v);
    };
    
#line 220
    Text::String ValueMap::AsString() const
    {
#line 220
        Text::String s;
#line 220
        s << "ValueMap(" << keys.GetCount() << ")";
#line 220
        return s;
    };
    
#line 211
    void ValueMap::Clear()
    {
#line 211
        keys.Clear();
#line 211
        values.Clear();
    };
    
#line 207
    int ValueMap::Find(Text::String key) const
    {
#line 207
        for (int i = 0; i < keys.GetCount(); i ++ )
#line 207
            if (keys[i] == key)
#line 207
                return i;
#line 207
        return - 1;
    };
    
#line 208
    Value& ValueMap::Get(Text::String key)
    {
#line 208
        int i = Find(key);
#line 208
        if (i == - 1)
#line 208
            throw Text::Exc("Unexpected key");
#line 208
        return values[i];
    };
    
#line 203
    Value& ValueMap::GetAdd(Text::String key)
    {
#line 203
        int i = Find(key);
#line 203
        if (i >= 0)
#line 203
            return values[i];
#line 203
        return Add(key);
    };
    
#line 204
    Value& ValueMap::GetAdd(Text::String key, const Value& def)
    {
#line 204
        int i = Find(key);
#line 204
        if (i >= 0)
#line 204
            return values[i];
#line 204
        return Add(key, def);
    };
    
#line 209
    int ValueMap::GetPos(Value *v) const
    {
#line 209
        for (int i = 0; i < values.GetCount(); i ++ )
#line 209
            if (&values[i] == v)
#line 209
                return i;
#line 209
        return - 1;
    };
    
#line 206
    Value *ValueMap::TryFind(Text::String key)
    {
#line 206
        int i = Find(key);
#line 206
        if (i >= 0)
#line 206
            return&At(i);
#line 206
        return 0;
    };
    
#line 205
    Value ValueMap::TryGet(Text::String key, Value def)
    {
#line 205
        int i = Find(key);
#line 205
        if (i >= 0)
#line 205
            return At(i);
        else
#line 205
            return def;
    };
    
#line 61
    ValueObject::~ValueObject() {};
    
#line 64
    Lang::int64 ValueObject::AsInt() const
    {
#line 64
        return 0;
    };
    
#line 63
    Text::String ValueObject::AsString() const
    {
#line 63
        return "VOID";
    };
    
#line 62
    void *ValueObject::Get()
    {
#line 62
        return 0;
    };
    
#line 74
    template < class _1 >
    ValueTemplate < _1 >::ValueTemplate()
    :
        is_owned(false),
        ptr(0)
    {
#line 74
        ptr = new _1;
#line 74
        is_owned = true;
#line 74
        type = ValueTypeNo < _1 > (0);
    };
    
#line 75
    template < class _1 >
    ValueTemplate < _1 >::ValueTemplate(_1 *ptr)
    :
        is_owned(false),
        ptr(ptr)
    {
#line 75
        type = ValueTypeNo < _1 > (0);
    };
    
#line 76
    template < class _1 >
    ValueTemplate < _1 >::ValueTemplate(const _1& obj)
    :
        is_owned(false),
        ptr(0)
    {
#line 76
        ptr = new _1(obj);
#line 76
        is_owned = true;
#line 76
        type = ValueTypeNo < _1 > (0);
    };
    
#line 77
    template < class _1 >
    ValueTemplate < _1 >::~ValueTemplate()
    {
#line 77
        if (is_owned && ptr)
        {
#line 77
            delete ptr;
#line 77
            ptr = 0;
#line 77
            is_owned = false;
#line 77
            type = VOID_V;
        }
    };
    
#line 80
    template < class _1 >
    Lang::int64 ValueTemplate < _1 >::AsInt() const
    {
#line 80
        if (ptr)
#line 80
            return Text::ToInt(*ptr);
#line 80
        return 0;
    };
    
#line 79
    template < class _1 >
    Text::String ValueTemplate < _1 >::AsString() const
    {
#line 79
        if (ptr)
#line 79
            return Text::ToString(*ptr);
#line 79
        return "NULL";
    };
    
#line 78
    template < class _1 >
    void *ValueTemplate < _1 >::Get()
    {
#line 78
        return ptr;
    };
    
};

#endif
