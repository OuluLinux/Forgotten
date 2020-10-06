#ifndef INTERFACE_HXX
#define INTERFACE_HXX

#include <new>

#ifndef SHARED_HXX
#include <Shared.hxx>
#endif
#ifndef NETWORK_HXX
#include <Network.hxx>
#endif

namespace Interface
{
    enum _anon_17
    {
        VOID_V = 0,
        INT_V = 1,
        DOUBLE_V = 2,
        STRING_V = 3,
        DATE_V = 4,
        TIME_V = 5,
        ERROR_V = 6,
        VALUE_V = 7,
        WSTRING_V = 8,
        VALUEARRAY_V = 9,
        INT64_V = 10,
        BOOL_V = 11,
        VALUEMAP_V = 12,
        VALUE_ARRAY_AND_MAP_V = 13,
        UNKNOWN_V = 0Xffffffff
    };
    enum _anon_18
    {
        FMT_MAIN_SWITCH = 0,
        FMT_TYPE_INVALID = 0,
        FMT_TYPE_VALUE
    };
};

namespace Interface {
class Value;
}

namespace Interface
{
#line 314 "../../src/Com/Interface.fog"
    Text::String Format(Text::String pattern, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7);
#line 248
    Text::String GetValueTreeString(const Value& v, Text::String key, int indent);
#line 9
    inline int RegisterTypeNo(const char *type);
#line 16
    template < class _1 >
    inline int StaticTypeNo(_1 *p);
#line 52
    inline Lang::dword ValueTypeNo(const Chrono::Date *);
    inline Lang::dword ValueTypeNo(const Chrono::Time *);
    inline Lang::dword ValueTypeNo(const Value *);
#line 47
    inline Lang::dword ValueTypeNo(const Lang::int64 *);
#line 50
    inline Lang::dword ValueTypeNo(const Text::String *);
    inline Lang::dword ValueTypeNo(const Text::WString *);
#line 42
    template < class _1 >
    inline Lang::dword ValueTypeNo(const _1 *);
#line 49
    inline Lang::dword ValueTypeNo(const bool *);
#line 48
    inline Lang::dword ValueTypeNo(const double *);
#line 46
    inline Lang::dword ValueTypeNo(const int *);
#line 45
    inline Lang::dword ValueTypeNo(const void *);
};

namespace Interface {
class ValueArray;
}

namespace Interface
{
#line 242
    template <>
    inline Lang::dword ValueTypeNo < ValueArray > (const ValueArray *);
};

namespace Interface {
struct ValueArrayMapComb;
}

namespace Interface
{
#line 244
    template <>
    inline Lang::dword ValueTypeNo < ValueArrayMapComb > (const ValueArrayMapComb *);
};

namespace Interface {
class ValueMap;
}

namespace Interface
{
#line 243
    template <>
    inline Lang::dword ValueTypeNo < ValueMap > (const ValueMap *);
};

namespace Interface {
class ValueObject;
}

namespace Interface
{
    class Value
    {
#line 87
        Shared::Ptr < ValueObject > obj;
        
    public:
#line 91
        inline Value();
        inline Value(const Value& v);
        Value(const char *str);
#line 106
        template < class _1 >
        inline Value& operator= (const Value& v);
#line 103
        inline bool operator== (const Value& v) const;
#line 120
        template < class _1 >
        operator _1 & () const;
#line 139
        Value *AddMapSub(Text::String key, Value *def = 0);
#line 152
        inline Lang::int64 AsInt() const;
#line 151
        inline Text::String AsString() const;
#line 110
        template < class _1 >
        inline void Attach(_1 *o);
#line 96
        inline void Clear();
        template < class _1 >
        _1& Create();
#line 98
        template < class _1 >
        _1& Create1(const _1& arg);
#line 101
        ValueArray& CreateArray();
#line 100
        ValueMap& CreateMap();
#line 99
        void DeepCopyArrayMap(Value v);
#line 125
        template < class _1 >
        _1& Get() const;
#line 140
        Value *GetAddMapSub(Text::String key, Value *def = 0);
#line 137
        ValueArray& GetArray();
#line 135
        const ValueArray& GetArray() const;
        ValueMap& GetMap();
#line 134
        const ValueMap& GetMap() const;
#line 138
        Value *GetMapSub(Text::String key, Value *def = 0);
#line 141
        inline ValueObject *GetObject() const;
#line 105
        inline Lang::dword GetType() const;
#line 112
        template < class _1 >
        bool Is() const;
#line 144
        bool IsArray() const;
#line 146
        bool IsArrayMapComb() const;
#line 148
        bool IsInt() const;
        bool IsInt64() const;
#line 145
        bool IsMap() const;
#line 147
        bool IsString() const;
#line 143
        bool IsVoid() const;
#line 111
        template < class _1 >
        inline void Set(const _1& o);
        template < class _1 >
        _1 *Try() const;
#line 133
        ValueArray *TryGetArray();
#line 131
        const ValueArray *TryGetArray() const;
        ValueMap *TryGetMap();
#line 130
        const ValueMap *TryGetMap() const;
    };
    
    class ValueArray
    {
#line 156
        typedef Container::Array < Value > A;
        
#line 157
        A values;
        
    public:
#line 161
        inline ValueArray();
        inline ValueArray(const ValueArray& m);
        inline void operator= (const ValueArray& m);
#line 171
        inline Value& operator[](int i);
#line 173
        inline const Value& operator[](int i) const;
#line 166
        inline Value& Add();
        inline Value& Add(const Value& v);
#line 180
        inline Lang::int64 AsInt() const;
#line 179
        Text::String AsString() const;
#line 172
        inline Value& At(int i);
#line 174
        inline const Value& At(int i) const;
#line 165
        inline void Clear();
#line 177
        void DeepCopyArrayMap(ValueArray& arr);
#line 170
        inline int GetCount() const;
#line 168
        inline Value& Insert(int i);
        inline Value& Insert(int i, const Value& v);
#line 175
        inline bool IsEmpty() const;
        inline void SetCount(int i);
#line 184
        inline Lang::ConstFwdPtrIterator < Value > begin() const;
#line 182
        inline Lang::FwdPtrIterator < Value > begin();
#line 185
        inline Lang::ConstFwdPtrIterator < Value > end() const;
#line 183
        inline Lang::FwdPtrIterator < Value > end();
    };
    
    class ValueMap
    {
#line 192
        Container::Vector < Text::String > keys;
        Container::Array < Value > values;
        
    public:
#line 197
        inline ValueMap();
        inline ValueMap(const ValueMap& m);
        void operator= (const ValueMap& m);
#line 213
        inline Value& operator[](int i);
#line 215
        inline const Value& operator[](int i) const;
#line 202
        Value& Add(Text::String key);
#line 201
        Value& Add(Text::String key, Value v);
#line 221
        inline Lang::int64 AsInt() const;
#line 220
        Text::String AsString() const;
#line 214
        inline Value& At(int i);
#line 216
        inline const Value& At(int i) const;
#line 211
        void Clear();
#line 218
        void DeepCopyArrayMap(ValueMap& map);
#line 207
        int Find(Text::String key) const;
        Value& Get(Text::String key);
#line 203
        Value& GetAdd(Text::String key);
        Value& GetAdd(Text::String key, const Value& def);
#line 212
        inline int GetCount() const;
#line 217
        inline Text::String GetKey(int i) const;
#line 209
        int GetPos(Value *v) const;
#line 206
        Value *TryFind(Text::String key);
#line 205
        Value TryGet(Text::String key, Value def = Value());
    };
    
    struct ValueArrayMapComb
    {
#line 226
        ValueArray arr;
        ValueMap map;
        
#line 230
        inline ValueArrayMapComb();
        inline ValueArrayMapComb(const ValueArrayMapComb& v);
        void operator= (const ValueArrayMapComb& v);
#line 238
        inline Lang::int64 AsInt() const;
#line 237
        Text::String AsString() const;
#line 235
        void Clear();
#line 233
        void DeepCopyArrayMap(ValueArrayMapComb& am);
#line 236
        int GetTotal() const;
    };
    
    class ValueObject
    {
    protected:
#line 58
        Lang::dword type;
        
    public:
        virtual ~ValueObject();
#line 64
        virtual Lang::int64 AsInt() const;
#line 63
        virtual Text::String AsString() const;
#line 62
        virtual void *Get();
#line 65
        inline Lang::dword GetType() const;
    };
    
    template < class _1 >
    class ValueTemplate : public Interface::ValueObject
    {
#line 70
        bool is_owned;
        _1 *ptr;
        
    public:
        ValueTemplate();
        ValueTemplate(_1 *ptr);
        ValueTemplate(const _1& obj);
        ~ValueTemplate();
#line 80
        virtual Lang::int64 AsInt() const;
#line 79
        virtual Text::String AsString() const;
#line 78
        virtual void *Get();
    };
};

namespace Interface
{
#line 9
    inline int RegisterTypeNo(const char *type)
    {
#line 10
        static Container::Index < Text::String > idx;
        return idx.FindAdd(type);
    };
    
#line 16
    template < class _1 >
    inline int StaticTypeNo(_1 *p)
    {
#line 18
        static int typeno = RegisterTypeNo(typeid(_1).name());
        return typeno;
    };
    
#line 52
    inline Lang::dword ValueTypeNo(const Chrono::Date *)
    {
#line 52
        return DATE_V;
    };
    
#line 53
    inline Lang::dword ValueTypeNo(const Chrono::Time *)
    {
#line 53
        return TIME_V;
    };
    
#line 54
    inline Lang::dword ValueTypeNo(const Value *)
    {
#line 54
        return VALUE_V;
    };
    
#line 47
    inline Lang::dword ValueTypeNo(const Lang::int64 *)
    {
#line 47
        return INT64_V;
    };
    
    inline Lang::dword ValueTypeNo(const Text::String *)
    {
#line 50
        return STRING_V;
    };
    
#line 51
    inline Lang::dword ValueTypeNo(const Text::WString *)
    {
#line 51
        return WSTRING_V;
    };
    
#line 42
    template < class _1 >
    inline Lang::dword ValueTypeNo(const _1 *)
    {
#line 43
        return StaticTypeNo((_1 * )0) + 0x8000000;
    };
    
#line 49
    inline Lang::dword ValueTypeNo(const bool *)
    {
#line 49
        return BOOL_V;
    };
    
#line 48
    inline Lang::dword ValueTypeNo(const double *)
    {
#line 48
        return DOUBLE_V;
    };
    
#line 46
    inline Lang::dword ValueTypeNo(const int *)
    {
#line 46
        return INT_V;
    };
    
#line 45
    inline Lang::dword ValueTypeNo(const void *)
    {
#line 45
        return VOID_V;
    };
    
#line 242
    template <>
    inline Lang::dword ValueTypeNo < ValueArray > (const ValueArray *)
    {
#line 242
        return VALUEARRAY_V;
    };
    
#line 244
    template <>
    inline Lang::dword ValueTypeNo < ValueArrayMapComb > (const ValueArrayMapComb *)
    {
#line 244
        return VALUE_ARRAY_AND_MAP_V;
    };
    
#line 243
    template <>
    inline Lang::dword ValueTypeNo < ValueMap > (const ValueMap *)
    {
#line 243
        return VALUEMAP_V;
    };
    
#line 91
    inline Value::Value() {};
    
#line 92
    inline Value::Value(const Value& v)
    {
#line 92
        *this = v;
    };
    
#line 106
    template < class _1 >
    inline Value& Value::operator= (const Value& v)
    {
#line 106
        obj = v.obj;
#line 106
        return *this;
    };
    
#line 103
    inline bool Value::operator== (const Value& v) const
    {
#line 103
        return obj == v.obj;
    };
    
#line 152
    inline Lang::int64 Value::AsInt() const
    {
#line 152
        if (obj)
#line 152
            return obj -> AsInt();
#line 152
        return 0;
    };
    
#line 151
    inline Text::String Value::AsString() const
    {
#line 151
        if (obj)
#line 151
            return obj -> AsString();
#line 151
        return "NULL";
    };
    
#line 110
    template < class _1 >
    inline void Value::Attach(_1 *o)
    {
#line 110
        obj = new ValueTemplate < _1 > (o);
    };
    
#line 96
    inline void Value::Clear()
    {
#line 96
        obj.Clear();
    };
    
#line 141
    inline ValueObject *Value::GetObject() const
    {
#line 141
        return obj.Get();
    };
    
#line 105
    inline Lang::dword Value::GetType() const
    {
#line 105
        if (obj)
#line 105
            return obj -> GetType();
#line 105
        return VOID_V;
    };
    
#line 111
    template < class _1 >
    inline void Value::Set(const _1& o)
    {
#line 111
        obj.WrapObject(new ValueTemplate < _1 > (o));
    };
    
#line 161
    inline ValueArray::ValueArray() {};
    
#line 162
    inline ValueArray::ValueArray(const ValueArray& m)
    {
#line 162
        *this = m;
    };
    
#line 163
    inline void ValueArray::operator= (const ValueArray& m)
    {
#line 163
        values <<= m.values;
    };
    
#line 171
    inline Value& ValueArray::operator[](int i)
    {
#line 171
        return values[i];
    };
    
#line 173
    inline const Value& ValueArray::operator[](int i) const
    {
#line 173
        return values[i];
    };
    
#line 166
    inline Value& ValueArray::Add()
    {
#line 166
        return values.Add();
    };
    
#line 167
    inline Value& ValueArray::Add(const Value& v)
    {
#line 167
        return values.Add(v);
    };
    
#line 180
    inline Lang::int64 ValueArray::AsInt() const
    {
#line 180
        return values.GetCount();
    };
    
#line 172
    inline Value& ValueArray::At(int i)
    {
#line 172
        return values[i];
    };
    
#line 174
    inline const Value& ValueArray::At(int i) const
    {
#line 174
        return values[i];
    };
    
#line 165
    inline void ValueArray::Clear()
    {
#line 165
        values.Clear();
    };
    
#line 170
    inline int ValueArray::GetCount() const
    {
#line 170
        return values.GetCount();
    };
    
#line 168
    inline Value& ValueArray::Insert(int i)
    {
#line 168
        return values.Insert(i);
    };
    
#line 169
    inline Value& ValueArray::Insert(int i, const Value& v)
    {
#line 169
        return values.Insert(i, v);
    };
    
#line 175
    inline bool ValueArray::IsEmpty() const
    {
#line 175
        return values.IsEmpty();
    };
    
#line 176
    inline void ValueArray::SetCount(int i)
    {
#line 176
        values.SetCount(i);
    };
    
#line 184
    inline Lang::ConstFwdPtrIterator < Value > ValueArray::begin() const
    {
#line 184
        return values.begin();
    };
    
#line 182
    inline Lang::FwdPtrIterator < Value > ValueArray::begin()
    {
#line 182
        return values.begin();
    };
    
    inline Lang::ConstFwdPtrIterator < Value > ValueArray::end() const
    {
#line 185
        return values.end();
    };
    
#line 183
    inline Lang::FwdPtrIterator < Value > ValueArray::end()
    {
#line 183
        return values.end();
    };
    
#line 230
    inline ValueArrayMapComb::ValueArrayMapComb() {};
    
#line 231
    inline ValueArrayMapComb::ValueArrayMapComb(const ValueArrayMapComb& v)
    {
#line 231
        *this = v;
    };
    
#line 238
    inline Lang::int64 ValueArrayMapComb::AsInt() const
    {
#line 238
        return GetTotal();
    };
    
#line 197
    inline ValueMap::ValueMap() {};
    
#line 198
    inline ValueMap::ValueMap(const ValueMap& m)
    {
#line 198
        *this = m;
    };
    
#line 213
    inline Value& ValueMap::operator[](int i)
    {
#line 213
        return values[i];
    };
    
#line 215
    inline const Value& ValueMap::operator[](int i) const
    {
#line 215
        return values[i];
    };
    
#line 221
    inline Lang::int64 ValueMap::AsInt() const
    {
#line 221
        return keys.GetCount();
    };
    
#line 214
    inline Value& ValueMap::At(int i)
    {
#line 214
        return values[i];
    };
    
#line 216
    inline const Value& ValueMap::At(int i) const
    {
#line 216
        return values[i];
    };
    
#line 212
    inline int ValueMap::GetCount() const
    {
#line 212
        return values.GetCount();
    };
    
#line 217
    inline Text::String ValueMap::GetKey(int i) const
    {
#line 217
        return keys[i];
    };
    
#line 65
    inline Lang::dword ValueObject::GetType() const
    {
#line 65
        return type;
    };
    
};

#endif
